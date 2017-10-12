#ifndef CONTENT_MATRIX_H
#define CONTENT_MATRIX_H

/* content_matrix.h

matrix is a virtual class, which is derived 
by content_matrix and sub_matrix_wrapper.
It promises the algorithms to access a matrix 
without the need to know who and how the matrix entries
are retrieved.

*/

#include <vector>

#include "../typedefs.h"
#include "matrix.h"
#include "sub_matrix_wrapper.h"

template <class T>
class content_line : public matrix_row<T> {

  std::vector<T> entries;

public:
  std::size_t size();
  T operator[](index_t n);

  content_line(std::size_t n);
};

template <class T>
class content_matrix : public matrix<T> {

  std::vector<content_line<T>> rows;

public:
  std::size_t size();
  matrix_row<T> operator[](index_t n);

  content_matrix();

  content_matrix(std::size_t n);

  sub_matrix_wrapper<T> get_sub_matrix(const std::vector<index_t> indices) const;
};

#endif
