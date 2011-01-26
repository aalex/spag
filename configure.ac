# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.53)
AC_INIT(spag, [0.1.1], [http://github.com/aalex/spag/issues], [spatosc], [http://github.com/aalex/spag])
AC_MSG_NOTICE([Configuring spag])
AC_CONFIG_HEADER(spag/config.h)
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([subdir-objects -Wno-portability])

# Check for programs:
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LIBTOOL
# AC_LIBTOOL_WIN32_DLL
AC_LIBTOOL_DLOPEN

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for libraries
AC_CHECK_LIB([m],[sqrt])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h stddef.h stdlib.h string.h sys/time.h])

# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([gettimeofday memmove mkdir setenv sqrt strchr strpbrk uname])

# Setup flags:
AC_SUBST(CXXFLAGS, " -O2 -Wall -Werror -Wextra -Wfatal-errors -Wnon-virtual-dtor") 

# Output files:
AC_CONFIG_FILES([
    Makefile
    spag/Makefile
    ])
AC_OUTPUT

