/*

-Header_File f2c.h ( CSPICE version of the f2c standard header file )

-Abstract

   Perform standard f2c declarations, customized for the host
   environment.

-Disclaimer

   THIS SOFTWARE AND ANY RELATED MATERIALS WERE CREATED BY THE
   CALIFORNIA INSTITUTE OF TECHNOLOGY (CALTECH) UNDER A U.S.
   GOVERNMENT CONTRACT WITH THE NATIONAL AERONAUTICS AND SPACE
   ADMINISTRATION (NASA). THE SOFTWARE IS TECHNOLOGY AND SOFTWARE
   PUBLICLY AVAILABLE UNDER U.S. EXPORT LAWS AND IS PROVIDED "AS-IS"
   TO THE RECIPIENT WITHOUT WARRANTY OF ANY KIND, INCLUDING ANY
   WARRANTIES OF PERFORMANCE OR MERCHANTABILITY OR FITNESS FOR A
   PARTICULAR USE OR PURPOSE (AS SET FORTH IN UNITED STATES UCC
   SECTIONS 2312-2313) OR FOR ANY PURPOSE WHATSOEVER, FOR THE
   SOFTWARE AND RELATED MATERIALS, HOWEVER USED.

   IN NO EVENT SHALL CALTECH, ITS JET PROPULSION LABORATORY, OR NASA
   BE LIABLE FOR ANY DAMAGES AND/OR COSTS, INCLUDING, BUT NOT
   LIMITED TO, INCIDENTAL OR CONSEQUENTIAL DAMAGES OF ANY KIND,
   INCLUDING ECONOMIC DAMAGE OR INJURY TO PROPERTY AND LOST PROFITS,
   REGARDLESS OF WHETHER CALTECH, JPL, OR NASA BE ADVISED, HAVE
   REASON TO KNOW, OR, IN FACT, SHALL KNOW OF THE POSSIBILITY.

   RECIPIENT BEARS ALL RISK RELATING TO QUALITY AND PERFORMANCE OF
   THE SOFTWARE AND ANY RELATED MATERIALS, AND AGREES TO INDEMNIFY
   CALTECH AND NASA FOR ALL THIRD-PARTY CLAIMS RESULTING FROM THE
   ACTIONS OF RECIPIENT IN THE USE OF THE SOFTWARE.

-Required_Reading

   None.

-Particulars

   The standard f2c header file f2c.h must be included by every function
   generated by running f2c on Fortran source code.  The header f2c.h
   includes typedefs used to provide a level of indirection in mapping
   Fortran data types to native C data types.  For example, Fortran
   INTEGER variables are mapped to variables of type integer, where
   integer is a C typedef.  In the standard f2c.h header, the typedef
   integer translates to the C type long.

   Because the standard version of f2c.h does not work on all platforms,
   this header file contains two platform-dependent versions of it,
   meant to be selected at build time via precompiler switches.  The
   precompiler switches reference macros defined in SpiceZpl.h to
   determine for which host platform the code is targeted.  The first
   version of f2c.h, which works on most platforms, is copied directly
   from the standard version of f2c.h.  The second version is intended
   for use on the DEC Alpha running Digital Unix and the Sun/Solaris
   platform using 64 bit mode and running gcc.  On those systems, longs
   occupy 8 bytes, as do doubles.  Because the Fortran standard requires
   that INTEGERS occupy half the storage of DOUBLE PRECISION numbers,
   INTEGERS should be mapped to 4-byte ints rather than 8-byte longs
   on the platforms having 8-byte longs.  In order to achieve this, the
   header f2c.h was transformed using the sed command

      sed 's/long //' f2c.h

   The high-level structure of this file is then:

      # if (    defined(CSPICE_ALPHA_DIGITAL_UNIX    )   \
             || defined(CSPICE_SUN_SOLARIS_64BIT_GCC )  )


         [ Alpha/Digital Unix and Sun Solaris 64 bit mode/gcc
           version of f2c.h source code ]

      # else

         [ Standard version of f2c.h source code ]

      # endif


-Restrictions

  1) This header file must be updated whenever the f2c processor
     or the f2c libraries libI77 and libF77 are updated.

  2) This header may need to be updated to support new platforms.
     The supported platforms at the time of the 31-JAN-1999 release
     are:

        ALPHA-DIGITAL-UNIX
        HP
        NEXT
        PC-LINUX
        PC-MS
        SGI-IRIX-N32
        SGI-IRIX-NO2
        SUN-SOLARIS

-Literature_References

   None.

-Author_and_Institution

   N.J. Bachman       (JPL)
   B.V. Semenov       (JPL)
   E.D. Wright        (JPL)

-Version

   -CSPICE Version 4.2.0, 09-APR-2014 (EDW) (BVS)

      Added include for SpiceZrnm.h to eliminate symbol conflict
      encountered from Icy and JNISpice under OS X 10.7.

      Minor text format correction to eliminate error signal from
      OS X cpp. The edit removes leading whitespace from the
      final "#endif".

      Updated for:

         PC-CYGWIN-64BIT-GCC_C

      environment. Added the corresponding tag:

         CSPICE_PC_CYGWIN_64BIT_GCC

      tag to the #ifdefs set.

   -CSPICE Version 4.1.0, 14-MAY-2010 (EDW)(BVS)

       Updated for:

          MAC-OSX-64BIT-INTEL_C
          SUN-SOLARIS-64BIT-NATIVE_C
          SUN-SOLARIS-INTEL-64BIT-CC_C

       environments. Added the corresponding tags:

          CSPICE_MAC_OSX_INTEL_64BIT_GCC
          CSPICE_SUN_SOLARIS_64BIT_NATIVE
          CSPICE_SUN_SOLARIS_INTEL_64BIT_CC

       tag to the #ifdefs set.

   -CSPICE Version 4.0.0, 21-FEB-2006 (NJB)

       Updated to support the PC Linux 64 bit mode/gcc platform.

   -CSPICE Version 3.0.0, 27-JAN-2003 (NJB)

       Updated to support the Sun Solaris 64 bit mode/gcc platform.

   -CSPICE Version 2.0.0, 19-DEC-2001 (NJB)

      Updated to support linking CSPICE into executables that
      also link in objects compiled from Fortran, in particular
      ones that perform Fortran I/O.  To enable this odd mix,
      one defines the  preprocessor flag

         MIX_C_AND_FORTRAN

      This macro is undefined by default, since the action it invokes
      is usually not desirable.  See the header

         f2cMang.h

      for further information.

   -CSPICE Version 1.0.0, 07-FEB-1999 (NJB)

*/

