<!DOCTYPE style-sheet PUBLIC "-//James Clark//DTD DSSSL Style Sheet//EN" [
<!ENTITY % cyr1 PUBLIC "ISO 8879:1986//ENTITIES Russian Cyrillic//EN">
%cyr1;
<!ENTITY % ru.words
  PUBLIC "-//Norman Walsh//ENTITIES DocBook Stylesheet Localization//RU"
         "dbl1ru.ent">
%ru.words;
]>

<style-sheet>
<style-specification id="docbook-l10n-ru">
<style-specification-body>

;; $Id: dbl1ru.dsl,v 1.17 2000/02/07 12:45:04 nwalsh Exp $
;;
;; This file is part of the Modular DocBook Stylesheet distribution.
;; See ../README or http://nwalsh.com/docbook/dsssl/
;;

;; ----------------------------- Localization -----------------------------

;; If you create a new version of this file, please send it to
;; Norman Walsh, ndw@nwalsh.com

;; This is revised Russian Localization version by Norman Walsh, modified by
;; Ilia V. Kouznetsov, ilia@syntext.com

;; Suggestion of I. Kouznetsov: According to my experience of writing
;; documentation, Russian Words for cross references had better be
;; abbreviated (just like it is usually done in Russian documents)
;; because the ends of not abbreviated cross references may vary from
;; place to place due to the cases of Russian language. Due to this reason
;; entities with ".abr" syffix are added.

;; The generated text for cross references to elements.  See dblink.dsl
;; for a discussion of how substitution is performed on the %x
;; keywords.
;;

(define (ru-xref-strings)
  (list (list (normalize "appendix")    (if %chapter-autolabel%
					    "&Appendix.abr; %n"
					    "&Appendix.abr; %t"))
	(list (normalize "article")     (string-append %gentext-ru-start-quote%
						       "%t"
						       %gentext-ru-end-quote%))
	(list (normalize "bibliography") "%t")
	(list (normalize "book")        "%t")
	(list (normalize "chapter")     (if %chapter-autolabel%
					    "&Chapter.abr; %n"
					    "&Chapter.abr; %t"))
	(list (normalize "equation")    "&Equation.abr; %n")
	(list (normalize "example")     "&Example.abr; %n")
	(list (normalize "figure")      "&Figure.abr; %n")
	(list (normalize "glossary")    "%t")
	(list (normalize "index")       "%t")
	(list (normalize "listitem")    "%n")
	(list (normalize "part")        "&Part.abr; %n")
	(list (normalize "preface")     "%t")
	(list (normalize "procedure")   "&Procedure.abr; %n, %t")
	(list (normalize "reference")   "&Reference; %n, %t")
	(list (normalize "section")     (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sect1")       (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sect2")       (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sect3")       (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sect4")       (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sect5")       (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "simplesect")  (if %section-autolabel%
					    "&Section.abr; %n"
					    "&Section.abr; %t"))
	(list (normalize "sidebar")     "&sidebar; %t")
	(list (normalize "step")        "&step; %n")
	(list (normalize "table")       "&Table.abr; %n")))

(define (gentext-ru-xref-strings gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (xref   (assoc name (ru-xref-strings))))
    (if xref
	(car (cdr xref))
	(let* ((msg    (string-append "[&xrefto; "
				      (if giname giname "&nonexistantelement;")
				      " &unsupported;]"))
	       (err    (node-list-error msg (current-node))))
	  msg))))

(define (ru-auto-xref-indirect-connector before) 
  (literal " &in; "))

