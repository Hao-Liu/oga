#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT(OpenGameArch, 0.1, liuhaonk@gmail.com)
AM_INIT_AUTOMAKE(OpenGameArch, 0.1)
AC_CONFIG_SRCDIR([src/OpenGameArch.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES(OGRE, [OGRE >= 1.2])
AC_SUBST(OGRE_CFLAGS)
AC_SUBST(OGRE_LIBS)

PKG_CHECK_MODULES(OIS, [OIS >= 1.0])
AC_SUBST(OIS_CFLAGS)
AC_SUBST(OIS_LIBS)

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT(Makefile src/Makefile)