/*
Include those rename assignments for routines whose symbols will
collide with other libraries.
*/
#ifndef HAVE_SPICERENAME_H
#include "SpiceZrnm.h"
#endif

/*
Optionally include name-mangling macros for f2c external symbols.
*/
#ifdef MIX_C_AND_FORTRAN
#include "f2cMang.h"
#endif

/*
Include CSPICE platform macro definitions.
*/
#include "SpiceZpl.h"

#if (defined(CSPICE_ALPHA_DIGITAL_UNIX) || defined(CSPICE_SUN_SOLARIS_64BIT_GCC)                                       \
     || defined(CSPICE_SUN_SOLARIS_64BIT_NATIVE) || defined(CSPICE_MAC_OSX_INTEL_64BIT_GCC)                            \
     || defined(CSPICE_SUN_SOLARIS_INTEL_64BIT_CC) || defined(CSPICE_PC_CYGWIN_64BIT_GCC)                              \
     || defined(CSPICE_PC_LINUX_64BIT_GCC))

/*
MODIFICATION

The following code is intended to be used on the platforms where
a long is the size of a double and an int is half the
size of a double.

Note that the comment line below indicating that the header is
"Standard" has been retained from the original, but is no longer
true.
*/

/* f2c.h  --  Standard Fortran to C header file */

#ifndef F2C_INCLUDE
#define F2C_INCLUDE

