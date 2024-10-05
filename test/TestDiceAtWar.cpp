/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2023-01-30
*/

#include <iostream>
#include <string>
#include <vector>

#include "Die.h"
#include "DiceAtWar.h"

#include "gtest/gtest.h"

TEST(TestDiceAtWar, defaultConstructorTest) {
  DiceAtWar daw;

  EXPECT_EQ(daw.getNumDice(0), 5);
  EXPECT_EQ(daw.getNumDice(1), 5);

  std::stringstream tempOut;
  daw.writeStandings(tempOut);

  std::string expectedString = "";
  expectedString  = "\n Computer) live pool: d2-d3-d4-d6-d12, used pool: empty";
  expectedString += "\n Human) live pool: d2-d3-d4-d6-d12, used pool: empty\n";

  EXPECT_EQ(tempOut.str(), expectedString);
}

TEST(TestDiceAtWar, writeRulesTest) {
  DiceAtWar daw;

  EXPECT_NO_THROW(daw.writeRules(std::cout));

  std::string fileName = "badFile.txt";
  EXPECT_THROW(daw.writeRules(std::cout, fileName.c_str()), invalid_object);
}

TEST(TestDiceAtWar, pickDieNumAndIdTest) {
  DiceAtWar daw;

  Die* die = daw.pickDie(0, "d2");

  EXPECT_EQ(die->getIdentifier(), "d2");

  delete die;

  die = daw.pickDie(1, "d4");

  EXPECT_EQ(die->getIdentifier(), "d4");

  delete die;
}

TEST(TestDiceAtWar, pickDieNumTest) {
  DiceAtWar daw;

  Die* die = daw.pickDie(0);

  EXPECT_EQ(die->getIdentifier(), "d2");

  delete die;

  die = daw.pickDie(1);

  EXPECT_EQ(die->getIdentifier(), "d2");

  delete die;
}


TEST(TestDiceAtWar, completeTurnTest) {
  DiceAtWar daw;

  //old one
  //Die* die0 = daw.pickDie(0, "d12");
  
  Die* die0 = daw.pickDie(0, "d4");
  Die* die1 = daw.pickDie(1, "d2");

  EXPECT_NO_THROW(daw.completeTurn(die0, die1));
}