;; Should the TOC come first or last?
;;
(define %generate-ru-toc-in-front% #t)

;; gentext-element-name returns the generated text that should be 
;; used to make reference to the selected element.
;;

(define (ru-element-name)
  (list
   (list (normalize "abstract")		"&Abstract;")
   (list (normalize "answer")		"&Answer;")
   (list (normalize "appendix")		"&Appendix;")
   (list (normalize "article")		"&Article;")
   (list (normalize "bibliography")	"&Bibliography;")
   (list (normalize "book")		"&Book;")
   (list (normalize "calloutlist")	"")
   (list (normalize "caution")		"&Caution;")
   (list (normalize "chapter")		"&Chapter;")
   (list (normalize "copyright")	"&Copyright;")
   (list (normalize "dedication")	"&Dedication;")
   (list (normalize "edition")		"&Edition;")
   (list (normalize "equation")		"&Equation;")
   (list (normalize "example")		"&Example;")
   (list (normalize "figure")		"&Figure;")
   (list (normalize "glossary")		"&Glossary;")
   (list (normalize "glosssee")		"&GlossSee;")
   (list (normalize "glossseealso")	"&GlossSeeAlso;")
   (list (normalize "important")	"&Important;")
   (list (normalize "index")		"&Index;")
   (list (normalize "colophon")		"&Colophon;")
   (list (normalize "setindex")		"&SetIndex;")
   (list (normalize "isbn")		"&ISBN;")
   (list (normalize "legalnotice")	"&LegalNotice;")
   (list (normalize "msgaud")		"&MsgAud;")
   (list (normalize "msglevel")		"&MsgLevel;")
   (list (normalize "msgorig")		"&MsgOrig;")
   (list (normalize "note")		"&Note;")
   (list (normalize "part")		"&Part;")
   (list (normalize "preface")		"&Preface;")
   (list (normalize "procedure")	"&Procedure;")
   (list (normalize "pubdate")		"&Published;")
   (list (normalize "question")		"&Question;")
   (list (normalize "refentry")		"&RefEntry;")
   (list (normalize "reference")	"&Reference;")
   (list (normalize "refname")		"&RefName;")
   (list (normalize "revhistory")	"&RevHistory;")
   (list (normalize "refsect1")		"&RefSection;")
   (list (normalize "refsect2")		"&RefSection;")
   (list (normalize "refsect3")		"&RefSection;")
   (list (normalize "refsynopsisdiv")	"&RefSynopsisDiv;")
   (list (normalize "revision")		"&Revision;")
   (list (normalize "sect1")		"&Section;")
   (list (normalize "sect2")		"&Section;")
   (list (normalize "sect3")		"&Section;")
   (list (normalize "sect4")		"&Section;")
   (list (normalize "sect5")		"&Section;")
   (list (normalize "section")		"&Section;")
   (list (normalize "simplesect")	"&Section;")
   (list (normalize "seeie")		"&See;")
   (list (normalize "seealsoie")	"&Seealso;")
   (list (normalize "set")		"&Set;")
   (list (normalize "sidebar")		"&Sidebar;")
   (list (normalize "step")		"&step;")
   (list (normalize "table")		"&Table;")
   (list (normalize "tip")		"&Tip;")
   (list (normalize "toc")		"&TableofContents;")
   (list (normalize "warning")		"&Warning;")
   ))

(define (gentext-ru-element-name gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (pname  (assoc name (ru-element-name))))
    (if pname
	(car (cdr pname))
	(let* ((msg (string-append 
		     "gentext-ru-element-name: &unexpectedelementname;: "
		     name))
	       (err (node-list-error msg (current-node))))
	  msg))))

;; gentext-element-name-space returns gentext-element-name with a 
;; trailing space, if gentext-element-name isn't "".
;;
(define (gentext-ru-element-name-space giname)
  (string-with-space (gentext-element-name giname)))

;; gentext-intra-label-sep returns the seperator to be inserted
;; between multiple occurances of a label (or parts of a label)
;; for the specified element.  Most of these are for enumerated
;; labels like "Figure 2-4", but this function is used elsewhere
;; (e.g. REFNAME) with a little abuse.
;;

(define (ru-intra-label-sep)
  (list
   (list (normalize "equation")		"-")
   (list (normalize "informalequation")	"-")
   (list (normalize "example")		"-")
   (list (normalize "figure")		"-")
   (list (normalize "listitem")		".")
   (list (normalize "procedure")	".")
   (list (normalize "refentry")		".")
   (list (normalize "reference")	".")
   (list (normalize "refname")		", ")
   (list (normalize "refsect1")		".")
   (list (normalize "refsect2")		".")
   (list (normalize "refsect3")		".")
   (list (normalize "sect1")		".")
   (list (normalize "sect2")		".")
   (list (normalize "sect3")		".")
   (list (normalize "sect4")		".")
   (list (normalize "sect5")		".")
   (list (normalize "section")		".")
   (list (normalize "simplesect")	".")
   (list (normalize "step")		".")
   (list (normalize "table")		"-")
   (list (normalize "_pagenumber")	"-")
   ))

(define (gentext-ru-intra-label-sep gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (sep    (assoc name (ru-intra-label-sep))))
    (if sep
	(car (cdr sep))
	"")))

;; gentext-label-title-sep returns the seperator to be inserted
;; between a label and the text following the label for the
;; specified element.  Most of these are for use between
;; enumerated labels and titles like "1. Chapter One Title", but
;; this function is used elsewhere (e.g. NOTE) with a little
;; abuse.
;;

