#include "./main.h"

class PublicMethods : public ::testing::Test {
protected:
  S21Matrix K44, M44, M43, M34, M33, R44, R33, Res_of_mult;

  void SetUp() override {
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
    M44(3, 0) = 10;
    M44(3, 1) = 11;
    M44(3, 2) = 12;
    M44(3, 3) = 1;

    R44.set_rows(4);
    R44.set_cols(4);
    R44(0, 0) = 1;
    R44(0, 1) = 2;
    R44(0, 2) = 3;
    R44(0, 3) = 1;
    R44(1, 0) = 4;
    R44(1, 1) = 5;
    R44(1, 2) = 6;
    R44(1, 3) = 1;
    R44(2, 0) = 7;
    R44(2, 1) = 8;
    R44(2, 2) = 9;
    R44(2, 3) = 1;
    R44(3, 0) = 10;
    R44(3, 1) = 11;
    R44(3, 2) = 12;
    R44(3, 3) = 1;

    K44.set_rows(4);
    K44.set_cols(4);
    K44(0, 0) = 1;
    K44(0, 1) = 2;
    K44(0, 2) = 3;
    K44(0, 3) = 1.00004;
    K44(1, 0) = 4;
    K44(1, 1) = 5;
    K44(1, 2) = 6;
    K44(1, 3) = 1;
    K44(2, 0) = 7;
    K44(2, 1) = 8;
    K44(2, 2) = 9;
    K44(2, 3) = 1;
    K44(3, 0) = 10;
    K44(3, 1) = 11;
    K44(3, 2) = 12;
    K44(3, 3) = 1;

    M34.set_rows(3);
    M34.set_cols(4);
    M34(0, 0) = 2;
    M34(0, 1) = 3;
    M34(0, 2) = 6;
    M34(0, 3) = 2;
    M34(1, 0) = 2;
    M34(1, 1) = 1;
    M34(1, 2) = 2;
    M34(1, 3) = 3;
    M34(2, 0) = 3;
    M34(2, 1) = 5;
    M34(2, 2) = 0.5;
    M34(2, 3) = 4;

    M43.set_rows(4);
    M43.set_cols(3);
    M43(0, 0) = 6;
    M43(0, 1) = 3;
    M43(0, 2) = 1;
    M43(1, 0) = 5;
    M43(1, 1) = 4;
    M43(1, 2) = 1;
    M43(2, 0) = 4;
    M43(2, 1) = 5;
    M43(2, 2) = 2;
    M43(3, 0) = 3;
    M43(3, 1) = 6;
    M43(3, 2) = 1;

    Res_of_mult.set_rows(3);
    Res_of_mult.set_cols(3);
    Res_of_mult(0, 0) = 57;
    Res_of_mult(0, 1) = 60;
    Res_of_mult(0, 2) = 19;
    Res_of_mult(1, 0) = 34;
    Res_of_mult(1, 1) = 38;
    Res_of_mult(1, 2) = 10;
    Res_of_mult(2, 0) = 57;
    Res_of_mult(2, 1) = 111 / 2.0;
    Res_of_mult(2, 2) = 13;

    M33.set_rows(3);
    M33.set_cols(3);
    M33(0, 0) = 2;
    M33(0, 1) = 2;
    M33(0, 2) = 2;
    M33(1, 0) = 2;
    M33(1, 1) = 2;
    M33(1, 2) = 2;
    M33(2, 0) = 2;
    M33(2, 1) = 2;
    M33(2, 2) = 2;

    R33.set_rows(3);
    R33.set_cols(3);
    R33(0, 0) = 5;
    R33(0, 1) = 5;
    R33(0, 2) = 5;
    R33(1, 0) = 5;
    R33(1, 1) = 5;
    R33(1, 2) = 5;
    R33(2, 0) = 5;
    R33(2, 1) = 5;
    R33(2, 2) = 5;
  }
};

// // Public Methods
TEST_F(PublicMethods, test_EqMatrix_44_44_eq) {
  EXPECT_TRUE(M44.EqMatrix(R44));
}

