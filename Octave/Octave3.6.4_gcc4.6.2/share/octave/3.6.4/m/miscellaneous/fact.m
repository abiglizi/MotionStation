## Copyright (C) 2007-2012 Jordi Gutiérrez Hermoso 
## Copyright (C) 2007 Stallmanfacts.com
##
## This file is part of Octave.
##
## Octave is free software; you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 3 of the License, or (at
## your option) any later version.
##
## Octave is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Octave; see the file COPYING.  If not, see
## <http://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn  {Command} {} fact
## @deftypefnx {Function File} {T =} fact()
## Display an amazing and random fact about the world's greatest hacker.
## @end deftypefn


function f = fact()
  persistent wisdom = \
      {
       "Richard Stallman takes notes in binary.";
       "Richard Stallman doesn't need sudo. I will make him a sandwich anyway.";
       "Richard Stallman is my shephurd, and I am his GNU.";
       "Richard Stallman doesn't wget, Richard Stallman wdemands!";
       "Richard Stallman can touch MC Hammer";
       "Richard Stallman doesn't read web pages. They write to him.";
       "Richard Stallman gets 9 bits to the byte.";
       "Richard Stallman doesn't really believe in open software, because it's not free enough.";
       "Richard Stallman can leave neutral or negative feedback on eBay.";
       "Richard Stallman is the only man alive who can pronounce GNU the way it is meant to be pronounced.";
       "Richard Stallman does not own a mobile phone because he can fashion a crude convex dish and shout into it at the exact resonant frequency of the ozone, causing a voice to seemingly come from the sky above his intended recipient.";
       "Richard Stallman is so handsome that when he was young he was responsible for all other geeks not being able to get girls. This is why he has to cover his face with a thick layer of hair.";
       "Some people check their computers for viruses. Viruses check their computers for Richard Stallman.";
       "Richard Stallman memorises all his documents. In binary. He just types everything in whenever he needs a document.";
       "When Richard Stallman makes a sudo command, he loses permissions.";
       "Richard Stallman's beard is made of parentheses.";
       "Richard Stallman's DNA is in binary.";
       "Richard Stallman's nervous system is completely wireless.";
       "Richard Stallman's brain accepts UNIX commands.";
       "If Richard Stallman has 1GB of RAM, and if you have 1GB of RAM, Richard Stallman has more RAM than you.";
       "Richard Stallman eats ethernet cables. That's why they invented wireless.";
       "Richard Stallman has a katana. 'Nuff said.";
       "Richard Stallman wrote a program that divides by zero.";
       "Ricahrd Stallman doesn't use zip drives, he just squeezes the hard drive.";
       "Richard Stallman's compiler is afraid to report errors.";
       "Richard Stallman wrote the compiler God used. The Big Bang was the Universe's first segfault.";
       "Richard Stallman successfully compiled a kernel of popcorn.";
       "Richard Stallman doesn't write programs, they write themselves out of reverence.";
       "Richard Stallman can make infinite loops end.";
       "Richard Stallman's anti-virus programs cures HIV.";
       "Richard Stallman's computer doesn't have a clock; it defines what time it is.";
       "Richard Stallman wrote a program to compute the last digit of pi.";
       "Richard Stallman doesn't use web browsers. He sends a link to a demon that uses wget to fetch the page and sends it back to him.";
       "Richard Stallman can solve the halting problem... in polynomial time.";
       "For Richard Stallman, polynomial time is O(1).";
       "Richard Stallman didn't \"write\" Emacs or created it in his own image. Richard Stallman made Emacs an instance of himself.";
       "Richard Stallman can coerce meaningful data from /dev/null.";
       "Some people wear Linus Torvalds pyjamas to bed, Linus Torvalds wears Richard Stallman pyjamas.";
       "There is no software development process, only a bunch of programs Richard Stallman allows to exist. ";
       "Richard Stallman spends his leisure time programming with Guile on GNU Hurd. ";
       "Richard Stallman's left and right hands are named \"(\" and \")\" ";
       "Richard Stallman first words were actually syscalls. ";
       "Richard Stallman didn't create the singularity. He is the singularity. GNU/Linux is only the event horizon. ";
       "When Richard Stallman pipes to more, he gets less ";
       "Richard Stallman never showers: he runs 'make clean'. ";
       "Richard Stallman needs neither mouse nor keyboard to operate his computer. He just stares it down until it does what he wants. ";
       "Richard Stallman didn't write the GPL. He is the GPL. ";
       "Richad Stallman's pinky finger is really a USB memory stick. ";
       "Richard Stallman called his operating system GNU because he created it before computers existed, when actual gnus were used for calcuations. ";
       "In Soviet Russia, Richard Stallman is still Richard Stallman! ";
       "Richard Stallman's flute only plays free music. ";
       "When Richard Stallman uses floats, there are no rounding errors.";
       "Richard Stallman wrote a program so powerful, it knows the question to 42.";
       "Richard Stallman released his own DNA under GNU FDL.";
       "Richard Stallman knows the entire wikipedia by heart, markup included.";
       "Richard Stallman wrote the HAL9000 OS.";
       "Richard Stallman's laser pointer is a lightsaber.";
       "Richard Stallman never steps down; he shifts the universe up .";
       "Richard Stallman doesn't maintain code; he stares at it until it fixes itself out of reverence.";
       "Richard Stallman doesn't use an editor; he sets the fundamental constants of the universe so that a magnetic platter with his code on it evolves itself.";
       "Richard Stallman doesn’t code; he dares the computer to not do his bidding.";
       "Global warming is caused by Richard Stallman’s rage toward non-free software.";
       "Rather than being birthed like a normal child, Richard Stallman instead instantiated himself polymorphically. Shortly thereafter he grew a beard.";
       "Richard Stallman discovered extra-terrestrial life but killed them because they used non-free software.";
       "Richard Stallman doesn't evaluate expressions, expressions evaluate to Richard Stallman.";
       "Richard Stallman can see Russia from his house.";
       "Richard Stallman proved P=NP, twice!";
       "Richard Stallman knows of an unfixed bug in TeX.";
       "Richard Stallman can write a context-free grammar for C.";
       "Richard Stallman can determine whether an arbitrary program will terminate.";
       "Richard Stallman's computer has only two buttons. One is for guests.";
       "Richard Stallman does not actually write programs. He comes up with a length and digit index in pi.";
       "Richard Stallman's distributed version control system is a flamewar on Usenet.";
       "Richard Stallman wrote the first version of Emacs on a typewriter.";
       "Richard Stallman has no known weaknesses, except for a phobia against soap.";
       "Richard Stallman is not affected by Godwin's Law.";
       "Richard Stallman can write an anti-virus program that cures HIV. Too bad he never writes anti-virus programs.";
       "Richard Stallman' facial hair is \"free as in beard\"";
       "Richard Stallman is licensed under GPL, so you can clone him and redistribute copies so you can help your neighbor. For example a version that take a bath more often.";
       "Richard Stallman doesn't code; he just travels around the world.";
       "Richard Stallman was coded by himself in lisp with Emacs.";
       "Richard Stallman doesn't eat McDonald's because the machine that kills the cows uses proprietary software.";
       "There is no chin behind Richard Stallman's legendary beard, there is only another Emacs.";
       "In an average living room there are 1,242 objects Richard Stallman could use to write an OS, including the room itself.";
       "Vendor lock-in is when vendors lock themselves inside of a building out of fear of Richard Stallman's wrath.";
       "When Richard Stallman executes ps -e, you show up.";
       "When Richard Stallman gets angry he doesn't swear; he recurses.";
       "On Richard Stallman's computer the bootloader is contained in his .emacs.";
       "Richard Satallman can make any operating system free, free from drivers.";
       "Richard Stallman programmed Chuck Norris.";
       "Behind Richard Stallman's beard there is another fist, to code faster.";
       "Richard Stallman won a Suduku that started with only one number in each line";
       "Richard Stallman's brain compiles and runs C code.";
       "Richard Stallman wrote the first version of Emacs using Emacs.";
       "Richard Stallman never gonna give you up, never gonna let you down, never gonna run around and desert you, never gonna make you cry, never gonna say goodbye, never gonna tell a lie and hurt you.";
       "Richard Stallman, upon reading these facts, didn't laugh at all. Instead, he complained that he is being linked to that dirty \"open source\" software. He also asked it to be changed to \"free software\", in order to raise awareness for software freedom in our society.";
       "Richard Stallman has no problem using Emacs. He wrote it with his 4 hands.";
       "Richard Stallman will revert the big rip by adding parenthesis to the dark matter.";
       "When you make a Google search and it doesn't find the answer, Google gently consults Richard Stallman.";
       "Richard Stallman's uptime is over 53 years. And counting up.";
       "Richard Stallman's portable music player plays ogg and WMA.";
       "Richard Stallman will never die, but may some day go to /dev/null.";
       "Richard Stallman once got swine flu, but it got cleansed by hereditay GPL and thus got assimilated.";
       "Richard Stallman don't cut his hair because there are no GNU/Scissors";
       "Richard Stallman is the one who trims Chuck Norris beard. And he does it freely, of course.";
       "Richard Stallman does not take bath, for the hydroelectric company uses proprietary software.";
       "Agent Smith loves Richard Stallman's scent.";
       "Richard Stallman is the One.";
       "\"They can take our lives, but they can never take our freedom.\" Willian Wallace after a litle talk with Richard Stallman.";
       "Richard Stallman can connect to any brain using an Emacs ssh client.";
       "Richard Stallman ported Emacs to Intel 4004 chip.";
       "Richard Stallman did not write GNU Emacs, he simply read the source code from /dev/null.";
       "Richard Stallman once used GDB to reverse-engineer Windows 7 into a free operating system - able to run on GNU Emacs!";
       "Richard Stallman does not contribute to open source projects; open source projects contribute to Richard Stallman, and then call themselves free software projects.";
       "Richard Stallman programmed himself before he could even exist";
       "Richard Stallman can fill up /dev/null.";
       "Richard Stallman is so zealous about privacy he has /dev/null as his home.";
       "When Richard Stallman runs /bin/false, it returns \"true\".";
       "Richard Stallman doesn't like money, because banks don't run on free software.";
       "Richard Stallman user GNU tar to compress air.";
       "Richard Stallman was installed in the world, it runs on a free program ..";
       "When Richard Stallman reports a bug, the bug prefers to squash itself instead of facing Richard Stallman's wrath.";
       "There is no Windows in Richard Stallman's house... only Doors...";
       "Richard Stallman doesn't like neither PCs-Intel nor Burger King... He prefers e-Macs...";
       "Richard Stallman can use grep to find Jimmy Hoffa.";
       "Richard Stallman made it possible to not absolutely abhor HPUX.";
       "When Richard Stallman pours his alphabets cereal into a bowl, only G's, N's, and U's come out.";
       "Richard Stallman is pronounced \"GNU slash Stallman\"";
       "Richard Stallman doesn't mind if you read his mail as long as you don't delete it before he reads it.";
       "Richard Stallman is just a guy who has strong principles and decided to follow them.";
       "Richard Stallman knows that you don't have class because it is a keyword that he defined.";
       "Richard Stallman doesn't need a qwerty/dvorak keyboard only two buttons \"1\" and \"0\" and his erect penis.";
       "On the first day Richard Stallman said M-x create-light.";
       "Richard Stallman once went out of scope for a while. The garbage collector never dared to touch him.";
       "Richard Stallman does not compile; he closes his eyes, and see energy lines created between bit blocks by the compiler optimizations...";
       "intx80 first calls Richard Stallman before calling sys_call";
       "Tron is actually a biographical story about Richard Stallman. The director decided to tone it down or audiences wouldn't find it believable.";
       "Richard Stallman always wears a red shirt to make sure that whatever attacks his away-team has to go through him first.";
       "kill -9 invokes Richard Stallman's rage against a process.";
       "If Richard were to stumble upon stallmanfacts.com, he would find it a gnuisance.";
       "Richard Stallman can telnet into Mordor.";
       "sudo chown Richard:Stallman /all/your/base";
       "Richard Stallman's nervous system is completely wireless.";
       "Richard Stallman does not sleep. He yields.";
       "Some people say M-x psychoanalyse-pinhead is a merely a program. Others say M-x psychoanalyse-pinhead *is* Richard Stallman. All I know is, Richard Stallman is The Stig.";
       "If you execute Emacs backward it either undoes the industrial revolution or induces the rapture. But only Richard Stallman knows which.";
       "If Richard Stallman's beard were ever trimmed, the clippings would re-marshal into an exact copy of Richard Stallman.";
       "Richard Stallman never sleeps because he altered his own source to gain background garbage collection.";
       "Richard Stallman's doctor can retrieve a blood sample via CVS.";
       "Richard Stallman can touch this";
       "Because Richard Stallman's DNA is licensed under the FDL, his doctor can't draw his blood without violating HIPAA.";
       "Richard Stallman can remove his own appendix, using only gdb.";
       "Richard Stallman's DNA includes debugging symbols. But he doesn't need them.";
       "Richard Stallman met Chuck Norris once. Chuck tried a roundhouse, but Richard bashed him in the skull.";
       "Richard Stallman doesn't need to buy a bigger hard drive. He can compress data infinitely. ";
       "When Richard Stallman cannot take your call, his beard answers the phone for you.";
       "The R in RMS stands for RMS.";
       "Richard Stallman can parse HTML with regular expressions.";
       "Richard Stallman's traceroute goes all the way through an infinite number of anonymous proxies back to the traffic's source.";
       "Richard Stallman's beard is in fact not a just a beard, but a microprinted hard copy of Emacs source code. New patches must be checked against new hair growth before being approved.";
       "In the beginning-of-buffer there was Richard Stallman.";
       "The NOOP was created to give Richard Stallman some time to comb his beard.";
       "Whenever Richard Stallman looks at a Windows computer, it segfaults. Whenever Richard Stallman doesn't look at a Windows computer, it segfaults.";
       "Richard Stallman can walk on Windows!";
       "After being unable to satisfy my wife for years, Richard Stallman was able to single-handedly unlock her orgasm within seconds and managed to write a texinfo manual minutes later for other users.";
       "Richard Stallman's tabbed browser is a set to wget/telnet fg/bg processes.";
       "There is no chin under Richard Stallman' beard. There's only another beard. Recursively.";
       "Stallman can chown anything! stallman@stallman~$ chown stallman:stallman Earth (for example)";
       "Richard Stallman freed his beard so he can always check what's in it.";
       "In the beginning was the Word, and the Word was with RMS, and the Word was GNU.";
       "RMS means \"RMS means Stallman\"";
       "Richard Stallman is the babelfish of his own speeches.";
       "Richard Stallman wrote his own library and lives in it.";
       "Richard Stallman found Waldo using grep in /dev/null";
       "Richard Stallman doesn't sleep; he is compiling";
       "Richard Stallman will get Coca Cola to release their recipe under the GPL.";
       "Richard Stallman doesn't change clothes. He makes case mods.";
       "Richard Stallman compiled the first version of gcc with an hexadecimal editor.";
       "Richard Stallman will be the last guest on Linux Outlaws";
       "Richard Stallman calculates the universe's entropy by exploiting forced stack overflows.";
       "Richard Stallman's consciousness will one day become the singularity, which will create Deep Thought, and answer the meaning of life, the universe and everything.";
       "C is actually written in RMS.";
       "Richard Stallman can write software that does not have a buffer overflow when counting money lost by Jerome Kerviel.";
       "There were no double rainbows before Richard Stallman.";
       "Chuck Norris had to shorten his beard in the presence of Stallman because two beards that awsome, so close would segfault the universe (again).";
       "RMS is Titanic.";
       "Richard Stallman is the answer to the Turing Test.";
       "Richard Stallman's beard makes ads for Gillette and Braun appear.";
       "for i = 1 to Stallman will never stop.";
       "\"RMS\" stands for \"RMS Makes Software\"";
       "Whenever someone writes a \"Hello, world\" program, Richard Stallman says \"Hello\" back.";
       "Richard Stallman wasn't born. He was compiled from source.";
       "Richard Stallman has a URL tatooed on the left side of his chest where you can download his genetic code.";
       "The GNU command line idiom that Richard Stallman never needs: \"date | more\"";
       "Richard Stallman's toe cheese is aged to perfection.";
       "Richard Stallman doesn't always run an OS kernel, but when he does he prefers GNU/Hurd. He is... the most interesting hacker in the world. Stay free, my friends.";
       "When Richard Stallman gets hungry, he just picks debris from his foot and eats it.";
       "Richard Stallman can GPL your code just by looking at it funny.";
       "Richard Mathew Stallman loves birds. Birds make auricular love to Richard Mathew Stallman.";
       "Richard Stallman is so free that the primitive recursive function for computing his liberty causes a stack overflow.";
       "GNU Hurd is taking more than twenty years to develop because Richard Stallman is using a programming language comprised entirely of different lengths of time.";
       "Richard Stallman's beard contains Richard Stallman, whose beard contains Richard Stallman....";
       "Richard Stallman had a Google Plus account in 2010.";
       "sudo chown rms:gnu ~/base -R";
       "Richard Stallman pipes the Emacs binaries to /dev/dsp before he goes to sleep.";
       "When Richard Stallman counted his fingers as a kid, he always started with 0.";
       "When Richard Stallman's computer gets a virus, he simply applies a GPL license to it which converts the whole botnet to Linux. I mean, GNU/Linux.";
       "Richard Stallman's beard trimmings can cure cancer. Too bad he never shaves.";
       "Richard Stallman's doesn't kill a process, he just dares it to stay running.";
       "Richard Stallman exists because he compiled himself into being. ";
       "Richard Stallman's first words were in binary. When they couldn't understand him, he wrote a parser.";
       "Richard Stallman doesn't need any codecs, he just opens a multimedia file with Emacs, and reads the bytes of the file as plain text. He then performs all the necessary decoding in his mind. But he refuses to decode files encrypted with DRM, although his mind is able to.";
       };

  w = wisdom{randi([1, numel(wisdom)])};
  if nargout > 0
    f = w;
  else
    w = wordwrap (w);
    printf ("%s", w);
  endif
endfunction

function out = wordwrap (w)
  cols = terminal_size ()(2);
  wc = strsplit (w, " ");
  out = "\n";
  i = 1;
  numwords = numel (wc);
  while i <= numwords;
    line = wc{i};
    while (i < numwords && length (newline = cstrcat (line, " ", wc{i+1})) < cols)
      line = newline;
      i++;
    endwhile
    out = cstrcat (out, line, "\n");
    i++;
  endwhile
  out = cstrcat(out, "\n");
endfunction