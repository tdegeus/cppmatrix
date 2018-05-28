
#include "support.h"

static const size_t ND = 3;

typedef cppmat::tiny::cartesian::tensor4 <double,ND> T4;
typedef cppmat::tiny::cartesian::tensor2 <double,ND> T2;
typedef cppmat::tiny::cartesian::tensor2s<double,ND> T2s;
typedef cppmat::tiny::cartesian::tensor2d<double,ND> T2d;
typedef cppmat::tiny::cartesian::vector  <double,ND> V;

// =================================================================================================

TEST_CASE("cppmat::tiny::cartesian::tensor2d<3>", "var_cartesian_tensor2s.h")
{

// =================================================================================================
// unit tensors
// =================================================================================================

SECTION( "I, T2d.dot(T2)" )
{
  T2d I = T2d::I();
  T2  A = T2 ::Random();

  T2  B = I.dot(A);

  Equal(A, B);
}

// -------------------------------------------------------------------------------------------------

SECTION( "I, T2d.dot(T2s)" )
{
  T2d I = T2d::I();
  T2s A = T2s::Random();

  T2  B = I.dot(A);

  Equal(A, B);
}

// -------------------------------------------------------------------------------------------------

SECTION( "I, T2d.dot(T2d)" )
{
  T2d I = T2d::I();
  T2d A = T2d::Random();

  T2d B = I.dot(A);

  Equal(A, B);
}

// -------------------------------------------------------------------------------------------------

SECTION( "I, T2d.dot(V)" )
{
  T2d I = T2d::I();
  V   A = V  ::Random();

  V   B = I.dot(A);

  Equal(A, B);
}

// =================================================================================================
// tensor products
// =================================================================================================

SECTION( "I, T2d.dot(T4)" )
{
  T2d A = T2d::Random();
  T4  I = T4 ::I();

  T2  B = A.ddot(I);

  Equal(A, B);
}

// =================================================================================================
// tensor products
// =================================================================================================

SECTION( "T2d.ddot(T2), T2d.dot(T2), T2d.trace()" )
{
  T2d A = T2d::Random();
  T2  B = T2 ::Random();

  double C = A.ddot(B);

  double c = A.dot(B).trace();

  EQ(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "T2d.ddot(T2s), T2d.dot(T2s), T2d.trace()" )
{
  T2d A = T2d::Random();
  T2s B = T2s::Random();

  double C = A.ddot(B);

  double c = A.dot(B).trace();

  EQ(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "T2d.ddot(T2d), T2d.dot(T2d), T2d.trace()" )
{
  T2d A = T2d::Random();
  T2d B = T2d::Random();

  double C = A.ddot(B);

  double c = A.dot(B).trace();

  EQ(C, c);
}

// =================================================================================================
// tensor products
// =================================================================================================

SECTION( "T2d.dyadic(T2)" )
{
  T2d A = T2d::I();
  T2  B = T2 ::I();

  T4  C = A.dyadic(B);

  T4  D = T4::II();

  Equal(C, D);
}

// -------------------------------------------------------------------------------------------------

SECTION( "T2d.dyadic(T2s)" )
{
  T2d A = T2d::I();
  T2s B = T2s::I();

  T4  C = A.dyadic(B);

  T4  D = T4::II();

  Equal(C, D);
}

// -------------------------------------------------------------------------------------------------

SECTION( "T2d.dyadic(T2d)" )
{
  T2d A = T2d::I();
  T2d B = T2d::I();

  T4  C = A.dyadic(B);

  T4  D = T4::II();

  Equal(C, D);
}

// =================================================================================================
// transpositions
// =================================================================================================

SECTION( "T" )
{
  T2d A = T2d::Random();

  T2d B = A.T();

  for ( size_t i = 0 ; i < B.ndim() ; ++i )
    for ( size_t j = 0 ; j < B.ndim() ; ++j )
      EQ( B(i,j), A(j,i) );
}

// =================================================================================================
// determinant
// =================================================================================================

SECTION("T2d.det()")
{
  MatD   a = makeDiagonal(MatD::Random(3,3));
  double c = a.determinant();

  T2d    A = T2d::CopyDense(a.data(), a.data()+a.size());
  double C = A.det();

  EQ(C, c);
}

// =================================================================================================
// inverse
// =================================================================================================

SECTION("T2d.inv()")
{
  MatD a = makeDiagonal(MatD::Random(3,3));
  MatD c = a.inverse();

  T2d A = T2d::CopyDense(a.data(), a.data()+a.size());
  T2d C = A.inv();

  Equal(C, c);
}

// =================================================================================================

}
