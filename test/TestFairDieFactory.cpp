/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03, 2023-01-17
 */

#include <string>

#include "Die.h"
#include "FairDie.h"
#include "SkewDie.h"
#include "DieFactory.h"
#include "Face.h"

#include "gtest/gtest.h"

TEST(TestFairDieFactory, makeValidDie) {
  FairDieFactory df;
  Die* d = df.makeDie(Face::REAL, 6, 1, 1);

  EXPECT_EQ(d->getIdentifier(), "Fair die");
  EXPECT_EQ(d->getNumFaces(), 6);
  EXPECT_EQ(d->getTop()->_TYPE, Face::REAL);
  EXPECT_NEAR(d->getTop()->getValue(), 6.0, 0.5);

  delete d;
}

TEST(TestFairDieFactory, makeMinGreaterThanMaxDie) {
  FairDieFactory df;
  EXPECT_THROW(df.makeDie(Face::REAL, 1, 6, 1), value_out_of_range);
}

TEST(TestFairDieFactory, makeNegativeStepDie) {
  FairDieFactory df;
  EXPECT_THROW(df.makeDie(Face::REAL, 6, 1, -1), value_out_of_range);
}

TEST(TestFairDieFactory, makeMinGreaterThanMaxAndNegativeStepDie) {
  FairDieFactory df;
  EXPECT_THROW(df.makeDie(Face::REAL, 1, 6, -1), value_out_of_range);
}

TEST(TestFairDieFactory, makeWitArcadeDiceTest) {
  FairDieFactory df;
  std::vector<Die*> gameDice = df.makeWitArcadeDice();

  EXPECT_EQ(gameDice.size(), 5);

  EXPECT_EQ(gameDice[0]->getNumFaces(), 2);
  EXPECT_EQ(gameDice[1]->getNumFaces(), 3);
  EXPECT_EQ(gameDice[2]->getNumFaces(), 4);
  EXPECT_EQ(gameDice[3]->getNumFaces(), 6);
  EXPECT_EQ(gameDice[4]->getNumFaces(), 12);

  for (std::vector<Die*>::iterator it = gameDice.begin();
       it != gameDice.end(); ++it)
    delete *it;
}




