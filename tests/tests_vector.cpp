#include "doctest/doctest.h"
#include "vector.hh"
#include "matrix.hh"
#include "equations.hh"

// Tests that don't naturally fit in the headers/.cpp files directly
// can be placed in a tests/*.cpp file. Integration tests are a good example.


TEST_CASE("Matrix Constructor")
{
  double arg1[][SIZE] = {2,4,7,1,9,3,2,0,4};
  Matrix temp = Matrix(arg1);

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      CHECK(temp(i,j) == arg1[i][j]);
    }
  }

}

TEST_CASE("test transpose")
{
  double arg1[][SIZE] = {2,4,7,1,9,3,2,0,4};
  Matrix temp = Matrix(arg1);

  temp.transpose();

  double arg2[][SIZE] = {2,1,2,4,9,0,7,3,4};
  Matrix correct = Matrix(arg2);

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < SIZE; j++){
      CHECK(temp(i,j) == correct(i,j));
    }
  }
}


TEST_CASE("test swap rows 1st with 3rd")
{
  double arg1[][SIZE] = {2,4,7,1,9,3,2,0,4};
  Matrix temp = Matrix(arg1);

  temp.transpose();

  double arg2[SIZE] = {7,3,4};
  Vector tmp = Vector(arg2);

  temp.column_swap(0, tmp);

  double arg3[][SIZE] = {7,3,4,4,9,0,2,1,1};
  Matrix correct = Matrix(arg3);

  for(int i = 0; i < SIZE; i++){
        CHECK(temp(0,i) == correct(0,i));
  }
}


TEST_CASE("calculating determinant using gauss")
{
  double arg[][SIZE] = {2,4,7,1,9,3,2,0,4};
  Matrix temp = Matrix(arg);
  CHECK( temp.detGauss() == (-46));
}


TEST_CASE("test wyznacnzika")
{
  double arg[][SIZE] = {9,8.5,8,2,2,3,1,1.5,1};
  Matrix temp = Matrix(arg);
  CHECK( temp.detGauss() == (-6));
}






