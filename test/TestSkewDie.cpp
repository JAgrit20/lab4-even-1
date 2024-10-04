/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#include <time.h>

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "SkewDie.h"
#include "Exceptions.h"
#include "Face.h"

#include "gtest/gtest.h"

TEST(TestSkewDie, defaultConstructorTest) {
  SkewDie sd;

  EXPECT_EQ(sd.getIdentifier(), "a die");
  EXPECT_EQ(sd.getNumFaces(), 0);
  EXPECT_THROW(sd.getDisplay(), invalid_object);
  EXPECT_THROW(sd.getTop(), invalid_object);
  EXPECT_THROW(sd.roll(), invalid_object);
}

TEST(TestSkewDie, stringConstructorTest) {
  SkewDie sd("green die");

  EXPECT_EQ(sd.getIdentifier(), "green die");
  EXPECT_EQ(sd.getNumFaces(), 0);
  EXPECT_THROW(sd.getDisplay(), invalid_object);
  EXPECT_THROW(sd.getTop(), invalid_object);
  EXPECT_THROW(sd.roll(), invalid_object);
}


TEST(TestSkewDie, stringAndSeedConstructorTest) {
  SkewDie sd("blue die", 314159);

  EXPECT_EQ(sd.getIdentifier(), "blue die");
  EXPECT_EQ(sd.getNumFaces(), 0);
  EXPECT_THROW(sd.getDisplay(), invalid_object);
  EXPECT_THROW(sd.getTop(), invalid_object);
  EXPECT_THROW(sd.roll(), invalid_object);
}

TEST(TestSkewDie, faceAndStringConstructorTest) {
  Face* iFace = new IntegerFace(1);
  SkewDie sd(iFace, "duck die");

  EXPECT_EQ(sd.getIdentifier(), "duck die");
  EXPECT_EQ(sd.getNumFaces(), 1);
  EXPECT_EQ(sd.getDisplay(), "duck die:1");
  EXPECT_EQ(sd.getTop()->getDisplay(), "1");
  EXPECT_NO_THROW(sd.roll());

  delete iFace;
}

TEST(TestSkewDie, faceStringAndSeedConstructorTest) {
  Face* iFace = new IntegerFace(-2);
  SkewDie sd(iFace, "leaf die", 777317);

  EXPECT_EQ(sd.getIdentifier(), "leaf die");
  EXPECT_EQ(sd.getNumFaces(), 1);
  EXPECT_EQ(sd.getDisplay(), "leaf die:-2");
  EXPECT_EQ(sd.getTop()->getDisplay(), "-2");
  EXPECT_NO_THROW(sd.roll());

  delete iFace;
}

