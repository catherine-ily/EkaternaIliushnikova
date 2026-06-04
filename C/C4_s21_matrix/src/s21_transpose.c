#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int return_code = OK;
  if ((return_code = s21_check_matrix(A)) == OK) {
    return_code = s21_create_matrix(A->columns, A->rows, result);
  }
  if (return_code == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return return_code;
}
