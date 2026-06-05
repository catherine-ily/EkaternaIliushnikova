#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int return_code = OK;
  if (!result) {
    return_code = INCORRECT_MATRIX;
  } else if ((return_code = s21_check_matrix(A)) != OK ||
             (return_code = s21_check_matrix(B)) != OK) {
  } else if (A->columns != B->rows) {
    return_code = CALCULATION_ERROR;
  } else if ((return_code = s21_create_matrix(A->rows, B->columns, result)) !=
             OK) {
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0.0;
        for (int m = 0; m < A->columns; m++) {
          result->matrix[i][j] += A->matrix[i][m] * B->matrix[m][j];
        }
      }
    }
  }
  return return_code;
}