TEST_F(PublicMethods, test_EqMatrix_44_44_neq) {
  EXPECT_FALSE(M44.EqMatrix(K44));
  EXPECT_FALSE(K44.EqMatrix(M44));
}

TEST_F(PublicMethods, test_EqMatrix_44_43) {
  EXPECT_FALSE(M44.EqMatrix(M34));
  EXPECT_FALSE(M34.EqMatrix(M44));
}

TEST_F(PublicMethods, test_SumMatrix) {
  M44.SumMatrix(R44);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 4; j++) {
      EXPECT_TRUE(M44(i, j) == R44(i, j) * 2);
    }
  }
}

TEST_F(PublicMethods, test_SumMatrix_err) {
  EXPECT_ANY_THROW(M44.SumMatrix(M34));
}

TEST_F(PublicMethods, test_SubMatrix) {
  M44.SubMatrix(R44);
  for (auto i = 0; i < 4; i++) {
    for (auto j = 0; j < 4; j++) {
      EXPECT_TRUE(M44(i, j) == 0);
    }
  }
}

TEST_F(PublicMethods, test_SubMatrix_err) {
  EXPECT_ANY_THROW(M44.SubMatrix(M34));
}

TEST_F(PublicMethods, test_MulNumber) {
  M33.MulNumber(2.50);
  EXPECT_TRUE(M33.EqMatrix(R33));
}

TEST_F(PublicMethods, test_MulNumber_err) {
  S21Matrix M(4, 4);
  EXPECT_ANY_THROW(M.MulNumber(std::nan("")));
}

TEST_F(PublicMethods, test_MulMatrix) {
  M34.MulMatrix(M43);
  EXPECT_TRUE(Res_of_mult.EqMatrix(M34));
}

TEST_F(PublicMethods, test_MulMatrix_to_bigger) {
  S21Matrix M(4, 2), K(2, 4), R(4, 4);
  M(0, 0) = 2;
  M(0, 1) = 3;
  M(1, 0) = 2;
  M(1, 1) = 1;
  M(2, 0) = 3;
  M(2, 1) = 5;
  M(3, 0) = 6;
  M(3, 1) = 2;

  K(0, 0) = 6;
  K(0, 1) = 3;
  K(0, 2) = 1;
  K(0, 3) = 5;
  K(1, 0) = 5;
  K(1, 1) = 4;
  K(1, 2) = 1;
  K(1, 3) = 5;

  R(0, 0) = 27;
  R(0, 1) = 18;
  R(0, 2) = 5;
  R(0, 3) = 25;
  R(1, 0) = 17;
  R(1, 1) = 10;
  R(1, 2) = 3;
  R(1, 3) = 15;
  R(2, 0) = 43;
  R(2, 1) = 29;
  R(2, 2) = 8;
  R(2, 3) = 40;
  R(3, 0) = 46;
  R(3, 1) = 26;
  R(3, 2) = 8;
  R(3, 3) = 40;

  M.MulMatrix(K);
  EXPECT_TRUE(R.EqMatrix(M));
}

TEST_F(PublicMethods, test_MulMatrix_err) {
  S21Matrix M(3, 2);
  S21Matrix K(3, 3);

  EXPECT_ANY_THROW(M.MulMatrix(K));
}

TEST_F(PublicMethods, test_Transpose) {
  S21Matrix M(3, 2);
  S21Matrix K(2, 3);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(1, 0) = 3;
  M(1, 1) = 4;
  M(2, 0) = 5;
  M(2, 1) = 6;

  K(0, 0) = 1;
  K(0, 1) = 3;
  K(0, 2) = 5;
  K(1, 0) = 2;
  K(1, 1) = 4;
  K(1, 2) = 6;

  S21Matrix R = M.Transpose();

  EXPECT_TRUE(K.EqMatrix(R));
}

TEST_F(PublicMethods, test_Transpose_const) {
  const S21Matrix M(3, 2);
  const S21Matrix K(2, 3);

  S21Matrix R = M.Transpose();

  EXPECT_TRUE(K.EqMatrix(R));
}

// TEST_F(PublicMethods, test_Cut_55_44) {
//   S21Matrix M(5, 5);
//   S21Matrix K(4, 4);

