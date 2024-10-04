/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#include <string>

#include "Face.h"
#include "RomanFace.h"
#include "Exceptions.h"

#include "gtest/gtest.h"

TEST(TestRomanFace, defaultConstructorTest) {
  RomanFace rFace;

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "I");
  EXPECT_NEAR(rFace.getValue(), 1.0, 0.5);
}

TEST(TestRomanFace, intConstructorTest) {
  RomanFace rFace(1);

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "I");
  EXPECT_NEAR(rFace.getValue(), 1.0, 0.5);
}

TEST(TestRomanFace, stringConstructorTest) {
  RomanFace rFace("II");

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "II");
  EXPECT_NEAR(rFace.getValue(), 2.0, 0.5);
}

TEST(TestRomanFace, copyConstructorTest) {
  RomanFace* rFace = new RomanFace(4);
  RomanFace copyFace(rFace);

  EXPECT_EQ(copyFace._TYPE, Face::ROMAN);
  EXPECT_EQ(copyFace.getDisplay(), "IV");
  EXPECT_NEAR(copyFace.getValue(), 4.0, 0.5);

  delete rFace;
}

TEST(TestRomanFace, intSetFaceTest) {
  RomanFace rFace(5);

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "V");
  EXPECT_NEAR(rFace.getValue(), 5.0, 0.5);

  rFace.setFace(6);

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "VI");
  EXPECT_NEAR(rFace.getValue(), 6.0, 0.5);
}

TEST(TestRomanFace, stringSetFaceTest) {
  RomanFace rFace(8);

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "VIII");
  EXPECT_NEAR(rFace.getValue(), 8.0, 0.5);

  rFace.setFace("IX");

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "IX");
  EXPECT_NEAR(rFace.getValue(), 9.0, 0.5);
}


TEST(TestRomanFace, wrongCaseStringSetFaceTest) {
  RomanFace rFace("xiii");

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "XIII");
  EXPECT_NEAR(rFace.getValue(), 13.0, 0.5);

  rFace.setFace("lX");

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "LX");
  EXPECT_NEAR(rFace.getValue(), 60.0, 0.5);
}

TEST(TestRomanFace, emptyStringSetFaceTest) {
  RomanFace rFace(100);

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "C");
  EXPECT_NEAR(rFace.getValue(), 100.0, 0.5);

  EXPECT_THROW(rFace.setFace(""), invalid_identifier);
}

TEST(TestRomanFace, invalidIdentifierSetFaceTest) {
  RomanFace rFace("MDCLXVI");

  EXPECT_EQ(rFace._TYPE, Face::ROMAN);
  EXPECT_EQ(rFace.getDisplay(), "MDCLXVI");
  EXPECT_NEAR(rFace.getValue(), 1666.0, 0.5);

  EXPECT_THROW(rFace.setFace("IIII"), invalid_identifier);
  EXPECT_THROW(rFace.setFace("IM"), invalid_identifier);
  EXPECT_THROW(rFace.setFace("IVXDCM"), invalid_identifier);
  EXPECT_THROW(rFace.setFace("A"), invalid_identifier);
  EXPECT_THROW(rFace.setFace("IAI"), invalid_identifier);
}

TEST(TestRomanFace, maxValueTest) {
  RomanFace rFace(3999);

  EXPECT_EQ(rFace.getDisplay(), "MMMCMXCIX");
  EXPECT_NEAR(rFace.getValue(), 3999.0, 0.5);

  rFace.setFace("MMMCMXCIX");

  EXPECT_EQ(rFace.getDisplay(), "MMMCMXCIX");
  EXPECT_NEAR(rFace.getValue(), 3999.0, 0.5);
}

TEST(TestRomanFace, outOfBoundsTest) {
  RomanFace rFace;

  EXPECT_THROW(rFace.setFace(0), value_out_of_range);
  EXPECT_THROW(rFace.setFace(4000), value_out_of_range);
  EXPECT_THROW(rFace.setFace("MMMM"), invalid_identifier);
}






