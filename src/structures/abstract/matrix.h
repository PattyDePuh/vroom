#ifndef MATRIX_H
#define MATRIX_H

/* matrix.h

matrix is a virtual class, which is derived 
by content_matrix and sub_matrix_wrapper.
It promises the algorithms to access a matrix 
without the need to know who and how the matrix entries
are retrieved.

*/

#include "../typedefs.h"

template <class T>
class matrix_row{
public:
  virtual T operator[](index_t n);
  virtual std::size_t size();
};

template <class T>
class matrix{
public:
  virtual matrix_row<T> operator[](index_t n);
  virtual std::size_t size();
};

#endif