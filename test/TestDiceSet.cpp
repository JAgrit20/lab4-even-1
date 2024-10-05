/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2023-01-30
*/

#include <string>
#include <vector>

#include "Die.h"
#include "FairDie.h"
#include "DiceSet.h"

#include "gtest/gtest.h"

TEST(TestDiceSet, defaultConstructorTest) {
  DiceSet set;

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");
}

TEST(TestDiceSet, constructorTest) {
  std::vector<Die*> someDice;

  for (unsigned i = 0; i < 3; ++i)
    someDice.push_back(new FairDie("Die" + std::to_string(i + 1)));

  DiceSet set(someDice);

  EXPECT_EQ(set.getNumDice(), 3);
  EXPECT_EQ(set.listDice(), "Die1-Die2-Die3");
}

TEST(TestDiceSet, addDieTest) {
  DiceSet set;

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");

  set.addDie(new FairDie("one"));

  EXPECT_EQ(set.getNumDice(), 1);
  EXPECT_EQ(set.listDice(), "one");

  set.addDie(new FairDie("two"));

  EXPECT_EQ(set.getNumDice(), 2);
  EXPECT_EQ(set.listDice(), "one-two");
}

TEST(TestDiceSet, invalidAddSameDieTwiceTest) {
  DiceSet set;

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");

  Die* die = new FairDie("die");

  EXPECT_NO_THROW(set.addDie(die));
  EXPECT_THROW(set.addDie(die), invalid_object);
}

TEST(TestDiceSet, addSameIdentifierDieTest) {
  DiceSet set;

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");

  set.addDie(new FairDie("die"));

  EXPECT_EQ(set.getNumDice(), 1);
  EXPECT_EQ(set.listDice(), "die");

  set.addDie(new FairDie("die"));

  EXPECT_EQ(set.getNumDice(), 2);
  EXPECT_EQ(set.listDice(), "die-die^");
}

TEST(TestDiceSet, unsuccessfulAddDieTest) {
  DiceSet set;

  EXPECT_THROW(set.addDie(nullptr), invalid_object);
}

TEST(TestDiceSet, successfulRemoveDieTest) {
  std::vector<Die*> someDice;

  for (unsigned i = 0; i < 3; ++i)
    someDice.push_back(new FairDie("Die" + std::to_string(i + 1)));

  DiceSet set(someDice);

  EXPECT_EQ(set.getNumDice(), 3);
  EXPECT_EQ(set.listDice(), "Die1-Die2-Die3");

  Die* die = set.removeDie("Die2");

  EXPECT_EQ(set.getNumDice(), 2);
  EXPECT_EQ(set.listDice(), "Die1-Die3");

  delete die;

  die = set.removeDie("Die1");

  EXPECT_EQ(set.getNumDice(), 1);
  EXPECT_EQ(set.listDice(), "Die3");

  delete die;

  die = set.removeDie("Die3");

  std::cout << "after removing Die3: " << set.listDice() << std::endl;

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");

  delete die;

  die = set.removeDie("empty");

  EXPECT_EQ(set.getNumDice(), 0);
  EXPECT_EQ(set.listDice(), "empty");

  delete die;
}

TEST(TestDiceSet, unsuccessfulRemoveDieFromEmptySetTest) {
  DiceSet emptySet;

  Die* die = emptySet.removeDie("empty");

  EXPECT_EQ(die, nullptr);
}

TEST(TestDiceSet, unsuccessfulRemoveDieFromNonEmptySetTest) {
  std::vector<Die*> someDice;

  for (unsigned i = 0; i < 3; ++i)
    someDice.push_back(new FairDie("Die" + std::to_string(i + 1)));

  DiceSet set(someDice);

  EXPECT_EQ(set.getNumDice(), 3);
  EXPECT_EQ(set.listDice(), "Die1-Die2-Die3");

  Die* die = set.removeDie("one");

  EXPECT_EQ(die, nullptr);
}


TEST(TestDiceSet, transferDiceToTest) {
  std::vector<Die*> someDice;

  for (unsigned i = 0; i < 3; ++i)
    someDice.push_back(new FairDie("Die" + std::to_string(i + 1)));

  DiceSet* source = new DiceSet(someDice);
  DiceSet* destination = new DiceSet();

  EXPECT_EQ(source->getNumDice(), 3);
  EXPECT_EQ(source->listDice(), "Die1-Die2-Die3");

  EXPECT_EQ(destination->getNumDice(), 0);
  EXPECT_EQ(destination->listDice(), "empty");

  source->transferDiceTo(destination);

  EXPECT_EQ(source->getNumDice(), 0);
  EXPECT_EQ(source->listDice(), "empty");

  EXPECT_EQ(destination->getNumDice(), 3);
  EXPECT_EQ(destination->listDice(), "Die1-Die2-Die3");

  delete source;
  delete destination;
}
