#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

TEST(Constructors, test_noarg) {
  S21Matrix M;
  EXPECT_TRUE(M.get_cols() == 0);
  EXPECT_TRUE(M.get_rows() == 0);
  EXPECT_THROW(M(0, 0), std::out_of_range);
}

TEST(Constructors, test_noarg_ptr) {
  S21Matrix *M = new S21Matrix;
  EXPECT_THROW((*M)(0, 0), std::out_of_range);
  delete M;
}

TEST(Constructors, test_special_cases) {
  S21Matrix M;
  const S21Matrix R;
  S21Matrix N(M);
  const S21Matrix K(M);
  EXPECT_THROW(N(0, 0), std::out_of_range);
  EXPECT_THROW(K(0, 0), std::out_of_range);
  EXPECT_THROW(M(0, 0), std::out_of_range);
  EXPECT_THROW(R(0, 0), std::out_of_range);
}

TEST(Constructors, test_noarg_const) {
  const S21Matrix M;
  EXPECT_TRUE(M.get_cols() == 0);
  EXPECT_TRUE(M.get_rows() == 0);
  EXPECT_THROW(M(0, 0), std::out_of_range);
}

TEST(Constructors, test_twoarg_34) {
  S21Matrix *M = new S21Matrix(3, 4);
  EXPECT_TRUE(M->get_rows() == 3);
  EXPECT_TRUE(M->get_cols() == 4);
  for (auto i = 0; i < 3; i++) {
    for (auto j = 0; j < 4; j++) {
      EXPECT_TRUE((*M)(i, j) == 0);
    }
  }
  delete M;
}

TEST(Constructors, test_twoarg_34_const) {
  const S21Matrix M(3, 4);
  EXPECT_TRUE(M.get_rows() == 3);
  EXPECT_TRUE(M.get_cols() == 4);
  for (auto i = 0; i < 3; i++) {
    for (auto j = 0; j < 4; j++) {
      EXPECT_TRUE(M(i, j) == 0);
    }
  }
}

TEST(Constructors, test_twoarg_11) {
  S21Matrix M(1, 1);
  EXPECT_TRUE(M.get_rows() == 1);
  EXPECT_TRUE(M.get_cols() == 1);
  EXPECT_TRUE(M(0, 0) == 0);
}

TEST(Constructors, test_twoarg_err) { EXPECT_ANY_THROW(S21Matrix M(-1, -1)); }

TEST(Constructors, test_twoarg_00) {
  S21Matrix M(0, 0);
  EXPECT_TRUE(M.get_rows() == 0);
  EXPECT_TRUE(M.get_cols() == 0);
  EXPECT_THROW(M(0, 0), std::out_of_range);
}

TEST(Constructors, test_copy) {
  S21Matrix other;
  other.set_cols(1);
  other.set_rows(1);
  S21Matrix *M = new S21Matrix(other);

  EXPECT_TRUE(M->get_rows() == 1);
  EXPECT_TRUE(M->get_cols() == 1);
  EXPECT_TRUE((*M)(0, 0) == 0);

  delete M;
}

TEST(Constructors, test_copy_2) {
  S21Matrix other;
  other.set_cols(3);
  other.set_rows(2);
  S21Matrix M(other);
  EXPECT_TRUE(M.get_rows() == 2);
  EXPECT_TRUE(M.get_cols() == 3);
  for (auto i = 0; i < 2; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M(i, j) == 0);
    }
  }
}

TEST(Constructors, test_move) {
  S21Matrix other;
  other.set_rows(1);
  other.set_cols(3);
  other(0, 2) = 2;
  S21Matrix M = std::move(other);
  EXPECT_TRUE(M.get_rows() == 1);
  EXPECT_TRUE(M.get_cols() == 3);

  EXPECT_ANY_THROW(other(0, 0));
  EXPECT_TRUE(M(0, 0) == 0);
  EXPECT_TRUE(M(0, 2) == 2);
}

TEST(Constructors, test_move_const) {
  S21Matrix other;
  other.set_rows(1);
  other.set_cols(3);
  other(0, 2) = 2;
  const S21Matrix M = std::move(other);
  EXPECT_TRUE(M.get_rows() == 1);
  EXPECT_TRUE(M.get_cols() == 3);

  EXPECT_ANY_THROW(other(0, 0));
  EXPECT_TRUE(M(0, 0) == 0);
  EXPECT_TRUE(M(0, 2) == 2);
}