//   M(0, 0) = 1;
//   M(0, 1) = 2;
//   M(0, 2) = 3;
//   M(0, 3) = 4;
//   M(0, 4) = 5;
//   M(1, 0) = 6;
//   M(1, 1) = 7;
//   M(1, 2) = 8;
//   M(1, 3) = 9;
//   M(1, 4) = 10;
//   M(2, 0) = 11;
//   M(2, 1) = 12;
//   M(2, 2) = 13;
//   M(2, 3) = 14;
//   M(2, 4) = 15;
//   M(3, 0) = 16;
//   M(3, 1) = 17;
//   M(3, 2) = 18;
//   M(3, 3) = 19;
//   M(3, 4) = 20;
//   M(4, 0) = 21;
//   M(4, 1) = 22;
//   M(4, 2) = 23;
//   M(4, 3) = 24;
//   M(4, 4) = 25;

//   K(0, 0) = 1;
//   K(0, 1) = 2;
//   K(0, 2) = 3;
//   K(0, 3) = 5;
//   K(1, 0) = 6;
//   K(1, 1) = 7;
//   K(1, 2) = 8;
//   K(1, 3) = 10;
//   K(2, 0) = 16;
//   K(2, 1) = 17;
//   K(2, 2) = 18;
//   K(2, 3) = 20;
//   K(3, 0) = 21;
//   K(3, 1) = 22;
//   K(3, 2) = 23;
//   K(3, 3) = 25;

//   S21Matrix R = M.Cut(2, 3);

//   EXPECT_TRUE(K.EqMatrix(R));
// }

// TEST_F(PublicMethods, test_Cut_22_11) {
//   S21Matrix M(2, 2);
//   S21Matrix K(1, 1);

//   M(0, 0) = 1;
//   M(0, 1) = 2;
//   M(1, 0) = 6;
//   M(1, 1) = 7;

//   K(0, 0) = 1;
//   S21Matrix R = M.Cut(1, 1);
//   EXPECT_TRUE(K.EqMatrix(R));

//   K(0, 0) = 6;
//   S21Matrix R1 = M.Cut(0, 1);
//   EXPECT_TRUE(K.EqMatrix(R1));

//   K(0, 0) = 2;
//   S21Matrix R2 = M.Cut(1, 0);
//   EXPECT_TRUE(K.EqMatrix(R2));

//   K(0, 0) = 7;
//   S21Matrix R3 = M.Cut(0, 0);
//   EXPECT_TRUE(K.EqMatrix(R3));
// }

// TEST_F(PublicMethods, test_Cut_11_err) {
//   S21Matrix K(1, 1);
//   EXPECT_ANY_THROW(S21Matrix R = K.Cut(1, 1));
// }

// TEST_F(PublicMethods, test_SwapRows_1) {
//   M44.SwapRows(1, 2);
//   EXPECT_TRUE(M44(1, 0) == 7);
//   EXPECT_TRUE(M44(1, 1) == 8);
//   EXPECT_TRUE(M44(1, 2) == 9);
//   EXPECT_TRUE(M44(1, 3) == 1);
//   EXPECT_TRUE(M44(2, 0) == 4);
//   EXPECT_TRUE(M44(2, 1) == 5);
//   EXPECT_TRUE(M44(2, 2) == 6);
//   EXPECT_TRUE(M44(2, 3) == 1);
// }

// TEST_F(PublicMethods, test_SwapRows_err) {
//   EXPECT_ANY_THROW(M44.SwapRows(-1, 2));
// }

TEST_F(PublicMethods, test_Determinant_11) {
  S21Matrix M(1, 1);
  M(0, 0) = 2;
  EXPECT_TRUE(M.Determinant() == 2);
}

TEST_F(PublicMethods, test_Determinant_22) {
  S21Matrix M(2, 2);

  M(0, 0) = 2;
  M(0, 1) = 2;
  M(1, 0) = 2;
  M(1, 1) = 3;

  EXPECT_TRUE(M.Determinant() == 2);
}

