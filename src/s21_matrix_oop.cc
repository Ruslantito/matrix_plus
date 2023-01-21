#include "s21_matrix_oop.h"

using namespace std;

// Default constructor
S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

// Параметризированный конструктор с количеством строк и столбцов
S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ < 0 || cols_ < 0) {
    throw invalid_argument(
        "Incorect matrix, rows and cols should be equal or more then 0");
  } else if (rows_ == 0 || cols_ == 0) {
    matrix_ = nullptr;
  } else {
    matrix_ = new double[rows_ * cols_]{0};
  }
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix &other)
    : rows_(other.rows_), cols_(other.cols_) {
  if (rows_ == 0 || cols_ == 0) {
    matrix_ = nullptr;
  } else {
    matrix_ = new double[rows_ * cols_]{0};
    copy(other.matrix_, other.matrix_ + (other.rows_ * other.cols_), matrix_);
  }
}

// Конструктор переноса
S21Matrix::S21Matrix(S21Matrix &&other) noexcept {
  *this = forward<S21Matrix>(other);
  other.rows_ = 0;
  other.cols_ = 0;

  other.ResetMatrix();
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) {
  if (this == &other) {
    return *this;
  }
  S21Matrix temp_matrix(other.rows_, other.cols_);
  for (auto i = 0; i < other.rows_; i++) {
    for (auto j = 0; j < other.cols_; j++) {
      temp_matrix(i, j) = other(i, j);
    }
  }
  ResetMatrix();
  *this = move(temp_matrix);
  return *this;
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  swap(rows_, other.rows_);
  swap(cols_, other.cols_);
  swap(matrix_, other.matrix_);

  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
  return *this;
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return *this;
}

S21Matrix &S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

// Destructor
S21Matrix::~S21Matrix() noexcept { ResetMatrix(); }

// Getters(accessors) / setters(mutators)
void S21Matrix::set_rows(const int &rows) {
  if (rows < 0) {
    throw invalid_argument(
        "Incorect size of matrix, rows should be equal or more then 0");
  } else if (rows == 0) {
    rows_ = 0;
    cols_ = 0;
    ResetMatrix();
  } else if (rows != rows_) {
    S21Matrix temp_matrix(rows, cols_);

    if (cols_ != 0) {
      for (auto i = 0; i < min(rows, rows_); i++) {
        for (auto j = 0; j < cols_; j++) {
          temp_matrix(i, j) = (*this)(i, j);
        }
      }
      ResetMatrix();
    }

    *this = move(temp_matrix);
  }
}

int S21Matrix::get_rows() const noexcept { return rows_; }

void S21Matrix::set_cols(const int &cols) {
  if (cols < 0) {
    throw invalid_argument(
        "Incorect size of matrix, cols should be equal or more then 0");
  }
  if (cols == 0) {
    rows_ = 0;
    cols_ = 0;
    ResetMatrix();
  } else if (cols != cols_) {
    S21Matrix temp_matrix(rows_, cols);

    if (rows_ != 0) {
      for (auto i = 0; i < rows_; i++) {
        for (auto j = 0; j < min(cols, cols_); j++) {
          temp_matrix(i, j) = (*this)(i, j);
        }
      }
      ResetMatrix();
    }

    *this = move(temp_matrix);
  }
}

int S21Matrix::get_cols() const noexcept { return cols_; }

