@rem = '--*-Perl-*--
@echo off
if "%OS%" == "Windows_NT" goto WinNT
perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
goto endofperl
:WinNT
perl -x -S "%0" %*
if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" goto endofperl
if %errorlevel% == 9009 echo You do not have Perl in your PATH.
goto endofperl
@rem ';
#!perl -w
#line 14

# $Id: lwp-request.PL,v 1.35 1999/03/19 22:06:32 gisle Exp $
#
# Simple user agent using LWP library.

=head1 NAME

lwp-request, GET, HEAD, POST - Simple WWW user agent

=head1 SYNOPSIS

 lwp-request [-aeEdvhx] [-m method] [-b <base URL>] [-t <timeout>]
             [-i <if-modified-since>] [-c <content-type>] [-C <credentials>]
             [-p <proxy-url>] [-o <format>] <url>...

=head1 DESCRIPTION

This program can be used to send requests to WWW servers and your
local file system. The request content for POST, PUT and CHECKIN
methods is read from stdin.  The content of the response is printed on
stdout.  Error messages are printed on stderr.  The program returns a
status value indicating the number of URLs that failed.

The options are:

=over 4

=item -m <method>

Set which method to use for the request.  If this option is not used,
then the method is derived from the name of the program.

=item -f

Force request through, even if the program believes that the method is
illegal.  The server will probably reject the request.

=item -b <url>

This URL will be used as the base URL for the URLs that the method is
applied to.  The base URL only takes effect for relative URLs.  If you
do not provide this option and the URLs are relative, then they will
be treated as files in the local file system.

=item -t <timeout>

Set the timeout value for the requests.  The timeout is the amount of
time that the program will wait for a response from the remote server
before it fails.  The default unit for the timeout value is seconds.
You might append "m" or "h" to the timeout value to make it minutes or
hours, respectively.  The default timeout is '3m', i.e. 3 minutes.

=item -i <time>

Set the If-Modified-Since header in the request. If I<time> it the
name of a file, use the modification timestamp for this file. If
I<time> is not a file, it is parsed as a literal date. Take a look at
L<HTTP::Date> for recogniced formats.

=item -c <content-type>

Set the Content-Type for the request.  This option is only allowed for
requests that take a content, i.e. POST, PUT and CHECKIN.  You can
force methods to take content by using the C<-f> option together with
C<-c>.  The default Content-Type for POST is
C<application/x-www-form-urlencoded>.  The default Content-type for
the others is C<text/plain>.

=item -p <proxy-url>

Set the proxy to be used for the requests.  The program also loads
proxy settings from the environment.  You can disable this with the
C<-P> option.

=item -C <username>:<password>

Provide credentials for documents that are protected by Basic
Authentication.  If the document is protected and you did not specify
the username and password with this option, then you will be prompted
to provide these values.

=back

The following options controls what is displayed by the program:

=over 4

=item -u

Print request method and absolute URL as requests are made.

=item -U

Print request headers in addition to request method and absolute URL.

=item -s

Print response status code.  This option is always on for HEAD requests.

=item -S

Print response status chain. This shows redirect and autorization
requests that are handled by the library.

=item -e

Print response headers.  This option is always on for HEAD requests.

=item -d

Do B<not> print the content of the response.

=item -o <format>

Process HTML content in various ways before printing it.  If the
content type of the response is not HTML, then this option has no
effect.  The legal format values are; I<text>, I<ps>, I<links>,
I<html> and I<dump>.

If you specify the I<text> format then the HTML will be formatted as
plain latin1 text.  If you specify the I<ps> format then it will be
formatted as Postscript.

The I<links> format will output all links found in the HTML document.
Relative links will be expanded to absolute ones.

The I<html> format will reformat the HTML code and the I<dump> format
will just dump the HTML syntax tree.

=item -v

Print the version number of the program and quit.

=item -h

Print usage message and quit.

=item -x

Extra debugging output.

=item -a

Set text(ascii) mode for content input and output.  If this option is not 
used, content input and output is done in binary mode.

=back

Because this program is implemented using the LWP library, it will
only support the protocols that LWP supports.

=head1 SEE ALSO

L<lwp-mirror>, L<LWP>

=head1 COPYRIGHT

Copyright 1995-1997 Gisle Aas.

This library is free software; you can redistribute it and/or
modify it under the same terms as Perl itself.

=head1 AUTHOR

Gisle Aas <aas@sn.no>

=cut

$progname = $0;
$progname =~ s,.*/,,;  # use basename only
$progname =~ s/\.\w*$//; # strip extension, if any

$VERSION = sprintf("%d.%02d", q$Revision: 1.35 $ =~ /(\d+)\.(\d+)/);