TEST_F(PublicMethods, test_Determinant_33) {
  S21Matrix M(3, 3);

  M(0, 0) = 2;
  M(0, 1) = 2;
  M(0, 2) = 2;
  M(1, 0) = 2;
  M(1, 1) = 3;
  M(1, 2) = 1;
  M(2, 0) = 3;
  M(2, 1) = 2;
  M(2, 2) = 5;

  // EXPECT_TRUE(M.Determinant() == 2);
  EXPECT_NEAR(M.Determinant(), 2, kS21_EPS);
}

TEST_F(PublicMethods, test_Determinant_44) {
  S21Matrix M(4, 4);

  M(0, 0) = -2;
  M(0, 1) = 2;
  M(0, 2) = 2;
  M(0, 3) = 2;
  M(1, 0) = 2;
  M(1, 1) = 0.3;
  M(1, 2) = 1;
  M(1, 3) = 3;
  M(2, 0) = 3;
  M(2, 1) = 2;
  M(2, 2) = 5;
  M(2, 3) = 4;
  M(3, 0) = 6;
  M(3, 1) = 7;
  M(3, 2) = 8;
  M(3, 3) = 5;

  EXPECT_NEAR(M.Determinant(), 170, kS21_EPS);
}

TEST_F(PublicMethods, test_Determinant_44_2) {
  S21Matrix M(4, 4);

  M(0, 0) = -2;
  M(0, 1) = 2;
  M(0, 2) = 2;
  M(0, 3) = 2;
  M(1, 0) = -2;
  M(1, 1) = 2;
  M(1, 2) = 2;
  M(1, 3) = 2;
  M(2, 0) = 3;
  M(2, 1) = 2;
  M(2, 2) = 5;
  M(2, 3) = 4;
  M(3, 0) = 6;
  M(3, 1) = 7;
  M(3, 2) = 8;
  M(3, 3) = 5;

  EXPECT_TRUE(M.Determinant() == 0);
}

TEST_F(PublicMethods, test_Determinant_55) {
  S21Matrix M(5, 5);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 2;
  M(0, 4) = 1;
  M(1, 0) = 2;
  M(1, 1) = 4;
  M(1, 2) = 1;
  M(1, 3) = 3;
  M(1, 4) = 2;
  M(2, 0) = 1;
  M(2, 1) = 3;
  M(2, 2) = 1;
  M(2, 3) = 5;
  M(2, 4) = 1;
  M(3, 0) = 0.11;
  M(3, 1) = 2;
  M(3, 2) = 0.3;
  M(3, 3) = 0.5;
  M(3, 4) = 1;
  M(4, 0) = 3;
  M(4, 1) = 2;
  M(4, 2) = 1;
  M(4, 3) = 3;
  M(4, 4) = 1;

  EXPECT_NEAR(M.Determinant(), 3.37, kS21_EPS);
}

// TEST_F(PublicMethods, test_Determinant_13_13) {
//   S21Matrix M(13, 13);

