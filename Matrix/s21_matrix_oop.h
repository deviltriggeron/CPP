#ifndef MATRIX_OOP
#define MATRIX_OOP

#include <iostream>
#include <cstring>
#include <cmath>

class Matrix {
    private:
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated
        const double EPS = 1e-7;   // EPS
        Matrix determinant_m(const int minor_row, const int minor_col) const;

    public:
        Matrix();              // Default constructor
        Matrix(int rows, int cols);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other);
        ~Matrix();             // Destructor

        double& operator()(int row, int col);
        const double& operator()(int row, int col) const;
        int operator()(int i, int j);
        int operator()(int i, int j) const;
        Matrix& operator=(const Matrix& other);
        bool operator==(const Matrix& other) const;
        Matrix operator+(const Matrix& other) const;
        Matrix& operator+=(const Matrix& other);
        Matrix operator-(const Matrix& other) const;
        Matrix& operator-=(const Matrix& other);
        Matrix operator*(const Matrix& other) const;
        Matrix operator*(double number);
        friend Matrix operator*(double number, const Matrix& matrix);
        Matrix& operator*=(const Matrix& other);
        Matrix& operator*=(double number);
        const double operator()(int row, int col) const &;
        

        void swapRows(int row1, int row2);
        int getCols();          // Acessor
        int getRows();
        void setRows(int new_rows); // Mutator
        void setCols(int new_cols);

        bool EqMatrix(const Matrix& other) const;
        void SumMatrix(const Matrix& other); 
        void SubMatrix(const Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const Matrix& other);
        Matrix Transpose();
        Matrix CalcComplements();
        double Determinant();
        Matrix InverseMatrix();
};

#endif
