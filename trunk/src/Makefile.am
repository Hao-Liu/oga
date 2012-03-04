# what flags you want to pass to the C compiler & linker
AM_CFLAGS = -Wall -O2 -g

# this lists the binaries to produce, the (non-PHONY, binary) targets in
# the previous manual Makefile
bin_PROGRAMS = $(top_builddir)/OpenGameArch
__top_builddir__OpenGameArch_CPPFLAGS= -I$(top_srcdir)
__top_builddir__OpenGameArch_SOURCES= 	OpenGameArch.cpp OpenGameArch.h\
								GameStateManager.cpp GameStateManager.h\
						 		GameState.cpp GameState.h\
								GameStateGamePlay.cpp GameStateGamePlay.h
__top_builddir__OpenGameArch_CXXFLAGS= $(OGRE_CFLAGS) $(OIS_CFLAGS)
__top_builddir__OpenGameArch_LDADD= $(OGRE_LIBS) $(OIS_LIBS)

