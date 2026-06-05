#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int return_code = OK;
  if (result == NULL || s21_check_matrix(A) != OK) {
    return_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    return_code = INCORRECT_MATRIX;
  } else if (A->rows == 1) {
    result->matrix[0][0] = 1.0;
  } else {
    for (int i = 0; i < A->rows && return_code == OK; i++) {
      for (int j = 0; j < A->columns && return_code == OK; j++) {
        double det = 0.0;
        matrix_t minor = {0};
        return_code = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        if (return_code != OK) {
          s21_remove_matrix(result);
        } else {
          s21_get_minor(A, &minor, i, j);
          return_code = s21_determinant(&minor, &det);
          s21_remove_matrix(&minor);
        }
        if (return_code == OK) {
          result->matrix[i][j] = pow(-1, i + j) * det;
        } else if (result->matrix != NULL) {
          s21_remove_matrix(result);
        }
      }
    }
  }
  return return_code;
}
