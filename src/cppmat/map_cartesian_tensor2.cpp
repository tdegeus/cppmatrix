/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_MAP_CARTESIAN_TENSOR2_CPP
#define CPPMAT_MAP_CARTESIAN_TENSOR2_CPP

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace view {
namespace cartesian {

// =================================================================================================
// constructors
// =================================================================================================

template<class X, size_t ND>
inline
tensor2<X,ND>::tensor2() : cppmat::view::matrix<X,ND,ND>()
{
}

// =================================================================================================
// constructors: map external pointer
// =================================================================================================

template<class X, size_t ND>
inline
tensor2<X,ND>::tensor2(const X *A) : cppmat::view::matrix<X,ND,ND>(A)
{
}

// =================================================================================================
// named constructors
// =================================================================================================

template<class X, size_t ND>
inline
tensor2<X,ND> tensor2<X,ND>::Map(const X *D)
{
  tensor2<X,ND> out;

  out.setMap(D);

  return out;
}

// =================================================================================================
// dimensions
// =================================================================================================

template<class X, size_t ND>
inline
size_t tensor2<X,ND>::ndim() const
{
  return ND;
}

// =================================================================================================

}}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