//   M(0, 0) = -2;
//   M(0, 1) = 2;
//   M(0, 2) = 2;
//   M(0, 3) = 2;
//   M(0, 4) = 1;
//   M(0, 5) = 2;
//   M(0, 6) = 5;
//   M(0, 7) = 8;
//   M(0, 8) = 9;
//   M(0, 9) = 1;
//   M(0, 10) = 2;
//   M(0, 11) = 3;
//   M(0, 12) = 4;
//   M(1, 0) = 2;
//   M(1, 1) = 0.3;
//   M(1, 2) = 1;
//   M(1, 3) = 3;
//   M(1, 4) = 3;
//   M(1, 5) = 4;
//   M(1, 6) = 6;
//   M(1, 7) = 7;
//   M(1, 8) = 0;
//   M(1, 9) = 2;
//   M(1, 10) = 3;
//   M(1, 11) = 0;
//   M(1, 12) = 5;
//   M(2, 0) = 3;
//   M(2, 1) = 2;
//   M(2, 2) = 5;
//   M(2, 3) = 4;
//   M(2, 4) = 0;
//   M(2, 5) = 0;
//   M(2, 6) = 0;
//   M(2, 7) = 0;
//   M(2, 8) = 0;
//   M(2, 9) = 0;
//   M(2, 10) = 4;
//   M(2, 11) = 3;
//   M(2, 12) = 6;
//   M(3, 0) = 6;
//   M(3, 1) = 7;
//   M(3, 2) = 8;
//   M(3, 3) = 5;
//   M(3, 4) = 3;
//   M(3, 5) = 2;
//   M(3, 6) = 6;
//   M(3, 7) = 2;
//   M(3, 8) = 0;
//   M(3, 9) = 0;
//   M(3, 10) = 11;
//   M(3, 11) = 3;
//   M(3, 12) = 7;
//   M(4, 0) = 0;
//   M(4, 1) = 0;
//   M(4, 2) = 0;
//   M(4, 3) = 5;
//   M(4, 4) = 4;
//   M(4, 5) = 0;
//   M(4, 6) = 23;
//   M(4, 7) = 6;
//   M(4, 8) = 2;
//   M(4, 9) = 0;
//   M(4, 10) = 7;
//   M(4, 11) = 6;
//   M(4, 12) = 8;
//   M(5, 0) = 0;
//   M(5, 1) = 0;
//   M(5, 2) = 0;
//   M(5, 3) = 22;
//   M(5, 4) = 2;
//   M(5, 5) = 36;
//   M(5, 6) = 0;
//   M(5, 7) = 0;
//   M(5, 8) = 0;
//   M(5, 9) = 3;
//   M(5, 10) = 0;
//   M(5, 11) = 7;
//   M(5, 12) = 7;
//   M(6, 0) = 7;
//   M(6, 1) = 0;
//   M(6, 2) = 23;
//   M(6, 3) = 6;
//   M(6, 4) = 0;
//   M(6, 5) = 7;
//   M(6, 6) = 8;
//   M(6, 7) = 9;
//   M(6, 8) = 1;
//   M(6, 9) = 26;
//   M(6, 10) = 0;
//   M(6, 11) = 62;
//   M(6, 12) = 6;
//   M(7, 0) = 0;
//   M(7, 1) = 23;
//   M(7, 2) = 5;
//   M(7, 3) = 0;
//   M(7, 4) = 4;
//   M(7, 5) = 6;
//   M(7, 6) = 5;
//   M(7, 7) = 3;
//   M(7, 8) = 2;
//   M(7, 9) = 0;
//   M(7, 10) = 3;
//   M(7, 11) = 5;
//   M(7, 12) = 5;
//   M(8, 0) = 4;
//   M(8, 1) = 0;
//   M(8, 2) = 0;
//   M(8, 3) = 2;
//   M(8, 4) = 6;
//   M(8, 5) = 0;
//   M(8, 6) = 0;
//   M(8, 7) = 4;
//   M(8, 8) = -5;
//   M(8, 9) = 3;
//   M(8, 10) = 0;
//   M(8, 11) = 2;
//   M(8, 12) = 4;
//   M(9, 0) = 0;
//   M(9, 1) = 3;
//   M(9, 2) = 7;
//   M(9, 3) = 4;
//   M(9, 4) = 0;
//   M(9, 5) = 0;
//   M(9, 6) = 0;
//   M(9, 7) = 0;
//   M(9, 8) = 0;
//   M(9, 9) = 4;
//   M(9, 10) = 0;
//   M(9, 11) = 5;
//   M(9, 12) = 3;
//   M(10, 0) = 2;
//   M(10, 1) = 0;
//   M(10, 2) = 5;
//   M(10, 3) = 0;
//   M(10, 4) = 0;
//   M(10, 5) = 0;
//   M(10, 6) = 0;
//   M(10, 7) = 0;
//   M(10, 8) = 0;
//   M(10, 9) = 0;
//   M(10, 10) = 0;
//   M(10, 11) = 5;
//   M(10, 12) = 2;
//   M(11, 0) = 0;
//   M(11, 1) = 3;
//   M(11, 2) = 0;
//   M(11, 3) = 0;
//   M(11, 4) = 0;
//   M(11, 5) = 0;
//   M(11, 6) = 0;
//   M(11, 7) = 0;
//   M(11, 8) = 0;
//   M(11, 9) = 0;
//   M(11, 10) = 0;
//   M(11, 11) = 7;
//   M(11, 12) = 1;
//   M(12, 0) = 6;
//   M(12, 1) = 5;
//   M(12, 2) = 4;
//   M(12, 3) = 3;
//   M(12, 4) = 2;
//   M(12, 5) = 2;
//   M(12, 6) = 3;
//   M(12, 7) = 4;
//   M(12, 8) = 2;
//   M(12, 9) = 5;
//   M(12, 10) = 1;
//   M(12, 11) = 6;
//   M(12, 12) = 2;

