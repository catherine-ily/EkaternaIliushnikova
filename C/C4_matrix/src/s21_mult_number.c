#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int return_code = OK;
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return_code = INCORRECT_MATRIX;
  } else if (isnan(number) || isinf(number) ||
             s21_create_matrix(A->rows, A->columns, result) != OK) {
    return_code = CALCULATION_ERROR;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return return_code;
}
