/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#include <string>

#include "Face.h"
#include "IntegerFace.h"
#include "Exceptions.h"

#include "gtest/gtest.h"

TEST(TestIntegerFace, defaultConstructorTest) {
  IntegerFace iFace;

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "0");
  EXPECT_NEAR(iFace.getValue(), 0.0, 0.5);
}

TEST(TestIntegerFace, intConstructorTest) {
  IntegerFace iFace(1);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "1");
  EXPECT_NEAR(iFace.getValue(), 1.0, 0.5);
}

TEST(TestIntegerFace, stringConstructorTest) {
  IntegerFace iFace("-1");

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "-1");
  EXPECT_NEAR(iFace.getValue(), -1.0, 0.5);
}

TEST(TestIntegerFace, copyConstructorTest) {
  IntegerFace* iFace = new IntegerFace(2);
  IntegerFace copyFace(iFace);

  EXPECT_EQ(copyFace._TYPE, Face::INTEGER);
  EXPECT_EQ(copyFace.getDisplay(), "2");
  EXPECT_NEAR(copyFace.getValue(), 2.0, 0.5);

  delete iFace;
}

TEST(TestIntegerFace, intSetFaceTest) {
  IntegerFace iFace(-2);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "-2");
  EXPECT_NEAR(iFace.getValue(), -2.0, 0.5);

  iFace.setFace(3);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "3");
  EXPECT_NEAR(iFace.getValue(), 3.0, 0.5);
}

TEST(TestIntegerFace, stringSetFaceTest) {
  IntegerFace iFace(-3);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "-3");
  EXPECT_NEAR(iFace.getValue(), -3.0, 0.5);

  iFace.setFace("4");

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "4");
  EXPECT_NEAR(iFace.getValue(), 4.0, 0.5);
}

TEST(TestIntegerFace, emptyStringSetFaceTest) {
  IntegerFace iFace(-4);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "-4");
  EXPECT_NEAR(iFace.getValue(), -4.0, 0.5);

  EXPECT_THROW(iFace.setFace(""), invalid_identifier);
}

TEST(TestIntegerFace, invalidSetFaceTest) {
  IntegerFace iFace(-4);

  EXPECT_EQ(iFace._TYPE, Face::INTEGER);
  EXPECT_EQ(iFace.getDisplay(), "-4");
  EXPECT_NEAR(iFace.getValue(), -4.0, 0.5);

  EXPECT_THROW(iFace.setFace("five"), invalid_identifier);
}