(define (ru-label-title-sep)
  (list
   (list (normalize "abstract")		": ")
   (list (normalize "answer")		" ")
   (list (normalize "appendix")		". ")
   (list (normalize "caution")		"")
   (list (normalize "chapter")		". ")
   (list (normalize "equation")		". ")
   (list (normalize "example")		". ")
   (list (normalize "figure")		". ")
   (list (normalize "footnote")		". ")
   (list (normalize "glosssee")		": ")
   (list (normalize "glossseealso")	": ")
   (list (normalize "important")	": ")
   (list (normalize "note")		": ")
   (list (normalize "orderedlist")	". ")
   (list (normalize "part")		". ")
   (list (normalize "procedure")	". ")
   (list (normalize "prefix")		". ")
   (list (normalize "question")		" ")
   (list (normalize "refentry")		"")
   (list (normalize "reference")	". ")
   (list (normalize "refsect1")		". ")
   (list (normalize "refsect2")		". ")
   (list (normalize "refsect3")		". ")
   (list (normalize "sect1")		". ")
   (list (normalize "sect2")		". ")
   (list (normalize "sect3")		". ")
   (list (normalize "sect4")		". ")
   (list (normalize "sect5")		". ")
   (list (normalize "section")		". ")
   (list (normalize "simplesect")	". ")
   (list (normalize "seeie")		" ")
   (list (normalize "seealsoie")	" ")
   (list (normalize "step")		". ")
   (list (normalize "table")		". ")
   (list (normalize "tip")		": ")
   (list (normalize "warning")		"")
   ))

(define (gentext-ru-label-title-sep gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (sep    (assoc name (ru-label-title-sep))))
    (if sep
	(car (cdr sep))
	"")))

(define (ru-label-number-format-list)
  (list
   (list (normalize "set")		"1")
   (list (normalize "book")		"1")
   (list (normalize "prefix")		"1")
   (list (normalize "part")		"I")
   (list (normalize "chapter")		"1")
   (list (normalize "appendix")		"A")
   (list (normalize "reference")	"I")
   (list (normalize "example")		"1")
   (list (normalize "figure")		"1")
   (list (normalize "table")		"1")
   (list (normalize "procedure")	"1")
   (list (normalize "step")		"1")
   (list (normalize "refsect1")		"1")
   (list (normalize "refsect2")		"1")
   (list (normalize "refsect3")		"1")
   (list (normalize "sect1")		"1")
   (list (normalize "sect2")		"1")
   (list (normalize "sect3")		"1")
   (list (normalize "sect4")		"1")
   (list (normalize "sect5")		"1")
   (list (normalize "section")		"1")
   ))

(define (ru-label-number-format gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (format (assoc name (ru-label-number-format-list))))
    (if format
	(car (cdr format))
	"1")))

(define (ru-lot-title)
  (list
   (list (normalize "table")		"&ListofTables;")
   (list (normalize "example")		"&ListofExamples;")
   (list (normalize "figure")		"&ListofFigures;")
   (list (normalize "equation")		"&ListofEquations;")
   ))

(define ($lot-title-ru$ gind)
  (let* ((giname (if (string? gind) gind (gi gind)))
	 (name   (normalize giname))
	 (title  (assoc name (ru-lot-title))))
    (if title
	(car (cdr title))
	(let* ((msg (string-append "&ListofUnknown;: " name))
	       (err (node-list-error msg (current-node))))
	  msg))))

(define %gentext-ru-start-quote% (dingbat "ldquo"))

(define %gentext-ru-end-quote% (dingbat "rdquo"))

(define %gentext-ru-start-nested-quote% (dingbat "lsquo"))

(define %gentext-ru-end-nested-quote% (dingbat "rsquo"))

(define %gentext-ru-by% "&by;") ;; e.g. Copyright 1997 "by" A. Nonymous
                           ;; Authored "by" Jane Doe

(define %gentext-ru-edited-by% "&Editedby;")
                           ;; "Edited by" Jane Doe

(define %gentext-ru-revised-by% "&Revisedby;")
                           ;; "Revised by" Jane Doe

(define %gentext-ru-page% "")

(define %gentext-ru-and% "&and;")

(define %gentext-ru-bibl-pages% "&Pgs;")

(define %gentext-ru-endnotes% "&Notes;")

(define %gentext-ru-table-endnotes% "&TableNotes;:")

(define %gentext-ru-index-see% "&See;")

(define %gentext-ru-index-seealso% "&SeeAlso;")


(define (gentext-ru-nav-prev prev) 
  (make sequence (literal "&nav-prev;")))

(define (gentext-ru-nav-prev-sibling prevsib) 
  (make sequence (literal "&nav-prev-sibling;")))

(define (gentext-ru-nav-next-sibling nextsib)
  (make sequence (literal "&nav-next-sibling;")))

(define (gentext-ru-nav-next next)
  (make sequence (literal "&nav-next;")))

(define (gentext-ru-nav-up up)
  (make sequence (literal "&nav-up;")))

(define (gentext-ru-nav-home home)
  (make sequence (literal "&nav-home;")))



</style-specification-body>
</style-specification>
</style-sheet>
