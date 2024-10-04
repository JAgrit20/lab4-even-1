/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#include <string>

#include "Face.h"
#include "RealFace.h"
#include "Exceptions.h"

#include "gtest/gtest.h"

TEST(TestRealFace, defaultConstructorTest) {
  RealFace rFace;

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "0");
  EXPECT_NEAR(rFace.getValue(), 0.0, 0.5);
}

TEST(TestRealFace, realConstructorTest) {
  RealFace rFace(1.1);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "1.1");
  EXPECT_NEAR(rFace.getValue(), 1.1, 0.0000001);
}

TEST(TestRealFace, stringConstructorTest) {
  RealFace rFace("-1.2");

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-1.2");
  EXPECT_NEAR(rFace.getValue(), -1.2, 0.0000001);
}

TEST(TestRealFace, copyConstructorTest) {
  RealFace* rFace = new RealFace(2.2);
  RealFace copyFace(rFace);

  EXPECT_EQ(copyFace._TYPE, Face::REAL);
  EXPECT_EQ(copyFace.getDisplay(), "2.2");
  EXPECT_NEAR(copyFace.getValue(), 2.2, 0.0000001);

  delete rFace;
}

TEST(TestRealFace, realSetFaceTest) {
  RealFace rFace(-2.4);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-2.4");
  EXPECT_NEAR(rFace.getValue(), -2.4, 0.0000001);

  rFace.setFace(3.1);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "3.1");
  EXPECT_NEAR(rFace.getValue(), 3.1, 0.0000001);
}

TEST(TestRealFace, stringSetFaceTest) {
  RealFace rFace(-3.3);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-3.3");
  EXPECT_NEAR(rFace.getValue(), -3.3, 0.0000001);

  rFace.setFace("4.15");

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "4.15");
  EXPECT_NEAR(rFace.getValue(), 4.15, 0.0000001);
}

TEST(TestRealFace, emptyStringSetFaceTest) {
  RealFace rFace(-4.27);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-4.27");
  EXPECT_NEAR(rFace.getValue(), -4.27, 0.0000001);

  EXPECT_THROW(rFace.setFace(""), invalid_identifier);
}

TEST(TestRealFace, invalidSetFaceTest) {
  RealFace rFace(-4.27);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-4.27");
  EXPECT_NEAR(rFace.getValue(), -4.27, 0.0000001);

  EXPECT_THROW(rFace.setFace("two thirds"), invalid_identifier);
}

TEST(TestRealFace, positiveNumberMagnitudeTooLargeSetFaceTest) {
  RealFace rFace(-4.27);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-4.27");
  EXPECT_NEAR(rFace.getValue(), -4.27, 0.0000001);

  EXPECT_THROW(rFace.setFace(1000000), value_out_of_range);
}

TEST(TestRealFace, negativeNumberMagnitudeTooLargeSetFaceTest) {
  RealFace rFace(-4.27);

  EXPECT_EQ(rFace._TYPE, Face::REAL);
  EXPECT_EQ(rFace.getDisplay(), "-4.27");
  EXPECT_NEAR(rFace.getValue(), -4.27, 0.0000001);

  EXPECT_THROW(rFace.setFace("-1000000"), value_out_of_range);
}