typedef int integer;
typedef unsigned uinteger;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct {
    real r, i;
} complex_type;
typedef struct {
    doublereal r, i;
} doublecomplex;
typedef int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;
#if 0 /* Adjust for integer*8. */
typedef long longint;      /* system-dependent */
typedef unsigned long ulongint;  /* system-dependent */
#define qbit_clear(a, b) ((a) & ~((ulongint)1 << (b)))
#define qbit_set(a, b) ((a) | ((ulongint)1 << (b)))
#endif

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* I/O stuff */

#ifdef f2c_i2
/* for -i2 */
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef int flag;
typedef int ftnlen;
typedef int ftnint;
#endif

/*external read, write*/
typedef struct {
    flag cierr;
    ftnint ciunit;
    flag ciend;
    char *cifmt;
    ftnint cirec;
} cilist;

/*internal read, write*/
typedef struct {
    flag icierr;
    char *iciunit;
    flag iciend;
    char *icifmt;
    ftnint icirlen;
    ftnint icirnum;
} icilist;

/*open*/
typedef struct {
    flag oerr;
    ftnint ounit;
    char *ofnm;
    ftnlen ofnmlen;
    char *osta;
    char *oacc;
    char *ofm;
    ftnint orl;
    char *oblnk;
} olist;

/*close*/
typedef struct {
    flag cerr;
    ftnint cunit;
    char *csta;
} cllist;

/*rewind, backspace, endfile*/
typedef struct {
    flag aerr;
    ftnint aunit;
} alist;

/* inquire */
typedef struct {
    flag inerr;
    ftnint inunit;
    char *infile;
    ftnlen infilen;
    ftnint *inex; /*parameters in standard's order*/
    ftnint *inopen;
    ftnint *innum;
    ftnint *innamed;
    char *inname;
    ftnlen innamlen;
    char *inacc;
    ftnlen inacclen;
    char *inseq;
    ftnlen inseqlen;
    char *indir;
    ftnlen indirlen;
    char *infmt;
    ftnlen infmtlen;
    char *inform;
    ftnint informlen;
    char *inunf;
    ftnlen inunflen;
    ftnint *inrecl;
    ftnint *innrec;
    char *inblank;
    ftnlen inblanklen;
} inlist;

#define VOID void

union Multitype { /* for multiple entry points */
    integer1 g;
    shortint h;
    integer i;
    /* longint j; */
    real r;
    doublereal d;
    complex_type c;
    doublecomplex z;
};

typedef union Multitype Multitype;

/*typedef int Long;*/ /* No longer used; formerly in Namelist */

struct Vardesc { /* for Namelist */
    char *name;
    char *addr;
    ftnlen *dims;
    int type;
};
typedef struct Vardesc Vardesc;

struct Namelist {
    char *name;
    Vardesc **vars;
    int nvars;
};
typedef struct Namelist Namelist;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal) abs(x)
#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define dmin(a, b) (doublereal) min(a, b)
#define dmax(a, b) (doublereal) max(a, b)
#define bit_test(a, b) ((a) >> (b)&1)
#define bit_clear(a, b) ((a) & ~((uinteger)1 << (b)))
#define bit_set(a, b) ((a) | ((uinteger)1 << (b)))

/* procedure parameter types for -A and -C++ */

#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* complex_type */ VOID (*C_fp)(...);
typedef /* Double complex_type */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* complex_type */ VOID (*C_fp)();
typedef /* Double complex_type */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif
/* E_fp is for real functions when -R is not specified */
typedef VOID C_f;       /* complex_type function */
typedef VOID H_f;       /* character function */
typedef VOID Z_f;       /* double complex_type function */
typedef doublereal E_f; /* real function with -R not specified */

/* undef any lower-case symbols that your C compiler predefines, e.g.: */

#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif
#endif

/*
This marks the end of the MODIFICATION section version of f2c.h.
*/

#else

/*
The following code is the standard f2c.h header.  In this
header, an "integer" is defined to be of type long.

Because the code is copied verbatim, it does not follow the usual
CSPICE indentation pattern.
*/

/* f2c.h  --  Standard Fortran to C header file */