TEST(TestSkewDie, copyConstructorTest) {
  Face* iFace = new IntegerFace(3);
  SkewDie* sourceDie = new SkewDie(iFace, "source die", 511111);

  EXPECT_EQ(sourceDie->getIdentifier(), "source die");
  EXPECT_EQ(sourceDie->getNumFaces(), 1);
  EXPECT_EQ(sourceDie->getDisplay(), "source die:3");
  EXPECT_EQ(sourceDie->getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(sourceDie->roll());

  SkewDie copiedDie(sourceDie);

  EXPECT_EQ(copiedDie.getIdentifier(), "copied die");
  EXPECT_EQ(copiedDie.getNumFaces(), 1);
  EXPECT_EQ(copiedDie.getDisplay(), "copied die:3");
  EXPECT_EQ(copiedDie.getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(copiedDie.roll());

  delete iFace;
  delete sourceDie;
}


TEST(TestSkewDie, copyConstructorWithNewIdentifierTest) {
  Face* iFace = new IntegerFace(3);
  SkewDie* sourceDie = new SkewDie(iFace, "source die", 511111);

  EXPECT_EQ(sourceDie->getIdentifier(), "source die");
  EXPECT_EQ(sourceDie->getNumFaces(), 1);
  EXPECT_EQ(sourceDie->getDisplay(), "source die:3");
  EXPECT_EQ(sourceDie->getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(sourceDie->roll());

  SkewDie copiedDie(sourceDie, "newly copied die");

  EXPECT_EQ(copiedDie.getIdentifier(), "newly copied die");
  EXPECT_EQ(copiedDie.getNumFaces(), 1);
  EXPECT_EQ(copiedDie.getDisplay(), "newly copied die:3");
  EXPECT_EQ(copiedDie.getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(copiedDie.roll());

  delete iFace;
  delete sourceDie;
}


TEST(TestSkewDie, copyConstructorWithNewIdentifierAndSeedTest) {
  Face* iFace = new IntegerFace(3);
  SkewDie* sourceDie = new SkewDie(iFace, "source die", 511111);

  EXPECT_EQ(sourceDie->getIdentifier(), "source die");
  EXPECT_EQ(sourceDie->getNumFaces(), 1);
  EXPECT_EQ(sourceDie->getDisplay(), "source die:3");
  EXPECT_EQ(sourceDie->getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(sourceDie->roll());

  SkewDie copiedDie(sourceDie, "destination die", 999983);

  EXPECT_EQ(copiedDie.getIdentifier(), "destination die");
  EXPECT_EQ(copiedDie.getNumFaces(), 1);
  EXPECT_EQ(copiedDie.getDisplay(), "destination die:3");
  EXPECT_EQ(copiedDie.getTop()->getDisplay(), "3");
  EXPECT_NO_THROW(copiedDie.roll());

  delete iFace;
  delete sourceDie;
}

TEST(TestSkewDie, setIdentifierTest) {
  SkewDie sd("rename me die");

  EXPECT_EQ(sd.getIdentifier(), "rename me die");
  EXPECT_EQ(sd.getNumFaces(), 0);

  sd.setIdentifier("renamed");

  EXPECT_EQ(sd.getIdentifier(), "renamed");
  EXPECT_EQ(sd.getNumFaces(), 0);
}

TEST(TestSkewDie, invalidSetIdentifierTest) {
  SkewDie sd("rename me die");

  EXPECT_EQ(sd.getIdentifier(), "rename me die");
  EXPECT_EQ(sd.getNumFaces(), 0);

  EXPECT_THROW(sd.setIdentifier(""), invalid_identifier);
}

TEST(TestSkewDie, addFacesTest) {
  SkewDie sd("giant die");

  EXPECT_EQ(sd.getIdentifier(), "giant die");
  EXPECT_EQ(sd.getNumFaces(), 0);

  Face* iFace = new IntegerFace(0);
  sd.addFace(iFace);
  delete iFace;

  EXPECT_EQ(sd.getNumFaces(), 1);
  EXPECT_EQ(sd.getDisplay(), "giant die:0");
  EXPECT_EQ(sd.getTop()->getDisplay(), "0");
  EXPECT_NO_THROW(sd.roll());

  iFace = new IntegerFace(1);
  sd.addFace(iFace);
  delete iFace;

  EXPECT_EQ(sd.getNumFaces(), 2);
  EXPECT_EQ(sd.getDisplay(), "giant die:1");
  EXPECT_EQ(sd.getTop()->getDisplay(), "1");
  EXPECT_NO_THROW(sd.roll());
}

TEST(TestSkewDie, rollDistributionTest) {
  SkewDie sd("test die");

  for (unsigned i = 0; i < 20; ++i) {
    Face* iFace = new IntegerFace(i);
    sd.addFace(iFace);
    delete iFace;
  }

  std::vector<int> tally(20, 0);

  for (unsigned i = 0; i < 1000; ++i) {
    sd.roll();
    tally[static_cast<int>(sd.getTop()->getValue())]++;
  }

  for (unsigned i = 0; i < 20; ++i) {
    std::cout << std::setw(2) << std::right << i << " : ";
    for (int k = 0; k < tally[i] / 10; ++k)
      std::cout << '*';
    std::cout << '\n';
  }
}
