#include "./main.h"

TEST(OperOverloads, test_op_plus) {
  S21Matrix M(4, 4), K(4, 4), R(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 1;
  M(0, 2) = 1;
  M(0, 3) = 1;
  M(1, 0) = 1;
  M(1, 1) = 1;
  M(1, 2) = 1;
  M(1, 3) = 1;
  M(2, 0) = 1;
  M(2, 1) = 1;
  M(2, 2) = 1;
  M(2, 3) = 1;
  M(3, 0) = 1;
  M(3, 1) = 1;
  M(3, 2) = 1;
  M(3, 3) = 1;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(0, 3) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;
  K(1, 3) = 3;
  K(2, 0) = 3;
  K(2, 1) = 3;
  K(2, 2) = 3;
  K(2, 3) = 3;
  K(3, 0) = 3;
  K(3, 1) = 3;
  K(3, 2) = 3;
  K(3, 3) = 3;

  R(0, 0) = 4;
  R(0, 1) = 4;
  R(0, 2) = 4;
  R(0, 3) = 4;
  R(1, 0) = 4;
  R(1, 1) = 4;
  R(1, 2) = 4;
  R(1, 3) = 4;
  R(2, 0) = 4;
  R(2, 1) = 4;
  R(2, 2) = 4;
  R(2, 3) = 4;
  R(3, 0) = 4;
  R(3, 1) = 4;
  R(3, 2) = 4;
  R(3, 3) = 4;

  EXPECT_TRUE(R.EqMatrix(M + K));
}

TEST(OperOverloads, test_op_plus_err) {
  S21Matrix M(3, 4), K(4, 4);
  EXPECT_ANY_THROW(EXPECT_TRUE(M.EqMatrix(M + K)));
}

TEST(OperOverloads, test_op_minus) {
  S21Matrix M(4, 4), K(4, 4), R(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 1;
  M(0, 2) = 1;
  M(0, 3) = 1;
  M(1, 0) = 1;
  M(1, 1) = 1;
  M(1, 2) = 1;
  M(1, 3) = 1;
  M(2, 0) = 1;
  M(2, 1) = 1;
  M(2, 2) = 1;
  M(2, 3) = 1;
  M(3, 0) = 1;
  M(3, 1) = 1;
  M(3, 2) = 1;
  M(3, 3) = 1;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(0, 3) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;
  K(1, 3) = 3;
  K(2, 0) = 3;
  K(2, 1) = 3;
  K(2, 2) = 3;
  K(2, 3) = 3;
  K(3, 0) = 3;
  K(3, 1) = 3;
  K(3, 2) = 3;
  K(3, 3) = 3;

  R(0, 0) = -2;
  R(0, 1) = -2;
  R(0, 2) = -2;
  R(0, 3) = -2;
  R(1, 0) = -2;
  R(1, 1) = -2;
  R(1, 2) = -2;
  R(1, 3) = -2;
  R(2, 0) = -2;
  R(2, 1) = -2;
  R(2, 2) = -2;
  R(2, 3) = -2;
  R(3, 0) = -2;
  R(3, 1) = -2;
  R(3, 2) = -2;
  R(3, 3) = -2;

  EXPECT_TRUE(R.EqMatrix(M - K));
}

TEST(OperOverloads, test_op_minus_err) {
  S21Matrix M(3, 4), K(4, 4);
  EXPECT_ANY_THROW(EXPECT_TRUE(M.EqMatrix(M - K)));
}

TEST(OperOverloads, test_op_mul) {
  S21Matrix M(3, 2), K(2, 3), R(3, 3);

  M(0, 0) = 2;
  M(0, 1) = 2;
  M(1, 0) = 2;
  M(1, 1) = 2;
  M(2, 0) = 2;
  M(2, 1) = 2;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;

  R(0, 0) = 12;
  R(0, 1) = 12;
  R(0, 2) = 12;
  R(1, 0) = 12;
  R(1, 1) = 12;
  R(1, 2) = 12;
  R(2, 0) = 12;
  R(2, 1) = 12;
  R(2, 2) = 12;

  EXPECT_TRUE((M * K).get_rows() == 3);
  EXPECT_TRUE((M * K).get_cols() == 3);
  EXPECT_TRUE(R.EqMatrix((M * K)));
}

TEST(OperOverloads, test_op_mul_err) {
  S21Matrix M(3, 2), K(3, 3);
  EXPECT_ANY_THROW(EXPECT_TRUE((M * K).get_rows() == 3));
}

TEST(OperOverloads, test_op_mul_num) {
  S21Matrix M(3, 3), R(3, 3);

  M(0, 0) = 12;
  M(0, 1) = 12;
  M(0, 2) = 12;
  M(1, 0) = 12;
  M(1, 1) = 12;
  M(1, 2) = 12;
  M(2, 0) = 12;
  M(2, 1) = 12;
  M(2, 2) = 12;

  R(0, 0) = 36;
  R(0, 1) = 36;
  R(0, 2) = 36;
  R(1, 0) = 36;
  R(1, 1) = 36;
  R(1, 2) = 36;
  R(2, 0) = 36;
  R(2, 1) = 36;
  R(2, 2) = 36;

  EXPECT_TRUE(R.EqMatrix(M * 3));
  EXPECT_TRUE(R.EqMatrix(3 * M));
}

TEST(OperOverloads, test_op_equal) {
  S21Matrix M(4, 4);
  S21Matrix K(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  K(0, 0) = 1;
  K(0, 1) = 2;
  K(0, 2) = 3;
  K(0, 3) = 1;
  K(1, 0) = 4;
  K(1, 1) = 5;
  K(1, 2) = 6;
  K(1, 3) = 1;
  K(2, 0) = 7;
  K(2, 1) = 8;
  K(2, 2) = 9;
  K(2, 3) = 1;
  K(3, 0) = 10;
  K(3, 1) = 11;
  K(3, 2) = 12;
  K(3, 3) = 1;

  EXPECT_TRUE(M == K);
}

TEST(OperOverloads, test_op_assign) {
  S21Matrix M(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  S21Matrix K;
  K = M;
  EXPECT_TRUE(M == K);

  S21Matrix N(6, 6);
  N = M;
  EXPECT_TRUE(M == N);
}

TEST(OperOverloads, test_op_assign_self) {
  S21Matrix M(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  M = M;

  EXPECT_TRUE(M == M);
}

TEST(OperOverloads, test_op_assign_move) {
  S21Matrix M(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  S21Matrix K = std::move(M);
  EXPECT_TRUE(K(1, 1) == 5);
  EXPECT_THROW(M(0, 0), std::out_of_range);
}

TEST(OperOverloads, test_op_addition_assignment) {
  S21Matrix M(4, 4), K(4, 4), R(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 1;
  M(0, 2) = 1;
  M(0, 3) = 1;
  M(1, 0) = 1;
  M(1, 1) = 1;
  M(1, 2) = 1;
  M(1, 3) = 1;
  M(2, 0) = 1;
  M(2, 1) = 1;
  M(2, 2) = 1;
  M(2, 3) = 1;
  M(3, 0) = 1;
  M(3, 1) = 1;
  M(3, 2) = 1;
  M(3, 3) = 1;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(0, 3) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;
  K(1, 3) = 3;
  K(2, 0) = 3;
  K(2, 1) = 3;
  K(2, 2) = 3;
  K(2, 3) = 3;
  K(3, 0) = 3;
  K(3, 1) = 3;
  K(3, 2) = 3;
  K(3, 3) = 3;

  R(0, 0) = 4;
  R(0, 1) = 4;
  R(0, 2) = 4;
  R(0, 3) = 4;
  R(1, 0) = 4;
  R(1, 1) = 4;
  R(1, 2) = 4;
  R(1, 3) = 4;
  R(2, 0) = 4;
  R(2, 1) = 4;
  R(2, 2) = 4;
  R(2, 3) = 4;
  R(3, 0) = 4;
  R(3, 1) = 4;
  R(3, 2) = 4;
  R(3, 3) = 4;

  EXPECT_TRUE(R.EqMatrix(M += K));
}

TEST(OperOverloads, test_op_sub_assignment) {
  S21Matrix M(4, 4), K(4, 4), R(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 1;
  M(0, 2) = 1;
  M(0, 3) = 1;
  M(1, 0) = 1;
  M(1, 1) = 1;
  M(1, 2) = 1;
  M(1, 3) = 1;
  M(2, 0) = 1;
  M(2, 1) = 1;
  M(2, 2) = 1;
  M(2, 3) = 1;
  M(3, 0) = 1;
  M(3, 1) = 1;
  M(3, 2) = 1;
  M(3, 3) = 1;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(0, 3) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;
  K(1, 3) = 3;
  K(2, 0) = 3;
  K(2, 1) = 3;
  K(2, 2) = 3;
  K(2, 3) = 3;
  K(3, 0) = 3;
  K(3, 1) = 3;
  K(3, 2) = 3;
  K(3, 3) = 3;

  R(0, 0) = 4;
  R(0, 1) = 4;
  R(0, 2) = 4;
  R(0, 3) = 4;
  R(1, 0) = 4;
  R(1, 1) = 4;
  R(1, 2) = 4;
  R(1, 3) = 4;
  R(2, 0) = 4;
  R(2, 1) = 4;
  R(2, 2) = 4;
  R(2, 3) = 4;
  R(3, 0) = 4;
  R(3, 1) = 4;
  R(3, 2) = 4;
  R(3, 3) = 4;

  EXPECT_TRUE(M.EqMatrix(R -= K));
}

TEST(OperOverloads, test_op_mul_assignment) {
  S21Matrix M(3, 2), K(2, 3), R(3, 3);

  M(0, 0) = 2;
  M(0, 1) = 2;
  M(1, 0) = 2;
  M(1, 1) = 2;
  M(2, 0) = 2;
  M(2, 1) = 2;

  K(0, 0) = 3;
  K(0, 1) = 3;
  K(0, 2) = 3;
  K(1, 0) = 3;
  K(1, 1) = 3;
  K(1, 2) = 3;

  R(0, 0) = 12;
  R(0, 1) = 12;
  R(0, 2) = 12;
  R(1, 0) = 12;
  R(1, 1) = 12;
  R(1, 2) = 12;
  R(2, 0) = 12;
  R(2, 1) = 12;
  R(2, 2) = 12;

  S21Matrix multiplied = M * K;
  EXPECT_TRUE(multiplied.get_rows() == 3);
  EXPECT_TRUE(multiplied.get_cols() == 3);
  EXPECT_TRUE(R.EqMatrix(M *= K));
}

TEST(OperOverloads, test_op_mul_assignment_num) {
  S21Matrix M(3, 3), R(3, 3);

  M(0, 0) = 12;
  M(0, 1) = 12;
  M(0, 2) = 12;
  M(1, 0) = 12;
  M(1, 1) = 12;
  M(1, 2) = 12;
  M(2, 0) = 12;
  M(2, 1) = 12;
  M(2, 2) = 12;

  R(0, 0) = 36;
  R(0, 1) = 36;
  R(0, 2) = 36;
  R(1, 0) = 36;
  R(1, 1) = 36;
  R(1, 2) = 36;
  R(2, 0) = 36;
  R(2, 1) = 36;
  R(2, 2) = 36;

  EXPECT_TRUE(R.EqMatrix(M *= 3));
}

TEST(OperOverloads, test_op_paren) {
  S21Matrix M(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  EXPECT_TRUE(M(2, 2) == 9);
}

TEST(OperOverloads, test_op_paren_err) {
  S21Matrix M(4, 4);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 1;
  M(1, 0) = 4;
  M(1, 1) = 5;
  M(1, 2) = 6;
  M(1, 3) = 1;
  M(2, 0) = 7;
  M(2, 1) = 8;
  M(2, 2) = 9;
  M(2, 3) = 1;
  M(3, 0) = 10;
  M(3, 1) = 11;
  M(3, 2) = 12;
  M(3, 3) = 1;

  EXPECT_ANY_THROW(EXPECT_TRUE(M(4, 2) == 9));
}

TEST(OperOverloads, test_op_paren_err_const) {
  const S21Matrix M(4, 4);

  EXPECT_ANY_THROW(EXPECT_TRUE(M(4, 2) == 9));
}