require LWP;
require LWP::Debug;

use URI;
use URI::Heuristic qw(uf_uri);

use HTTP::Status qw(status_message);
use HTTP::Date qw(time2str str2time);


# This table lists the methods that are allowed.  It should really be
# a superset for all methods supported for every scheme that may be
# supported by the library.  Currently it might be a bit too HTTP
# specific.  You might use the -f option to force a method through.
#
# "" = No content in request, "C" = Needs content in request
#
%allowed_methods = (
    GET        => "",
    HEAD       => "",
    POST       => "C",
    PUT        => "C",
    DELETE     => "",
    TRACE      => "",
    OPTIONS    => "",
);


# We make our own specialization of LWP::UserAgent that asks for
# user/password if document is protected.
{
    package RequestAgent;
    @ISA = qw(LWP::UserAgent);

    sub new
    { 
	my $self = LWP::UserAgent::new(@_);
	$self->agent("lwp-request/$main::VERSION");
	$self;
    }

    sub get_basic_credentials
    {
	my($self, $realm, $uri) = @_;
	if ($main::opt_C) {
	    return split(':', $main::opt_C, 2);
	} elsif (-t) {
	    my $netloc = $uri->host_port;
	    print "Enter username for $realm at $netloc: ";
	    my $user = <STDIN>;
	    chomp($user);
	    return (undef, undef) unless length $user;
	    print "Password: ";
	    system("stty -echo");
	    my $password = <STDIN>;
	    system("stty echo");
	    print "\n";  # because we disabled echo
	    chomp($password);
	    return ($user, $password);
	} else {
	    return (undef, undef)
	}
    }
}

$method = uc(lc($progname) eq "lwp-request" ? "GET" : $progname);

# Parse command line
use Getopt::Std;

$opt_a = undef;  # content i/o in text(ascii) mode
$opt_m = undef;  # set method
$opt_f = undef;  # make request even if method is not in %allowed_methods
$opt_b = undef;  # base url
$opt_t = undef;  # timeout
$opt_i = undef;  # if-modified-since
$opt_c = undef;  # content type for POST
$opt_C = undef;  # credidentials for basic authorization

$opt_u = undef;  # display method, URL and headers of request
$opt_U = undef;  # display request headers also
$opt_s = undef;  # display status code
$opt_S = undef;  # display whole chain of status codes
$opt_e = undef;  # display response headers (default for HEAD)
$opt_d = undef;  # don't display content

$opt_h = undef;  # print usage
$opt_v = undef;  # print version

$opt_x = undef;  # extra debugging info
$opt_p = undef;  # proxy URL
$opt_P = undef;  # don't load proxy setting from environment

$opt_o = undef;  # output format

unless (getopts("axhvuUsSedPp:b:t:i:c:C:m:fo:")) {
    usage();
}

if ($opt_v) {
    require LWP;
    my $DISTNAME = 'libwww-perl-' . LWP::Version();
    die <<"EOT";
This is lwp-request version $VERSION ($DISTNAME)

Copyright 1995-1997, Gisle Aas.

This program is free software; you can redistribute it and/or
modify it under the same terms as Perl itself.
EOT
}

usage() if $opt_h || !@ARGV;

LWP::Debug::level('+') if $opt_x;

# Create the user agent object
$ua = new RequestAgent;

# Load proxy settings from *_proxy environment variables.
$ua->env_proxy unless $opt_P;

$method = uc($opt_m) if defined $opt_m;

if ($opt_f) {
    if ($opt_c) {
        $allowed_methods{$method} = "C";  # force content
    } else {
        $allowed_methods{$method} = "";
    }
} elsif (!defined $allowed_methods{$method}) {
    die "$progname: $method is not an allowed method\n";
}

if ($method eq "HEAD") {
    $opt_s = 1;
    $opt_e = 1 unless $opt_d;
    $opt_d = 1;
}

if (defined $opt_t) {
    $opt_t =~ /^(\d+)([smh])?/;
    die "$progname: Illegal timeout value!\n" unless defined $1;
    $timeout = $1;
    $timeout *= 60   if ($2 eq "m");
    $timeout *= 3600 if ($2 eq "h");
    $ua->timeout($timeout);
}

if (defined $opt_i) {
    if (-e $opt_i) {
        $time = (stat _)[9];
    } else {
        $time = str2time($opt_i);
        die "$progname: Illegal time syntax for -i option\n"
            unless defined $time;
    }
    $opt_i = time2str($time);
}