#ifndef F2C_INCLUDE
#define F2C_INCLUDE

typedef long int integer;
typedef unsigned long uinteger;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct {
    real r, i;
} complex_type;
typedef struct {
    doublereal r, i;
} doublecomplex;
typedef long int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;
#if 0 /* Adjust for integer*8. */
typedef long long longint;    /* system-dependent */
typedef unsigned long long ulongint;   /* system-dependent */
#define qbit_clear(a, b) ((a) & ~((ulongint)1 << (b)))
#define qbit_set(a, b) ((a) | ((ulongint)1 << (b)))
#endif

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* I/O stuff */

#ifdef f2c_i2
/* for -i2 */
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef long int flag;
typedef long int ftnlen;
typedef long int ftnint;
#endif

/*external read, write*/
typedef struct {
    flag cierr;
    ftnint ciunit;
    flag ciend;
    char *cifmt;
    ftnint cirec;
} cilist;

/*internal read, write*/
typedef struct {
    flag icierr;
    char *iciunit;
    flag iciend;
    char *icifmt;
    ftnint icirlen;
    ftnint icirnum;
} icilist;

/*open*/
typedef struct {
    flag oerr;
    ftnint ounit;
    char *ofnm;
    ftnlen ofnmlen;
    char *osta;
    char *oacc;
    char *ofm;
    ftnint orl;
    char *oblnk;
} olist;

/*close*/
typedef struct {
    flag cerr;
    ftnint cunit;
    char *csta;
} cllist;

/*rewind, backspace, endfile*/
typedef struct {
    flag aerr;
    ftnint aunit;
} alist;

/* inquire */
typedef struct {
    flag inerr;
    ftnint inunit;
    char *infile;
    ftnlen infilen;
    ftnint *inex; /*parameters in standard's order*/
    ftnint *inopen;
    ftnint *innum;
    ftnint *innamed;
    char *inname;
    ftnlen innamlen;
    char *inacc;
    ftnlen inacclen;
    char *inseq;
    ftnlen inseqlen;
    char *indir;
    ftnlen indirlen;
    char *infmt;
    ftnlen infmtlen;
    char *inform;
    ftnint informlen;
    char *inunf;
    ftnlen inunflen;
    ftnint *inrecl;
    ftnint *innrec;
    char *inblank;
    ftnlen inblanklen;
} inlist;

#define VOID void

union Multitype { /* for multiple entry points */
    integer1 g;
    shortint h;
    integer i;
    /* longint j; */
    real r;
    doublereal d;
    complex_type c;
    doublecomplex z;
};

typedef union Multitype Multitype;

/*typedef long int Long;*/ /* No longer used; formerly in Namelist */

struct Vardesc { /* for Namelist */
    char *name;
    char *addr;
    ftnlen *dims;
    int type;
};
typedef struct Vardesc Vardesc;

struct Namelist {
    char *name;
    Vardesc **vars;
    int nvars;
};
typedef struct Namelist Namelist;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal) abs(x)
#define min(a, b) ((a) <= (b) ? (a) : (b))
#define max(a, b) ((a) >= (b) ? (a) : (b))
#define dmin(a, b) (doublereal) min(a, b)
#define dmax(a, b) (doublereal) max(a, b)
#define bit_test(a, b) ((a) >> (b)&1)
#define bit_clear(a, b) ((a) & ~((uinteger)1 << (b)))
#define bit_set(a, b) ((a) | ((uinteger)1 << (b)))

/* procedure parameter types for -A and -C++ */

#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* complex_type */ VOID (*C_fp)(...);
typedef /* Double complex_type */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* complex_type */ VOID (*C_fp)();
typedef /* Double complex_type */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif
/* E_fp is for real functions when -R is not specified */
typedef VOID C_f;       /* complex_type function */
typedef VOID H_f;       /* character function */
typedef VOID Z_f;       /* double complex_type function */
typedef doublereal E_f; /* real function with -R not specified */

/* undef any lower-case symbols that your C compiler predefines, e.g.: */

#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif
#endif

#endif