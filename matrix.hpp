#ifndef MATRIX_HPP
#define MATRIX_HPP

bool isEmpty(bool** m, int line, int col);
bool** generate_matrix(int l, int c);
void print_matrix(bool** m, int l, int c);
void delete_matrix(bool** m, int l, int c);

#include "matrix.impl.hpp"

#endif // MATRIX_HPP