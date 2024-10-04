/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#include <string>

#include "Face.h"
#include "FractionFace.h"
#include "Exceptions.h"

#include "gtest/gtest.h"

TEST(TestFractionFace, defaultConstructorTest) {
  FractionFace fFace;

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "0/1");
  EXPECT_EQ(fFace.getNumerator(), 0);
  EXPECT_EQ(fFace.getDenominator(), 1);
  EXPECT_NEAR(fFace.getValue(), 0.0, 0.0000001);
}

TEST(TestFractionFace, oneOfTwoParametersConstructorTest) {
  FractionFace fFace(1);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "1/1");
  EXPECT_EQ(fFace.getNumerator(), 1);
  EXPECT_EQ(fFace.getDenominator(), 1);
  EXPECT_NEAR(fFace.getValue(), 1.0, 0.0000001);
}

TEST(TestFractionFace, fractionConstructorTest) {
  FractionFace fFace(1, 2);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "1/2");
  EXPECT_EQ(fFace.getNumerator(), 1);
  EXPECT_EQ(fFace.getDenominator(), 2);
  EXPECT_NEAR(fFace.getValue(), 0.5, 0.0000001);
}

TEST(TestFractionFace, stringConstructorTest) {
  FractionFace fFace("2/1");

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "2/1");
  EXPECT_EQ(fFace.getNumerator(), 2);
  EXPECT_EQ(fFace.getDenominator(), 1);
  EXPECT_NEAR(fFace.getValue(), 2.0, 0.0000001);
}

TEST(TestFractionFace, copyConstructorTest) {
  FractionFace* fFace = new FractionFace(1, 8);
  FractionFace copyFace(fFace);

  EXPECT_EQ(copyFace._TYPE, Face::FRACTION);
  EXPECT_EQ(copyFace.getDisplay(), "1/8");
  EXPECT_EQ(copyFace.getNumerator(), 1);
  EXPECT_EQ(copyFace.getDenominator(), 8);
  EXPECT_NEAR(copyFace.getValue(), 0.125, 0.0000001);

  delete fFace;
}

TEST(TestFractionFace, fractionSetFaceTest) {
  FractionFace fFace(-1, 4);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "-1/4");
  EXPECT_EQ(fFace.getNumerator(), -1);
  EXPECT_EQ(fFace.getDenominator(), 4);
  EXPECT_NEAR(fFace.getValue(), -0.25, 0.0000001);

  fFace.setFace(3, 8);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "3/8");
  EXPECT_EQ(fFace.getNumerator(), 3);
  EXPECT_EQ(fFace.getDenominator(), 8);
  EXPECT_NEAR(fFace.getValue(), 0.375, 0.0000001);
}

TEST(TestFractionFace, stringSetFaceTest) {
  FractionFace fFace("7/8");

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "7/8");
  EXPECT_EQ(fFace.getNumerator(), 7);
  EXPECT_EQ(fFace.getDenominator(), 8);
  EXPECT_NEAR(fFace.getValue(), 0.875, 0.0000001);

  fFace.setFace("1/10");

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "1/10");
  EXPECT_EQ(fFace.getNumerator(), 1);
  EXPECT_EQ(fFace.getDenominator(), 10);
  EXPECT_NEAR(fFace.getValue(), 0.1, 0.0000001);
}

TEST(TestFractionFace, emptyStringSetFaceTest) {
  FractionFace fFace(-4, 5);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "-4/5");
  EXPECT_EQ(fFace.getNumerator(), -4);
  EXPECT_EQ(fFace.getDenominator(), 5);
  EXPECT_NEAR(fFace.getValue(), -0.8, 0.0000001);

  EXPECT_THROW(fFace.setFace(""), invalid_identifier);
}

TEST(TestFractionFace, invalidSetFaceTest) {
  FractionFace fFace(3, 2);

  EXPECT_EQ(fFace._TYPE, Face::FRACTION);
  EXPECT_EQ(fFace.getDisplay(), "3/2");
  EXPECT_EQ(fFace.getNumerator(), 3);
  EXPECT_EQ(fFace.getDenominator(), 2);
  EXPECT_NEAR(fFace.getValue(), 1.5, 0.0000001);

  EXPECT_THROW(fFace.setFace("1, 4"), invalid_identifier);
  EXPECT_THROW(fFace.setFace("1\4"), invalid_identifier);
  EXPECT_THROW(fFace.setFace("1|4"), invalid_identifier);
  EXPECT_THROW(fFace.setFace("1:4"), invalid_identifier);
  EXPECT_THROW(fFace.setFace("one quarter"), invalid_identifier);
}

TEST(TestFractionFace, reduceFractionsTests) {
  FractionFace fFace(0, 7);

  EXPECT_EQ(fFace.getNumerator(), 0);
  EXPECT_EQ(fFace.getDenominator(), 1);

  fFace.setFace(2 * 2, 2);

  EXPECT_EQ(fFace.getNumerator(), 2);
  EXPECT_EQ(fFace.getDenominator(), 1);

  fFace.setFace(11, 11);

  EXPECT_EQ(fFace.getNumerator(), 1);
  EXPECT_EQ(fFace.getDenominator(), 1);

  fFace.setFace(3 * 4, 4 * 4);

  EXPECT_EQ(fFace.getNumerator(), 3);
  EXPECT_EQ(fFace.getDenominator(), 4);

  fFace.setFace(-1, 2);

  EXPECT_EQ(fFace.getNumerator(), -1);
  EXPECT_EQ(fFace.getDenominator(), 2);

  fFace.setFace(-1, -2);

  EXPECT_EQ(fFace.getNumerator(), 1);
  EXPECT_EQ(fFace.getDenominator(), 2);

  fFace.setFace(1, -2);

  EXPECT_EQ(fFace.getNumerator(), -1);
  EXPECT_EQ(fFace.getDenominator(), 2);

  fFace.setFace(2 * 3 * 5 * 11, -2 * 5 * 7 * 11);

  EXPECT_EQ(fFace.getNumerator(), -3);
  EXPECT_EQ(fFace.getDenominator(), 7);
}

TEST(TestFractionFace, setDenominatorToZeroTest) {
  FractionFace fFace;

  EXPECT_THROW(fFace.setFace(1, 0), division_by_zero_error);
  EXPECT_THROW(fFace.setFace("3/0"), division_by_zero_error);
}
