/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_FIX_MISC_MATRIX_H
#define CPPMAT_FIX_MISC_MATRIX_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// =================================================================================================
// extra external arithmetic operators -> cppmat::tiny::matrix
// =================================================================================================

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator* (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator/ (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator+ (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator- (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator+ (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator- (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator* (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator/ (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator+ (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator- (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator+ (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::matrix<X,M,N> operator- (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

// =================================================================================================
// extra external arithmetic operators -> cppmat::tiny::symmetric::matrix
// =================================================================================================

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator+ (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator- (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator+ (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const X &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator- (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const X &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator+ (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator- (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator+ (
  const X &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::symmetric::matrix<X,M,N> operator- (
  const X &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

// =================================================================================================
// extra external arithmetic operators -> cppmat::tiny::diagonal::matrix
// =================================================================================================

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator* (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator/ (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator* (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator/ (
  const cppmat::tiny::diagonal::matrix<X,M,N> &A,
  const cppmat::tiny::symmetric::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator* (
  const cppmat::tiny::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

template<typename X, size_t M, size_t N>
cppmat::tiny::diagonal::matrix<X,M,N> operator* (
  const cppmat::tiny::symmetric::matrix<X,M,N> &A,
  const cppmat::tiny::diagonal::matrix<X,M,N> &B
);

// =================================================================================================

#endif