//   EXPECT_NEAR(M.Determinant(), -1760857683006, 0.01);
// }

TEST_F(PublicMethods, test_Determinant_err) {
  S21Matrix M(3, 4);
  EXPECT_ANY_THROW(EXPECT_TRUE(M.Determinant() == 0));
}

TEST_F(PublicMethods, test_Complements_err) {
  S21Matrix M(4, 3);

  EXPECT_ANY_THROW(M.CalcComplements());
}

TEST_F(PublicMethods, test_Complements_11) {
  S21Matrix M(1, 1);
  M(0, 0) = 5;

  EXPECT_TRUE(M.CalcComplements()(0, 0) == 1);
}

TEST_F(PublicMethods, test_Complements_22) {
  S21Matrix M(2, 2), K(2, 2);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(1, 0) = 0;
  M(1, 1) = 4;

  K(0, 0) = 4;
  K(0, 1) = 0;
  K(1, 0) = -2;
  K(1, 1) = 1;

  EXPECT_TRUE(K.EqMatrix(M.CalcComplements()));
}

TEST_F(PublicMethods, test_Complements_33) {
  S21Matrix M(3, 3), K(3, 3);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(1, 0) = 0;
  M(1, 1) = 4;
  M(1, 2) = 2;
  M(2, 0) = 5;
  M(2, 1) = 2;
  M(2, 2) = 1;

  K(0, 0) = 0;
  K(0, 1) = 10;
  K(0, 2) = -20;
  K(1, 0) = 4;
  K(1, 1) = -14;
  K(1, 2) = 8;
  K(2, 0) = -8;
  K(2, 1) = -2;
  K(2, 2) = 4;

  EXPECT_TRUE(K.EqMatrix(M.CalcComplements()));
}

TEST_F(PublicMethods, test_Complements_44) {
  S21Matrix M(4, 4), K(4, 4);

  M(0, 0) = 9;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 4;
  M(1, 0) = 5;
  M(1, 1) = 4;
  M(1, 2) = 3;
  M(1, 3) = 2;
  M(2, 0) = 3;
  M(2, 1) = 3;
  M(2, 2) = 3;
  M(2, 3) = 2;
  M(3, 0) = 6;
  M(3, 1) = 4;
  M(3, 2) = 3;
  M(3, 3) = 2;

  K(0, 0) = 0;
  K(0, 1) = 0;
  K(0, 2) = 2;
  K(0, 3) = -3;
  K(1, 0) = 6;
  K(1, 1) = -18;
  K(1, 2) = 30;
  K(1, 3) = -27;
  K(2, 0) = 0;
  K(2, 1) = 6;
  K(2, 2) = -12;
  K(2, 3) = 6;
  K(3, 0) = -6;
  K(3, 1) = 12;
  K(3, 2) = -22;
  K(3, 3) = 24;
  EXPECT_TRUE(K.EqMatrix(M.CalcComplements()));
}

TEST_F(PublicMethods, test_Inverse_11) {
  S21Matrix M(1, 1);
  M(0, 0) = 2;
  EXPECT_TRUE(M.InverseMatrix()(0, 0) == 0.5);
}

TEST_F(PublicMethods, test_Inverse_22) {
  S21Matrix M(2, 2), K(2, 2);

  M(0, 0) = 3;
  M(0, 1) = 2;
  M(1, 0) = 5;
  M(1, 1) = 0;

  K(0, 0) = 0;
  K(0, 1) = 0.2;
  K(1, 0) = 0.5;
  K(1, 1) = -0.3;

  EXPECT_TRUE(K.EqMatrix(M.InverseMatrix()));
}

