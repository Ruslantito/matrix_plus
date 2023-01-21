#include "./main.h"

class AccessorsMutators : public ::testing::Test {
protected:
  S21Matrix M43, M44, M34, M33;

  void SetUp() override {
    M43.set_rows(4);
    M43.set_cols(3);
    M43(0, 0) = 1;
    M43(0, 1) = 2;
    M43(0, 2) = 3;
    M43(1, 0) = 4;
    M43(1, 1) = 5;
    M43(1, 2) = 6;
    M43(2, 0) = 7;
    M43(2, 1) = 8;
    M43(2, 2) = 9;
    M43(3, 0) = 10;
    M43(3, 1) = 11;
    M43(3, 2) = 12;

    M44.set_rows(4);
    M44.set_cols(4);
    M44(0, 0) = 1;
    M44(0, 1) = 2;
    M44(0, 2) = 3;
    M44(0, 3) = 1;
    M44(1, 0) = 4;
    M44(1, 1) = 5;
    M44(1, 2) = 6;
    M44(1, 3) = 1;
    M44(2, 0) = 7;
    M44(2, 1) = 8;
    M44(2, 2) = 9;
    M44(2, 3) = 1;
    M44(3, 0) = 1;
    M44(3, 1) = 1;
    M44(3, 2) = 1;
    M44(3, 3) = 1;

    M34.set_rows(3);
    M34.set_cols(4);
    M34(0, 0) = 1;
    M34(0, 1) = 2;
    M34(0, 2) = 3;
    M34(0, 3) = 4;
    M34(1, 0) = 5;
    M34(1, 1) = 6;
    M34(1, 2) = 7;
    M34(1, 3) = 8;
    M34(2, 0) = 9;
    M34(2, 1) = 10;
    M34(2, 2) = 11;
    M34(2, 3) = 12;

    M33.set_rows(3);
    M33.set_cols(3);
    M33(0, 0) = 1;
    M33(0, 1) = 2;
    M33(0, 2) = 3;
    M33(1, 0) = 4;
    M33(1, 1) = 5;
    M33(1, 2) = 6;
    M33(2, 0) = 7;
    M33(2, 1) = 8;
    M33(2, 2) = 9;
  }
};

TEST_F(AccessorsMutators, test_getters) {
  EXPECT_TRUE(M33.get_cols() == 3);
  EXPECT_TRUE(M33.get_rows() == 3);
}

TEST_F(AccessorsMutators, test_set_rows_4_3) {
  M43.set_rows(3);
  for (auto i = 0; i < 3; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
}

TEST_F(AccessorsMutators, test_set_rows_4_5) {
  M43.set_rows(5);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
  for (auto j = 0; j < 3; j++) {
    EXPECT_TRUE(M43(4, j) == 0);
  }
}

TEST_F(AccessorsMutators, test_set_rows_4_6) {
  M43.set_rows(6);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
  for (auto j = 0; j < 3; j++) {
    EXPECT_TRUE(M43(4, j) == 0);
  }
  for (auto j = 0; j < 3; j++) {
    EXPECT_TRUE(M43(5, j) == 0);
  }
}

TEST_F(AccessorsMutators, test_set_rows_4_0) {
  M33.set_rows(0);
  EXPECT_ANY_THROW(M33(0, 0));
}

TEST_F(AccessorsMutators, test_set_rows_err) {
  EXPECT_ANY_THROW(M33.set_rows(-1));
}

TEST_F(AccessorsMutators, test_set_cols_3_2) {
  M43.set_cols(2);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 2; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
}

TEST_F(AccessorsMutators, test_set_cols_3_4) {
  M43.set_cols(4);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
  for (auto i = 0; i < 4; i++) {
    EXPECT_TRUE(M43(i, 3) == 0);
  }
}

TEST_F(AccessorsMutators, test_set_cols_3_5) {
  M43.set_cols(5);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 3; j++) {
      EXPECT_TRUE(M43(i, j) == i * 3 + j + 1);
    }
  }
  for (auto i = 0; i < 4; i++) {
    EXPECT_TRUE(M43(i, 3) == 0);
  }
  for (auto i = 0; i < 4; i++) {
    EXPECT_TRUE(M43(i, 4) == 0);
  }
}

TEST_F(AccessorsMutators, test_set_cols_4_0) {
  M43.set_cols(0);
  EXPECT_THROW(M43(0, 0), std::out_of_range);
}

TEST_F(AccessorsMutators, test_set_cols_err) {
  EXPECT_THROW(M43.set_cols(-1), std::invalid_argument);
}

TEST_F(AccessorsMutators, test_set_cols_0) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;
  test_matrix.set_cols(0);
  EXPECT_FALSE(test_matrix == matrix_before);
}