$content = undef;
if ($allowed_methods{$method} eq "C") {
    # This request needs some content
    unless (defined $opt_c) {
        # set default content type
        $opt_c = ($method eq "POST") ?
              "application/x-www-form-urlencoded"
            : "text/plain";
    } else {
        die "$progname: Illegal Content-type format\n"
            unless $opt_c =~ m,^[\w\-]+/[\w\-]+(?:\s*;.*)?$,
    }
    print "Please enter content ($opt_c) to be ${method}ed:\n"
        if -t;
    binmode STDIN unless -t or $opt_a;
    $content = join("", <STDIN>);
} else {
    die "$progname: Can't set Content-type for $method requests\n"
        if defined $opt_c;
}

# Set up a request.  We will use the same request object for all URLs.
$request = new HTTP::Request $method;
$request->header('If-Modified-Since', $opt_i) if defined $opt_i;
#$request->header('Accept', '*/*');
if ($opt_c) { # will always be set for request that wants content
    $request->header('Content-Type', $opt_c);
    $request->header('Content-Length', length $content);  # Not really needed
    $request->content($content);
}


$errors = 0;

# Ok, now we perform the requests, one URL at a time
while ($url = shift) {
    # Create the URL object, but protect us against bad URLs
    eval {
	if ($url =~ /^\w+:/ || $opt_b) {  # is there any scheme specification
	    $url = URI->new($url, $opt_b);
	    $url = $url->abs($opt_b) if $opt_b;
	} else {
	    $url = uf_uri($url);
        }
    };
    if ($@) {
	$@ =~ s/at\s+\S+\s+line\s\d+//;
	print STDERR $@;
	$errors++;
	next;
    }

    $ua->proxy($url->scheme, $opt_p) if $opt_p;

    # Send the request and get a response back from the server
    $request->url($url);
    $response = $ua->request($request);

    if ($opt_u || $opt_U) {
        my $url = $response->request->url->as_string;
        print "$method $url\n";
        print $response->request->headers_as_string, "\n" if $opt_U;
    }

    if ($opt_S) {
	printResponseChain($response);
    } elsif ($opt_s) {
        print $response->status_line, "\n";
    }

    if ($opt_e) {
        # Display headers
        print $response->headers_as_string;
        print "\n";  # separate headers and content
    }

    if ($response->is_success) {
	unless ($opt_d) {
	    if ($opt_o &&
		$response->content_type eq 'text/html') {
		require HTML::Parse;
		my $html = HTML::Parse::parse_html($response->content);
		{
		    $opt_o eq 'ps' && do {
			require HTML::FormatPS;
			my $f = new HTML::FormatPS;
			print $f->format($html);
			last;
		    };
		    $opt_o eq 'text' && do {
			require HTML::FormatText;
			my $f = new HTML::FormatText;
			print $f->format($html);
			last;
		    };
		    $opt_o eq 'html' && do {
			print $html->as_HTML;
			last;
		    };
		    $opt_o eq 'links' && do {
			my $base = $response->base;
			for ( @{ $html->extract_links } ) {
			    my($link, $elem) = @$_;
			    my $tag = uc $elem->tag;
			    $link = URI->new($link)->abs($base)->as_string;
			    print "$tag\t$link\n";
			}
			last;
		    };
		    $opt_o eq 'dump' && do {
			$html->dump;
			last;
		    };
		    # It is bad to not notice this before now :-(
		    die "Illegal -o option value ($opt_o)\n";
		}
	    } else {
                binmode STDOUT unless $opt_a;
		print $response->content;
	    }
	}
    } else {
        print STDERR $response->error_as_HTML unless $opt_d;
        $errors++;
    }
}

exit $errors;


sub printResponseChain
{
    my($response) = @_;
    return unless defined $response;
    printResponseChain($response->previous);
    my $method = $response->request->method;
    my $url = $response->request->url->as_string;
    my $code = $response->code;
    print "$method $url --> ", $response->status_line, "\n";
}


sub usage
{
    die <<"EOT";
Usage: $progname [-options] <url>...
    -m <method>   use method for the request (default is '$method')
    -f            make request even if $progname believes method is illegal
    -b <base>     Use the specified URL as base
    -t <timeout>  Set timeout value
    -i <time>     Set the If-Modified-Since header on the request
    -c <conttype> use this content-type for POST, PUT, CHECKIN
    -a            Use text mode for content I/O
    -p <proxyurl> use this as a proxy
    -P            don't load proxy settings from environment

    -u            Display method and URL before any response
    -U            Display request headers (implies -u)
    -s            Display response status code
    -S            Display response status chain
    -e            Display response headers
    -d            Do not display content
    -o <format>   Process HTML content in various ways

    -v            Show program version
    -h            Print this message

    -x            Extra debugging output
EOT
}
__END__
:endofperl
