#include "matrix_oop.h"

bool Matrix::EqMatrix(const Matrix &other) const {
    bool res = true;
    if(rows_ != other.rows_ || cols_ != other.cols_) {
        return false;
    }
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            if(std::abs(other(i, j) - (*this)(i, j)) > EPS) {
                res = false;
            }
        }
    }
    return res;
}

void Matrix::SumMatrix(const Matrix& other) {
    if(rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::logic_error("different dimensions of matrix.");
    }
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            (*this)(i, j) += other(i, j);
        }
    }
}

void Matrix::SubMatrix(const Matrix& other) {
    if(rows_ != other.rows_ || cols_ != other.cols_) {
        throw std::logic_error("different dimensions of matrix.");
    }
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            (*this)(i, j) -= other(i, j);
        }
    }
}

void Matrix::MulNumber(const double num) {
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            (*this)(i, j) *= num;
        }
    }
}

void Matrix::MulMatrix(const Matrix& other) {
    if(rows_ != other.cols_ || cols_ != other.rows_) {
        throw std::logic_error("the number of columns of the first matrix is not equal to the value of the second row of the matrix.");
    }
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            (*this)(i, j) *= other(i, j);
        }
    }
}

Matrix Matrix::Transpose() {
    Matrix result(cols_, rows_);
    for(int i = 0; i < rows_; i++) {
        for(int j = 0; j < cols_; j++) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}

Matrix Matrix::CalcComplements() {
    if(rows_ != cols_) {
        throw std::logic_error("The matrix is not square.");
    }
    Matrix result (rows_, cols_);
    for(int i = 0; i < getRows(); i++) {
        for(int j = 0; j < getCols(); j++) {
            Matrix determinant_matrix = determinant_m(i, j);
            result(i, j) = determinant_matrix.Determinant();
            if ((i + j) % 2 != 0) {
                result(i, j) = -result(i, j);
            }
        }
    }
    return result;
}

double Matrix::Determinant() {
    if(rows_ != cols_) {
        throw std::logic_error("The matrix is not square.");
    }
    double result = 1.0;
    Matrix tmp(*this);
    int size = rows_;

    for (int i = 0; i < size; ++i) {
        int index = i;
        for (int j = i + 1; j < size; ++j) {
        if (std::abs(tmp(j, i)) > std::abs(tmp(index, i))) {
            index = j;
        }
    }

    if (std::abs(tmp(index, i)) < EPS) {
      return 0.0;
    }

    tmp.swapRows(i, index);

    result *= tmp(i, i);

    if (i != index) {
      result = -result;
    }

    for (int j = i + 1; j < size; ++j) {
      double coefficient = tmp(j, i) / tmp(i, i);
      for (int k = i; k < size; ++k) {
        tmp(j, k) -= tmp(i, k) * coefficient;
      }
    }
  }

  return result;
}

Matrix Matrix::InverseMatrix() {
    if(rows_ != cols_) {
        throw std::logic_error("The determinant of the matrix is 0.");
    }
    double det = Determinant();

    if (std::abs(det) < EPS) {
        throw std::logic_error("Determinant must be non-zero to calculate Inverse");
    }

    return Transpose().CalcComplements() * (1.0 / det);
}

int main() {
    Matrix matrix1(3, 3);
    Matrix matrix2(3, 3);
    Matrix result(3, 3);
    double number = 3;
    matrix1(0, 0) = 5;
    matrix2(0, 0) = 0;
    matrix1(1, 0) = 4;
    matrix2(1, 0) = 0;
    matrix1(2, 0) = 6;
    matrix2(2, 0) = 8;
    matrix1(2, 1) = 10;
    matrix2(2, 1) = 11;
    matrix1(0, 1) = 9;
    matrix2(0, 1) = 0;
    matrix1(0, 2) = 1;
    matrix2(0, 2) = 2;
    matrix1(1, 1) = 6;
    matrix2(1, 1) = 0;
    matrix1(1, 2) = 16;
    matrix2(1, 2) = 28;
    matrix1(2, 2) = 7;
    matrix2(2, 2) = 5;

    for(int i = 0; i < matrix1.getRows(); i++) {
        for(int j = 0; j < matrix1.getCols(); j++) {
            std::cout << matrix1(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    result = matrix1.Transpose();
    for(int i = 0; i < result.getRows(); i++) {
        for(int j = 0; j < result.getCols(); j++) {
            std::cout << result(i, j) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