// Methods...
bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (other.cols_ <= 0 || other.rows_ <= 0 || other.cols_ != cols_ ||
      other.rows_ != rows_ || cols_ <= 0 || rows_ <= 0) {
    return false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (abs((*this)(i, j) - other(i, j)) >= kS21_EPS) {
          return false;
        }
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  // Исключительные ситуации:
  // различная размерность матриц
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw invalid_argument("Incorrect matrix, the size should be same");
  } else {
    for (auto i = 0; i < rows_; i++) {
      for (auto j = 0; j < cols_; j++) {
        (*this)(i, j) += other(i, j);
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  // Исключительные ситуации:
  // различная размерность матриц
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw invalid_argument("Incorrect matrix, the size should be same");
  } else {
    for (auto i = 0; i < rows_; i++) {
      for (auto j = 0; j < cols_; j++) {
        (*this)(i, j) -= other(i, j);
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (num != num) {
    throw invalid_argument("Incorrect input, num not present");
  } else {
    for (auto i = 0; i < rows_; i++) {
      for (auto j = 0; j < cols_; j++) {
        (*this)(i, j) *= num;
      }
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  // Исключительные ситуации:
  // число столбцов первой матрицы не равно числу строк второй матрицы
  if (cols_ != other.rows_) {
    throw invalid_argument(
        "Incorrect matrix, the size of cols of first and rows of secont should "
        "be same");
  } else {
    S21Matrix temp_matrix(*this);
    set_cols(other.cols_);

    for (auto i = 0; i < rows_; i++) {
      for (auto j = 0; j < cols_; j++) {
        (*this)(i, j) = 0;
        for (int j_a = 0, i_b = 0; j_a < temp_matrix.cols_ && i_b < other.rows_;
             j_a++, i_b++) {
          (*this)(i, j) += temp_matrix(i, j_a) * other(i_b, j);
        }
      }
    }
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix final_matrix(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      final_matrix(i, j) = (*this)(j, i);
    }
  }
  return final_matrix;
}

S21Matrix S21Matrix::CalcComplements() const {
  // Исключительные ситуации:
  // матрица не является квадратной
  if (rows_ != cols_) {
    throw invalid_argument(
        "Incorrect matrix, the size of rows and cols should be same");
  }
  S21Matrix final_matrix(rows_, cols_);
  if (rows_ > 1) {
    double sign;
    for (auto i = 0; i < rows_; i++) {
      for (auto j = 0; j < cols_; j++) {
        S21Matrix final_matrix_ReduceMatrix = ReduceMatrix(i, j);
        double det = final_matrix_ReduceMatrix.Determinant();
        sign = pow(-1.0, i + j) < 0 ? -1.0 : 1.0;
        final_matrix(i, j) = sign * det;
      }
    }
  } else {
    final_matrix(0, 0) = 1;
  }
  return final_matrix;
}

double S21Matrix::Determinant() const {
  // Исключительные ситуации:
  // матрица не является квадратной
  double res = 0.0;
  S21Matrix res_tmp(*this);

  if (rows_ <= 0 || rows_ != cols_) {
    throw invalid_argument(
        "Incorrect matrix, the size of rows and cols should be same");
  }
  if (rows_ == 1) {
    res = res_tmp(0, 0);
  } else if (rows_ == 2) {
    res = res_tmp(0, 0) * res_tmp(1, 1) - res_tmp(0, 1) * res_tmp(1, 0);
  } else {
    double sign;
    for (auto i = 0; i < 1; i++) {
      for (auto j = 0; j < cols_; j++) {
        S21Matrix temp_matrix_ReduceMatrix = ReduceMatrix(i, j);
        double det = temp_matrix_ReduceMatrix.Determinant();
        sign = pow(-1.0, i + j) < 0 ? -1.0 : 1.0;
        res += sign * res_tmp(0, j) * det;
      }
    }
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() const {
  // Исключительные ситуации:
  // определитель матрицы равен 0
  if (rows_ != cols_) {
    throw invalid_argument(
        "Incorrect matrix, the size of rows and cols should be same");
  }
  double det = Determinant();
  if ((det < kS21_EPS) && (det > -kS21_EPS)) {
    throw invalid_argument("Can't find inverse matrix while determinant == 0");
  }
  if (rows_ == 1) {
    S21Matrix final_matrix(rows_, cols_);
    final_matrix(0, 0) = 1.0 / (*this)(0, 0);
    return final_matrix;
  } else {
    double det_inverse = 1.0 / Determinant();
    S21Matrix final_matrix = CalcComplements().Transpose();
    final_matrix.MulNumber(det_inverse);
    return final_matrix;
  }
}

S21Matrix S21Matrix::ReduceMatrix(const int rows, const int col) const {
  if ((rows_ != cols_) || (rows_ <= 0) || (rows > rows_)) {
    throw out_of_range(
        "Incorrect matrix, the size of rows and cols should be same");
  }
  S21Matrix final_matrix(rows_ - 1, cols_ - 1);
  int l = -1, c = -1;
  for (int i = 0; i < (*this).rows_; i++) {
    if (i == rows) {
      continue;
    }
    l++;
    c = -1;
    for (int j = 0; j < (*this).cols_; j++) {
      if (j == col) {
        continue;
      }
      c++;
      final_matrix(l, c) = (*this)(i, j);
    }
  }
  return final_matrix;
}

// Operators
S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix final_matrix = *this;
  final_matrix.SumMatrix(other);
  return final_matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix final_matrix = *this;
  final_matrix.SubMatrix(other);
  return final_matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix final_matrix = *this;
  final_matrix.MulMatrix(other);
  return final_matrix;
}

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix final_matrix = *this;
  final_matrix.MulNumber(num);
  return final_matrix;
}

S21Matrix operator*(const double num, const S21Matrix &other) {
  S21Matrix final_matrix(other);
  final_matrix.MulNumber(num);
  return final_matrix;
}

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

double &S21Matrix::operator()(const int row, const int col) {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

const double &S21Matrix::operator()(const int row, const int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

void S21Matrix::ResetMatrix() noexcept {
  delete[] matrix_;
  matrix_ = nullptr;
}
