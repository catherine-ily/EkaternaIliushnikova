#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int return_code = OK, main_exit = 0;
  if (!result || s21_check_matrix(A)) {
    return_code = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    return_code = CALCULATION_ERROR;
  } else if (A->rows == 1) {
    *result = 0.0;
    *result = A->matrix[0][0];
    main_exit = 1;
  } else if (A->rows == 2) {
    *result = 0.0;
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
    main_exit = 1;
  } else {
    *result = 0.0;
  }

  if (return_code == OK && !main_exit) {
    int exit = 0;
    matrix_t minor = {0};
    if (s21_create_matrix(A->rows - 1, A->columns - 1, &minor) != OK) {
      return_code = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < A->rows && !exit; i++) {
        s21_get_minor(A, &minor, i, 0);
        double det_minor = 0.0;
        return_code = s21_determinant(&minor, &det_minor);
        if (return_code) {
          exit = 1;
        } else {
          *result += (pow(-1, i) * det_minor * A->matrix[i][0]);
        }
      }
      s21_remove_matrix(&minor);
    }
  }
  return return_code;
}
