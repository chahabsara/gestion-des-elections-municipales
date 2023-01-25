## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = validation

validation_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	reclamation.c reclamation.h \
	election.c election.h \
	fonction.c fonction.h \
	listelc.c listelc.h \
	observateur.c observateur.h

validation_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

