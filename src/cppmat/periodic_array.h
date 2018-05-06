/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_PERIODIC_ARRAY_H
#define CPPMAT_PERIODIC_ARRAY_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace periodic {

// =================================================================================================
// cppmat::array
// =================================================================================================

template<class X>
class array
{
private:

  static const size_t MAX_DIM=6;    // maximum number of dimensions
  std::vector<X> mData;             // data container
  size_t         mNdim=0;           // actual number of dimensions
  size_t         mSize=0;           // total size == data.size() == prod(shape)
  size_t         mShape[MAX_DIM];   // number of entries in each dimensions
  int            mShapeI[MAX_DIM];  // == mShape, but with int's
  size_t         mStrides[MAX_DIM]; // stride length for each index

public:

  // constructor
  array() = default;
  array(const std::vector<size_t> &shape);

  // constructor: initialize
  static array<X> Arange  (const std::vector<size_t> &shape);
  static array<X> Zero    (const std::vector<size_t> &shape);
  static array<X> Ones    (const std::vector<size_t> &shape);
  static array<X> Constant(const std::vector<size_t> &shape, X D);

  // constructor: initialize by copying from external object
  template<typename Iterator>
  static array<X> Copy(const std::vector<size_t> &shape, Iterator first, Iterator last);

  // resize
  void resize (const std::vector<size_t> &shape);
  void reshape(const std::vector<size_t> &shape);
  void chdim  (size_t ndim);

  // get dimensions
  size_t size() const;
  size_t ndim() const;
  size_t shape(int    i) const;
  size_t shape(size_t i) const;
  std::vector<size_t> shape() const;
  std::vector<size_t> strides(bool bytes=false) const;

  // index operators: access plain storage
  X&       operator[](size_t i);
  const X& operator[](size_t i) const;

  // index operators: access using array-indices
  X&       operator()(int a);
  const X& operator()(int a) const;
  X&       operator()(int a, int b);
  const X& operator()(int a, int b) const;
  X&       operator()(int a, int b, int c);
  const X& operator()(int a, int b, int c) const;
  X&       operator()(int a, int b, int c, int d);
  const X& operator()(int a, int b, int c, int d) const;
  X&       operator()(int a, int b, int c, int d, int e);
  const X& operator()(int a, int b, int c, int d, int e) const;
  X&       operator()(int a, int b, int c, int d, int e, int f);
  const X& operator()(int a, int b, int c, int d, int e, int f) const;

  // index operators: access using iterator
  // N.B. the iterator points to list of array-indices (a,b,c,...)
  template<class Iterator> X&       at(Iterator first, Iterator last);
  template<class Iterator> const X& at(Iterator first, Iterator last) const;

  // index operators: plain storage -> array-indices (i -> a,b,c,...)
  std::vector<size_t> decompress(size_t i) const;

  // index operators: array-indices -> plain storage (a,b,c,... -> i)
  size_t compress(int a) const;
  size_t compress(int a, int b) const;
  size_t compress(int a, int b, int c) const;
  size_t compress(int a, int b, int c, int d) const;
  size_t compress(int a, int b, int c, int d, int e) const;
  size_t compress(int a, int b, int c, int d, int e, int f) const;

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

  // iterator to specific entry: access using array-indices
  auto item(int a);
  auto item(int a) const;
  auto item(int a, int b);
  auto item(int a, int b) const;
  auto item(int a, int b, int c);
  auto item(int a, int b, int c) const;
  auto item(int a, int b, int c, int d);
  auto item(int a, int b, int c, int d) const;
  auto item(int a, int b, int c, int d, int e);
  auto item(int a, int b, int c, int d, int e) const;
  auto item(int a, int b, int c, int d, int e, int f);
  auto item(int a, int b, int c, int d, int e, int f) const;

  // basic initialization
  void setArange();
  void setZero();
  void setOnes();
  void setConstant(X D);
  template<typename Iterator> void setCopy(Iterator first, Iterator last);

  // arithmetic operators
  array<X>& operator*= (const array<X> &B);
  array<X>& operator/= (const array<X> &B);
  array<X>& operator+= (const array<X> &B);
  array<X>& operator-= (const array<X> &B);
  array<X>& operator*= (const       X  &B);
  array<X>& operator/= (const       X  &B);
  array<X>& operator+= (const       X  &B);
  array<X>& operator-= (const       X  &B);

  // basic algebra
  // - absolute value
  void abs();
  // - location of the minimum/maximum
  std::vector<size_t> argmin() const;
  std::vector<size_t> argmax() const;
  // - location of the minimum/maximum
  size_t argminIndex() const;
  size_t argmaxIndex() const;
  // - minimum
  X        minCoeff() const;
  array<X> minCoeff(int    axis) const;
  array<X> minCoeff(size_t axis) const;
  array<X> minCoeff(const std::vector<int> &axes) const;
  // - maximum
  X        maxCoeff() const;
  array<X> maxCoeff(int    axis) const;
  array<X> maxCoeff(size_t axis) const;
  array<X> maxCoeff(const std::vector<int> &axes) const;
  // - sum
  X        sum() const;
  array<X> sum(int    axis) const;
  array<X> sum(size_t axis) const;
  array<X> sum(const std::vector<int> &axes) const;
  // - mean
  double   mean() const;
  array<X> mean(int    axis) const;
  array<X> mean(size_t axis) const;
  array<X> mean(const std::vector<int> &axes) const;
  // - weighted average
  double   average(const array<X> &weights,                               bool norm=true) const;
  array<X> average(const array<X> &weights, int    axis,                  bool norm=true) const;
  array<X> average(const array<X> &weights, size_t axis,                  bool norm=true) const;
  array<X> average(const array<X> &weights, const std::vector<int> &axes, bool norm=true) const;

  // formatted print; NB also "operator<<" is defined
  void printf(std::string fmt) const;

};

// arithmetic operators
template<class X> inline array<X> operator* (const array<X> &A, const array<X> &B);
template<class X> inline array<X> operator/ (const array<X> &A, const array<X> &B);
template<class X> inline array<X> operator+ (const array<X> &A, const array<X> &B);
template<class X> inline array<X> operator- (const array<X> &A, const array<X> &B);
template<class X> inline array<X> operator* (const array<X> &A, const       X  &B);
template<class X> inline array<X> operator/ (const array<X> &A, const       X  &B);
template<class X> inline array<X> operator+ (const array<X> &A, const       X  &B);
template<class X> inline array<X> operator- (const array<X> &A, const       X  &B);
template<class X> inline array<X> operator* (const       X  &A, const array<X> &B);
template<class X> inline array<X> operator/ (const       X  &A, const array<X> &B);
template<class X> inline array<X> operator+ (const       X  &A, const array<X> &B);
template<class X> inline array<X> operator- (const       X  &A, const array<X> &B);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

