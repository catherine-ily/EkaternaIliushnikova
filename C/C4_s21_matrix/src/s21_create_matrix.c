#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int return_code = OK;

  if (rows <= 0 || columns <= 0 || result == NULL) {
    return_code = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    // if (result->matrix == NULL) {
    //   return_code = INCORRECT_MATRIX;
    // } else {
    int exit = 0;
    for (int i = 0; i < rows && !exit; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        return_code = INCORRECT_MATRIX;
        exit = 1;
      }
    }
    //}
  }

  return return_code;
}
