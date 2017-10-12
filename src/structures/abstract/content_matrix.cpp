/*

This file is part of VROOM.

Copyright (c) 2015-2017, Julien Coupey.
All rights reserved (see LICENSE).

*/
#include "content_matrix.h"

template <class T>
content_line<T>::content_line(std::size_t n) :
  entries(n) {}

template <class T>
std::size_t content_line<T>::size() {
  return entries.size();
}

template <class T>
T content_line<T>::operator[](index_t row_index) {
  return entries[row_index];
}



template <class T>
content_matrix<T>::content_matrix(std::size_t n) : 
  rows(n) {}

template <class T>
content_matrix<T>::content_matrix() : rows(0) {}

template <class T>
std::size_t content_matrix<T>::size() {
  return rows.size();
}

template <class T>
matrix_row<T> content_matrix<T>::operator[](index_t row_index) {
  return rows[row_index];
}


template <class T>
sub_matrix_wrapper<T> content_matrix<T>::get_sub_matrix(const std::vector<index_t> indices) const {
  sub_matrix_wrapper<T> sub_matrix(this, indices);
  return sub_matrix;
}

template class matrix<distance_t>;