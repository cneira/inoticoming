dnl
dnl Process this file with autoconf to produce a configure script
dnl

AC_INIT(inoticoming,0.2.3,brlink@debian.org)
AC_CONFIG_AUX_DIR(ac)
AC_CONFIG_SRCDIR(inoticoming.c)
AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE([-Wall -Werror])

AM_MAINTAINER_MODE
AC_GNU_SOURCE

AC_PROG_CC
AC_PROG_INSTALL
AC_SYS_LARGEFILE

AC_CHECK_FUNCS([closefrom])
AC_CHECK_HEADERS(sys/inotify.h,,[
AC_CHECK_HEADERS(inotifytools/inotify.h,,[
AC_MSG_ERROR(["Cannot proceed without sys/inotify.h and without inotifytools/inotify.h"])])
])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
