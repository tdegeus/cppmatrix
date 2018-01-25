/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_MACROS_H
#define CPPMAT_MACROS_H

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#define CPPMAT_WORLD_VERSION 0
#define CPPMAT_MAJOR_VERSION 3
#define CPPMAT_MINOR_VERSION 8

#define CPPMAT_VERSION_AT_LEAST(x,y,z) \
  (CPPMAT_WORLD_VERSION>x || (CPPMAT_WORLD_VERSION>=x && \
  (CPPMAT_MAJOR_VERSION>y || (CPPMAT_MAJOR_VERSION>=y && \
                              CPPMAT_MINOR_VERSION>=z))))

#define CPPMAT_VERSION(x,y,z) \
  (CPPMAT_WORLD_VERSION==x && \
   CPPMAT_MAJOR_VERSION==y && \
   CPPMAT_MINOR_VERSION==z)

// dummy operation that can be use to suppress the "unused parameter" warnings
#define UNUSED(p) ( (void)(p) )

#endif
