#ifndef SUB_MATRIX_WRAPPER_H
#define SUB_MATRIX_WRAPPER_H

/* sub_matrix_wrapper.h

The sub_matrix_wrapper is created from an excisting matrix, 
where for certain sub-problems only a few entries are necessary. 

Ther line_wrapper gets the address for the matrix 
and the useable indices from his parent wrapper.
*/

#include <vector>

#include "../typedefs.h"
#include "matrix.h"


template <class T>
class line_wrapper : public matrix_row<T> {
private:  
  matrix<T>* _matrix;
  std::vector<index_t>* _sub_indices;
  index_t _row_index;
public:
  line_wrapper(matrix<T>* matrix,
        std::vector<index_t>* sub_indices,
        index_t row_index);

  std::size_t size();
  T operator[](index_t collumn_index);
};


template <class T>
class sub_matrix_wrapper : public matrix<T> {
private:
  std::vector<line_wrapper<T>> _line_wrappers;
  matrix<T>* _matrix;
  std::vector<index_t> _sub_indices;

public:
  sub_matrix_wrapper(matrix<T>* matrix, 
        std::vector<index_t> sub_indices);

  std::size_t size();
  matrix_row<T> operator[](index_t collumn_index);
};

#endif