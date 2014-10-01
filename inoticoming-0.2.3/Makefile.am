EXAMPLES =  examples/cronjob examples/inoticoming.init examples/inoticoming.default
EXTRA_DIST = autogen.sh inoticoming.1 $(EXAMPLES)

bin_PROGRAMS = inoticoming

inoticoming_SOURCES = inoticoming.c closeallfds.c
noinst_HEADERS = closeallfds.h
man_MANS = inoticoming.1

MAINTAINERCLEANFILES = $(srcdir)/Makefile.in $(srcdir)/configure $(srcdir)/stamp-h.in $(srcdir)/aclocal.m4 $(srcdir)/config.h.in $(srcdir)/config.h.in~

distclean-local:
	-rm -rf autom4te.cache
maintainer-clean-local:
	-rm -rf $(srcdir)/ac $(srcdir)/autom4te.cache
