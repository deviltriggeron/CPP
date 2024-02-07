# CPP

Matrix - Реализация работы с матрицами

## Matrix

- Реализация работы с матрицами созданный класс, с методами и операторами 
bool EqMatrix(const S21Matrix& other)
Проверяет матрицы на равенство между собой.   
void SumMatrix(const S21Matrix& other)
Прибавляет вторую матрицы к текущей     
void SubMatrix(const S21Matrix& other)
Вычитает из текущей матрицы другую   
void MulNumber(const double num)
Умножает текущую матрицу на число.   
void MulMatrix(const S21Matrix& other)
Умножает текущую матрицу на вторую.    
S21Matrix Transpose()
Создает новую транспонированную матрицу из текущей и возвращает ее.
S21Matrix CalcComplements()
Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее.    
double Determinant()
Вычисляет и возвращает определитель текущей матрицы.    
S21Matrix InverseMatrix()
Вычисляет и возвращает обратную матрицу.  