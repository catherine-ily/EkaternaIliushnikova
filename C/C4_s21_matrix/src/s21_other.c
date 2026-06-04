#include "s21_matrix.h"

void s21_check_two_and_create(matrix_t *A, matrix_t *B, matrix_t *result,
                              int *return_code) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL ||
      result == NULL) {
    *return_code = INCORRECT_MATRIX;
  } else if (A->rows != B->rows || A->columns != B->columns) {
    *return_code = CALCULATION_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result) != 0) {
    *return_code = INCORRECT_MATRIX;
  }
}

int s21_check_matrix(matrix_t *A) {
  int return_code = 0, exit = 0;
  if (!A || !A->matrix || A->rows <= 0 || A->columns <= 0) {
    return_code = INCORRECT_MATRIX;
  } else {
    for (int i = 0; i < A->rows && !exit; i++) {
      for (int j = 0; j < A->columns && !exit; j++) {
        if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
          return_code = CALCULATION_ERROR;
          exit = 1;
        }
      }
    }
  }
  return return_code;
}

void s21_get_minor(matrix_t *src, matrix_t *minor, int skip_row, int skip_col) {
  int row = 0, col = 0;
  for (int i = 0; i < src->rows; i++) {
    if (i != skip_row) {
      for (int j = 0; j < src->columns; j++) {
        if (j != skip_col) {
          minor->matrix[row][col] = src->matrix[i][j];
          col++;
        }
      }
      row++;
      col = 0;
    }
  }
}

void s21_fill_matrix(double input[], matrix_t *output) {
  int ind = 0;
  for (int i = 0; i < output->rows; ++i) {
    for (int j = 0; j < output->columns; ++j) {
      output->matrix[i][j] = input[ind++];
    }
  }
}
