#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int return_code = OK;

  if (s21_check_matrix(A) != OK || result == NULL) {
    return_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR;
  } else if (!result) {
    return_code = INCORRECT_MATRIX;
  } else {
    double det = 0.0, temp = 0.0;
    return_code = s21_determinant(A, &det);
    if (return_code == OK) {
      if (fabs(det) < ACCURACY) {
        return_code = CALCULATION_ERROR;
      } else if (A->rows == 1) {
        return_code = s21_create_matrix(A->rows, A->rows, result);
        if (return_code == OK) {
          result->matrix[0][0] = 1.0 / det;
        }
      } else {
        matrix_t calc_mat = {0}, trans = {0};
        return_code = s21_calc_complements(A, &calc_mat);
        if (return_code == OK) {
          return_code = s21_transpose(&calc_mat, &trans);
        }
        if (return_code == OK) {
          temp = 1 / det;
          return_code = s21_mult_number(&trans, temp, result);
        }
        s21_remove_matrix(&calc_mat);
        s21_remove_matrix(&trans);
      }
    }
  }
  return return_code;
}
