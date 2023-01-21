#ifndef CPP1_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <stdexcept>

static const double kS21_EPS = 1e-7;

class S21Matrix {
public:
  S21Matrix() noexcept; // Default constructor
  S21Matrix(int rows, int cols); // Параметризированный конструктор
  S21Matrix(const S21Matrix &other); // Конструктор копирования
  S21Matrix(S21Matrix &&other) noexcept; // Конструктор переноса

  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double num);

  ~S21Matrix() noexcept; // Destructor

  // Getters(accessors) / setters(mutators)
  void set_rows(const int &rows);
  int get_rows() const noexcept;
  void set_cols(const int &cols);
  int get_cols() const noexcept;

  // Methods...
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;
  S21Matrix ReduceMatrix(const int row, const int col) const;

  // Operators
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(const double num) const;
  friend S21Matrix operator*(const double num, const S21Matrix &other);
  bool operator==(const S21Matrix &other) const;
  double &operator()(const int row, const int col);
  const double &operator()(const int row, const int col) const;

private:
  // private methods
  void ResetMatrix() noexcept;

  // Attributes
  int rows_, cols_; // Rows and columns
  double *matrix_;  // Pointer to the memory where the matrix is allocated
};

#endif // CPP1_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_
