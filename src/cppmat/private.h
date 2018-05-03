/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_PRIVATE_H
#define CPPMAT_PRIVATE_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace Private {

// =================================================================================================

template<class X> std::vector<X> sort_axes(const std::vector<X> &A, X n, bool reverse=true);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif
