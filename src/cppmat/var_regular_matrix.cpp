/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VAR_REGULAR_MATRIX_CPP
#define CPPMAT_VAR_REGULAR_MATRIX_CPP

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {

// =================================================================================================
// constructors
// =================================================================================================

template<class X>
inline
matrix<X>::matrix(size_t m, size_t n) : cppmat::array<X>({m,n})
{
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X>::matrix(const cppmat::array<X> &A) : cppmat::array<X>(A)
{
  assert( this->mRank == 2 );
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X>::matrix(const cppmat::symmetric::matrix<X> &A) : cppmat::array<X>({A.shape(0),A.shape(1)})
{
  for ( size_t i = 0 ; i < A.shape(0) ; ++i )
    for ( size_t j = 0 ; j < A.shape(1) ; ++j )
      (*this)(i,j) = A(i,j);
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X>::matrix(const cppmat::diagonal::matrix<X> &A) : cppmat::array<X>({A.shape(0),A.shape(1)})
{
  for ( size_t i = 0 ; i < A.shape(0) ; ++i )
    for ( size_t j = 0 ; j < A.shape(1) ; ++j )
      (*this)(i,j) = A(i,j);
}

// =================================================================================================
// named constructors
// =================================================================================================

template<class X>
inline
matrix<X> matrix<X>::Random(size_t m, size_t n, X lower, X upper)
{
  matrix<X> out(m,n);

  out.setRandom(lower, upper);

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X> matrix<X>::Arange(size_t m, size_t n)
{
  matrix<X> out(m,n);

  out.setArange();

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X> matrix<X>::Zero(size_t m, size_t n)
{
  matrix<X> out(m,n);

  out.setZero();

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X> matrix<X>::Ones(size_t m, size_t n)
{
  matrix<X> out(m,n);

  out.setOnes();

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X> matrix<X>::Constant(size_t m, size_t n, X D)
{
  matrix<X> out(m,n);

  out.setConstant(D);

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
matrix<X> matrix<X>::Copy(size_t m, size_t n, const std::vector<X> &D)
{
  matrix<X> out(m,n);

  out.setCopy(D.begin(), D.end());

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
template<typename Iterator>
inline
matrix<X> matrix<X>::Copy(size_t m, size_t n, Iterator first)
{
  matrix<X> out(m,n);

  out.setCopy(first);

  return out;
}

// -------------------------------------------------------------------------------------------------

template<class X>
template<typename Iterator>
inline
matrix<X> matrix<X>::Copy(size_t m, size_t n, Iterator first, Iterator last)
{
  matrix<X> out(m,n);

  out.setCopy(first,last);

  return out;
}

// =================================================================================================
// resize
// =================================================================================================

template<class X>
inline
void matrix<X>::resize(size_t m, size_t n)
{
  cppmat::array<X>::resize({m,n});
}

// -------------------------------------------------------------------------------------------------

template<class X>
inline
void matrix<X>::reshape(size_t m, size_t n)
{
  cppmat::array<X>::reshape({m,n});
}

// =================================================================================================

} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

