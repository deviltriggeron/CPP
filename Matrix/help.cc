#include "matrix_oop.h"

Matrix::Matrix() {
    rows_ = 3;
    cols_ = 3;
    matrix_ = new double[rows_ * cols_]();
}

Matrix::Matrix(int rows, int cols) : rows_(rows), cols_(cols), matrix_(nullptr) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
    }
}

Matrix::Matrix(const Matrix& o) : rows_(o.rows_), cols_(o.cols_), matrix_(nullptr) {
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = o.matrix_[i][j];
        }
    }
}

Matrix::Matrix(Matrix&& o) : rows_(o.rows_), cols_(o.cols_), matrix_(o.matrix_) {
    o.rows_ = 0;
    o.cols_ = 0;
    o.matrix_ = nullptr;
}

Matrix::~Matrix() {
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
}

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

int Matrix::getRows() { return rows_; }

int Matrix::getCols() { return cols_; }

void Matrix::setRows(int new_rows) {
  if (new_rows < 0) {
    throw std::length_error("matrix rows count must be non-negative");
  }

  if (new_rows != rows_) {
    Matrix tmp{new_rows, cols_};
    int min = std::min(rows_, new_rows);
    for (int i = 0; i < min; ++i) {
      for (int j = 0; j < cols_; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

void Matrix::setCols(int new_cols) {
  if (new_cols < 0) {
    throw std::length_error("matrix columns count must be non-negative");
  }

  if (new_cols != cols_) {
    Matrix tmp{rows_, new_cols};
    int min = std::min(cols_, new_cols);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < min; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

Matrix Matrix::determinant_m(const int minor_row, const int minor_col) const {
  Matrix result{rows_ - 1, cols_ - 1};
  int shift_i = 0;
  for (int i = 0; i < result.getRows(); ++i) {
    if (i == minor_row) {
      shift_i = 1;
    }
    int shift_j = 0;
    for (int j = 0; j < result.getCols(); ++j) {
      if (j == minor_col) {
        shift_j = 1;
      }
      result(i, j) = (*this)(i + shift_i, j + shift_j);
    }
  }
  return result;
}

void Matrix::swapRows(int row1, int row2) {
  if (row1 != row2) {
    for (int i = 0; i < cols_; ++i) {
      std::swap((*this)(row1, i), (*this)(row2, i));
    }
  }
}
