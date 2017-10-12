/* sub_matrix_wrapper.cpp


*/
#include "sub_matrix_wrapper.h"

template <class T>
line_wrapper<T>::line_wrapper(  
  matrix<T>* matrix,
  std::vector<index_t>* sub_indices,
  index_t row_index)  
  : _matrix(matrix),
  _sub_indices(sub_indices),
  _row_index(row_index) {}

template <class T>
std::size_t line_wrapper<T>::size() {
  return _sub_indices->size();
}

template <class T>
T line_wrapper<T>::operator[](index_t collumn_index) {
  return (*_matrix)[_row_index][(*_sub_indices)[collumn_index]];
}


template <class T>
sub_matrix_wrapper<T>::sub_matrix_wrapper(  
  matrix<T>* matrix, 
  std::vector<index_t> sub_indices) 
  : _matrix(matrix),
  _sub_indices(sub_indices) {
  for (index_t row_index : sub_indices) {
    _line_wrappers.emplace_back(_matrix, &_sub_indices, row_index);
  }
}

template <class T>
std::size_t sub_matrix_wrapper<T>::size() {
  return _sub_indices.size();
}

template <class T>
matrix_row<T> sub_matrix_wrapper<T>::operator[](index_t row_index) {
  return _line_wrappers[row_index];
}


template class line_wrapper<distance_t>;
template class sub_matrix_wrapper<distance_t>;
