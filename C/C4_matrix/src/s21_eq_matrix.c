#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;

  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    result = FAILURE;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    result = FAILURE;
  } else {
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns && result == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > ACCURACY) {
          result = FAILURE;
        }
      }
    }
  }
  return result;
}
