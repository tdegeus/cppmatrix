/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_FIX_SYMMETRIC_MATRIX_H
#define CPPMAT_FIX_SYMMETRIC_MATRIX_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace tiny {
namespace symmetric {

// =================================================================================================
// cppmat::symmetric::matrix
// =================================================================================================

template<class X, size_t M, size_t N>
class matrix
{
  static_assert( N == M , "Must be square" );

protected:

  static const size_t mSize=(N+1)*N/2;  // total size == data.size()
  static const size_t mRank=2;          // rank (number of axes)
  X                   mData[(N+1)*N/2]; // data container

public:

  // return size without constructing
  static size_t Size();

  // constructor: allocate, don't initialize
  matrix();

  // constructor: copy
  matrix(const cppmat::tiny::symmetric::matrix<X,M,N> &A);
  matrix(const cppmat::tiny::diagonal ::matrix<X,M,N> &A);
  matrix(const cppmat::view::diagonal ::matrix<X,M,N> &A);
  matrix(const cppmat::      diagonal ::matrix<X>     &A);
  matrix(const cppmat::      symmetric::matrix<X>     &A);

  // named constructor: initialize
  static matrix<X,M,N> Random  (X lower=(X)0, X upper=(X)1);
  static matrix<X,M,N> Arange  ();
  static matrix<X,M,N> Zero    ();
  static matrix<X,M,N> Ones    ();
  static matrix<X,M,N> Constant(X D);

  // named constructor: copy
  static matrix<X,M,N> Copy(const std::vector<X> &D);

  // named constructor: copy
  template<typename Itr> static matrix<X,M,N> Copy     (Itr first);
  template<typename Itr> static matrix<X,M,N> Copy     (Itr first, Itr last);
  template<typename Itr> static matrix<X,M,N> CopyDense(Itr first);
  template<typename Itr> static matrix<X,M,N> CopyDense(Itr first, Itr last);

  // copy constructor
  operator cppmat::symmetric::matrix<X> () const;

  // return plain storage as vector
  std::vector<X> asVector() const;

  // get dimensions
  size_t size() const;
  size_t rank() const;
  size_t shape(int    i) const;
  size_t shape(size_t i) const;
  std::vector<size_t> shape() const;

  // index operators: access plain storage
  X&       operator[](size_t i);
  const X& operator[](size_t i) const;

  // index operators: access using matrix-indices
  X&       operator()(size_t a, size_t b);
  const X& operator()(size_t a, size_t b) const;

  // index operators: matrix-indices -> plain storage (a,b -> i)
  size_t compress(size_t a, size_t b) const;

  // index operators: plain storage -> matrix-indices (i -> a,b)
  std::vector<size_t> decompress(size_t i) const;

  // pointer to data
  X*       data();
  const X* data() const;

  // iterator to first and last entry
  auto begin();
  auto begin() const;
  auto end();
  auto end() const;

  // iterator to specific entry: access plain storage
  auto index(size_t i);
  auto index(size_t i) const;

  // iterator to specific entry: access using matrix-indices
  auto item(size_t a, size_t b);
  auto item(size_t a, size_t b) const;

  // initialization
  void setRandom(X lower=(X)0, X upper=(X)1);
  void setArange();
  void setZero();
  void setOnes();
  void setConstant(X D);
  template<typename Iterator> void setCopy     (Iterator first);
  template<typename Iterator> void setCopy     (Iterator first, Iterator last);
  template<typename Iterator> void setCopyDense(Iterator first);
  template<typename Iterator> void setCopyDense(Iterator first, Iterator last);

  // copy to target
  template<typename Iterator> void copyTo     (Iterator first) const;
  template<typename Iterator> void copyTo     (Iterator first, Iterator last) const;
  template<typename Iterator> void copyToDense(Iterator first) const;
  template<typename Iterator> void copyToDense(Iterator first, Iterator last) const;

  // sign change
  matrix<X,M,N> operator- () const;
  matrix<X,M,N> operator+ () const;

  // arithmetic operators
  matrix<X,M,N>& operator*= (const cppmat::tiny::symmetric::matrix<X,M,N> &B);
  matrix<X,M,N>& operator/= (const cppmat::tiny::symmetric::matrix<X,M,N> &B);
  matrix<X,M,N>& operator+= (const cppmat::tiny::symmetric::matrix<X,M,N> &B);
  matrix<X,M,N>& operator-= (const cppmat::tiny::symmetric::matrix<X,M,N> &B);
  matrix<X,M,N>& operator*= (const                                 X      &B);
  matrix<X,M,N>& operator/= (const                                 X      &B);
  matrix<X,M,N>& operator+= (const                                 X      &B);
  matrix<X,M,N>& operator-= (const                                 X      &B);

  // extra arithmetic operators
  matrix<X,M,N>& operator*= (const cppmat::tiny::diagonal ::matrix<X,M,N> &B);
  matrix<X,M,N>& operator+= (const cppmat::tiny::diagonal ::matrix<X,M,N> &B);
  matrix<X,M,N>& operator-= (const cppmat::tiny::diagonal ::matrix<X,M,N> &B);

  // absolute value
  matrix<X,M,N> abs() const;

  // norm (sum of absolute values)
  X norm() const;

  // return the indices that would sort the matrix
  cppmat::tiny::symmetric::matrix<size_t,M,N> argsort(bool ascending=true) const;

  // location of the minimum/maximum: plain storage (use decompress to convert to indices)
  size_t argmin() const;
  size_t argmax() const;

  // minimum
  X min() const;

  // maximum
  X max() const;

  // sum
  X sum() const;

  // mean
  double mean() const;

  // weighted average
  double average(const cppmat::tiny::symmetric::matrix<X,M,N> &weights, bool norm=true) const;

  // find the plain storage indices of all non-zero entries
  std::vector<size_t> where() const;

  // find the plain storage indices of all entries equal to some constant
  std::vector<size_t> where(X D) const;

};

// =================================================================================================
// external arithmetic operators (cppmat::tiny::symmetric)
// =================================================================================================

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator* (const matrix<X,M,N> &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator/ (const matrix<X,M,N> &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator+ (const matrix<X,M,N> &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator- (const matrix<X,M,N> &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator* (const matrix<X,M,N> &A, const X &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator/ (const matrix<X,M,N> &A, const X &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator+ (const matrix<X,M,N> &A, const X &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator- (const matrix<X,M,N> &A, const X &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator* (const X &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator/ (const X &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator+ (const X &A, const matrix<X,M,N> &B);

// -------------------------------------------------------------------------------------------------

template<class X, size_t M, size_t N>
inline
matrix<X,M,N> operator- (const X &A, const matrix<X,M,N> &B);

// =================================================================================================

}}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