TEST_F(PublicMethods, test_Inverse_33) {
  S21Matrix M(3, 3), K(3, 3);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(1, 0) = 0;
  M(1, 1) = 4;
  M(1, 2) = 2;
  M(2, 0) = 1;
  M(2, 1) = 2;
  M(2, 2) = 1;

  K(0, 0) = 0;
  K(0, 1) = -0.5;
  K(0, 2) = 1;
  K(1, 0) = -0.25;
  K(1, 1) = 0.25;
  K(1, 2) = 0.25;
  K(2, 0) = 0.5;
  K(2, 1) = 0;
  K(2, 2) = -0.5;

  EXPECT_TRUE(K.EqMatrix(M.InverseMatrix()));
}

TEST_F(PublicMethods, test_Inverse_55) {
  S21Matrix M(5, 5), K(5, 5);

  M(0, 0) = 1;
  M(0, 1) = 2;
  M(0, 2) = 3;
  M(0, 3) = 2;
  M(0, 4) = 1;
  M(1, 0) = 2;
  M(1, 1) = 4;
  M(1, 2) = 1;
  M(1, 3) = 3;
  M(1, 4) = 2;
  M(2, 0) = 1;
  M(2, 1) = 3;
  M(2, 2) = 1;
  M(2, 3) = 5;
  M(2, 4) = 1;
  M(3, 0) = 0.11;
  M(3, 1) = 2;
  M(3, 2) = 0.3;
  M(3, 3) = 0.5;
  M(3, 4) = 1;
  M(4, 0) = 3;
  M(4, 1) = 2;
  M(4, 2) = 1;
  M(4, 3) = 3;
  M(4, 4) = 1;

  K(0, 0) = -40 / 337.0;
  K(0, 1) = -570 / 337.0;
  K(0, 2) = 0;
  K(0, 3) = 700 / 337.0;
  K(0, 4) = 480 / 337.0;
  K(1, 0) = -98 / 337.0;
  K(1, 1) = -2576 / 337.0;
  K(1, 2) = 1;
  K(1, 3) = 3400 / 337.0;
  K(1, 4) = 1513 / 337.0;
  K(2, 0) = 133 / 337.0;
  K(2, 1) = -211 / 337.0;
  K(2, 2) = 0;
  K(2, 3) = 200 / 337.0;
  K(2, 4) = 89 / 337.0;
  K(3, 0) = 9 / 337.0;
  K(3, 1) = 718 / 337.0;
  K(3, 2) = 0;
  K(3, 3) = -1000 / 337.0;
  K(3, 4) = -445 / 337.0;
  K(4, 0) = 156 / 337.0;
  K(4, 1) = 4919 / 337.0;
  K(4, 2) = -2;
  K(4, 3) = -6100 / 337.0;
  K(4, 4) = -2883 / 337.0;

  EXPECT_TRUE(K.EqMatrix(M.InverseMatrix()));
}

TEST_F(PublicMethods, test_Inverse_err) {
  S21Matrix M(2, 1);
  EXPECT_ANY_THROW(EXPECT_TRUE(M.InverseMatrix()(0, 0) == 0));
}

TEST_F(PublicMethods, test_Inverse_zerodet) {
  S21Matrix M(2, 2);

  M(0, 0) = 3;
  M(0, 1) = 3;
  M(1, 0) = 3;
  M(1, 1) = 3;

  EXPECT_ANY_THROW(EXPECT_TRUE(M.InverseMatrix()(0, 0) == 0));
}

// TEST_F(PublicMethods, test_Determinant_bignum) {
//   S21Matrix matrix1(3, 3);

//   matrix1(0, 0) = 9.05718e+07;
//   matrix1(0, 1) = 9.05718e+07;
//   matrix1(0, 2) = 9.05718e+07;

//   matrix1(1, 0) = 9.05718e+07;
//   matrix1(1, 1) = 9.05718e+07;
//   matrix1(1, 2) = 9.05718e+07;

//   matrix1(2, 0) = -9.0963e+07;
//   matrix1(2, 1) = -9.72731e+07;
//   matrix1(2, 2) = 1.16551e+07;

//   double result = matrix1.Determinant();
//   EXPECT_NEAR(result, 0, kS21_EPS);
// }
