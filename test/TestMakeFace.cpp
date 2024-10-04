/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2023-01-30
 */

#include <string>
#include <vector>

#include "Face.h"
#include "FractionFace.h"
#include "IntegerFace.h"
#include "RealFace.h"
#include "RomanFace.h"
#include "MakeFace.h"
#include "Exceptions.h"

#include "gtest/gtest.h"

std::vector<Face::FaceType> definedFaces
  = {Face::FRACTION, Face::INTEGER, Face::REAL, Face::ROMAN};

std::vector<Face::FaceType> undefinedFaces
  = {Face::DOTTED, Face::INT_NAME, Face::TALLY};

TEST(TestMakeFace, copyFractionFaceTest) {
  Face* sourceFace = new FractionFace("1/1");

  Face* copiedFace = MakeFace::copyFace(sourceFace);

  EXPECT_EQ(copiedFace->_TYPE, Face::FRACTION);
  EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

  delete copiedFace;

  for (std::vector<Face::FaceType>::iterator it = definedFaces.begin();
       it != definedFaces.end(); ++it) {
    copiedFace = MakeFace::copyFace(sourceFace, *it);

    EXPECT_EQ(copiedFace->_TYPE, *it);
    EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

    delete copiedFace;
  }

  for (std::vector<Face::FaceType>::iterator it = undefinedFaces.begin();
       it != undefinedFaces.end(); ++it) {
    EXPECT_THROW(MakeFace::copyFace(sourceFace, *it), invalid_object);
  }

  delete sourceFace;
}

TEST(TestMakeFace, copyIntegerFaceTest) {
  Face* sourceFace = new IntegerFace("1");

  Face* copiedFace = MakeFace::copyFace(sourceFace);

  EXPECT_EQ(copiedFace->_TYPE, Face::INTEGER);
  EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

  delete copiedFace;

  for (std::vector<Face::FaceType>::iterator it = definedFaces.begin();
       it != definedFaces.end(); ++it) {
    copiedFace = MakeFace::copyFace(sourceFace, *it);

    EXPECT_EQ(copiedFace->_TYPE, *it);
    EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

    delete copiedFace;
  }

  for (std::vector<Face::FaceType>::iterator it = undefinedFaces.begin();
       it != undefinedFaces.end(); ++it) {
    EXPECT_THROW(MakeFace::copyFace(sourceFace, *it), invalid_object);
  }

  delete sourceFace;
}

TEST(TestMakeFace, copyRealFaceTest) {
  Face* sourceFace = new RealFace("1");

  Face* copiedFace = MakeFace::copyFace(sourceFace);

  EXPECT_EQ(copiedFace->_TYPE, Face::REAL);
  EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

  delete copiedFace;

  for (std::vector<Face::FaceType>::iterator it = definedFaces.begin();
       it != definedFaces.end(); ++it) {
    copiedFace = MakeFace::copyFace(sourceFace, *it);

    EXPECT_EQ(copiedFace->_TYPE, *it);
    EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

    delete copiedFace;
  }

  for (std::vector<Face::FaceType>::iterator it = undefinedFaces.begin();
       it != undefinedFaces.end(); ++it) {
    EXPECT_THROW(MakeFace::copyFace(sourceFace, *it), invalid_object);
  }

  delete sourceFace;
}

TEST(TestMakeFace, copyRomanFaceTest) {
  Face* sourceFace = new RomanFace("I");

  Face* copiedFace = MakeFace::copyFace(sourceFace);

  EXPECT_EQ(copiedFace->_TYPE, Face::ROMAN);
  EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

  delete copiedFace;

  for (std::vector<Face::FaceType>::iterator it = definedFaces.begin();
       it != definedFaces.end(); ++it) {
    copiedFace = MakeFace::copyFace(sourceFace, *it);

    EXPECT_EQ(copiedFace->_TYPE, *it);
    EXPECT_NEAR(copiedFace->getValue(), 1.0, 0.5);

    delete copiedFace;
  }

  for (std::vector<Face::FaceType>::iterator it = undefinedFaces.begin();
       it != undefinedFaces.end(); ++it) {
    EXPECT_THROW(MakeFace::copyFace(sourceFace, *it), invalid_object);
  }

  delete sourceFace;
}

TEST(TestMakeFace, getFaceTest) {
  for (std::vector<Face::FaceType>::iterator it = definedFaces.begin();
       it != definedFaces.end(); ++it) {
    Face* createdFace = MakeFace::getFace(*it, 1.0);

    EXPECT_EQ(createdFace->_TYPE, *it);
    EXPECT_NEAR(createdFace->getValue(), 1.0, 0.5);

    delete createdFace;
  }
}

