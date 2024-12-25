# Makefile.am  2019-05-20 $

AM_CFLAGS = -W -Wall -Wextra -ansi
AM_CXXFLAGS = -W -Wall -Wextra -ansi

noinst_LIBRARIES = libphraseparser.a

libphraseparser_a_SOURCES = \
	parser.yy scanner.ll parser.h scanner.h y.tab.h \
	location.hh position.hh stack.hh FlexLexer.h \
	driver.cc driver.h expression.h

bin_PROGRAMS = aarohi

aarohi_SOURCES = aarohi.cc
aarohi_DEPENDENCIES = libphraseparser.a

LIBS = libphraseparser.a

# c++ scanner spits out to lex.yy.cc, automake ylwrap checks for 
# lex.yy.cc alone, this is needed to override the output
AM_LFLAGS = -olex.yy.c

EXTRA_DIST = readme.dox aarohi.txt \
	aarohi.vcproj libphraseparser.vcproj \
	Makefile.plain

extraclean:
	rm -f parser.cc parser.h scanner.cc

rebuild: clean extraclean all
