#include "matrix_oop.h"

double& Matrix::operator()(int row, int col) {
    return matrix_[row][col];
}

const double& Matrix::operator()(int row, int col) const {
    return matrix_[row][col];
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) {
        return *this;
    }
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_];
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
    return *this;
}

Matrix::operator()(int i, int j) {

}

Matrix::operator()(int i, int j) const {
  
}

bool Matrix::operator==(const Matrix& other) const {
  return EqMatrix(other);  
}

Matrix Matrix::operator+(const Matrix& other) const {
  Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
  SumMatrix(other);
  return *this;
}

Matrix Matrix::operator-(const Matrix& other) const {
  Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

Matrix& Matrix::operator-=(const Matrix& other) {
  SubMatrix(other);
  return *this;
}

Matrix Matrix::operator*(const Matrix& other) const {
  Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

Matrix Matrix::operator*(double number) {
  Matrix result(*this);
  result.MulNumber(number);
  return result;
}

Matrix operator*(double number, const Matrix& matrix) {
  Matrix result = number * matrix;
  return result;
}

Matrix& Matrix::operator*=(const Matrix& other) {
  MulMatrix(other);
  return *this;
}

Matrix& Matrix::operator*=(double number) {
  MulNumber(number);
  return *this;
}

const double &Matrix::operator()(int row, int col) const & {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input for (), index is out of range.");
  }
  return matrix_[row * cols_ + col];
}
