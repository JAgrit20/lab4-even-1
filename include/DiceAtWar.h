/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2023-01-30
*/

#ifndef DICEATWAR_H_INCLUDED
#define DICEATWAR_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include "DiceSet.h"
#include "Die.h"

/**
 * @class DiceAtWar DiceAtWar.h "DiceAtWar.h"
 * @brief Abstract base class for dice.
 */
class DiceAtWar {
 public:
  const std::string STANDARD_RULES = "rules.txt";

  /**
   * @brief Set up the game.
   * @details Create two die sets, one for the human player, playerNumber 0, and
   * and one for the computer player, playerNumber 1.
   * the computer player.
   */
  DiceAtWar();

  /**
   * @brief Destructor
   */
  virtual ~DiceAtWar();

  /**
   * @brief Display the rules.
   * @details If a filename isn't given then the standard rules are displayed.
   * @param[inout] out the output stream to be used for displaying the rules.
   * @param[in] filename the filename of the rules to be displayed.
   * @throw invalid_object if the filename doesn't correspond to a file.
   */
  void writeRules(std::ostream& out, std::string filename = "");

  /**
   * @brief Display current state of the game.
   * @details Display all the player pools and, if it isn't empty, the prize
   * pool.
   * @param[inout] out the output stream to be used for displaying the rules.
   */
  void writeStandings(std::ostream& out);

  /**
   * @brief Access the total number of dice that belong to a player.
   * @param[in] playerNumber the player whose info is desired.
   * @return The total number of dice a player has available.
   */
  unsigned getNumDice(unsigned playerNumber);

  /**
   * @brief Picks a die.
   * @details If the identifier doesn't exist then nullptr is returned.
   * @param[in] playerNumber Which dice pool to pick from.
   * @param[in] identifier The identifier of the desired die.
   * @return The die chosen.
   */
  Die* pickDie(unsigned playerNumber, std::string identifier);

  /**
   * @brief Picks an arbitrary die.
   * @return The die chosen.
   */
  Die* pickDie(unsigned playerNumber);

  /**
   * @brief Resolve turn.
   * @details If the player wins then "You won that turn." is returned. If the
   * computer wins then then "You lost that turn." is returned. If it is a tie
   * then "It's a tie, this means WAR!" is returned. Dice are moved to
   * appropriate pools.
   * @param[in] humansDie The die chosen by the human player.
   * @param[in] computersDie The die chosen by the computer player.
   * @return The current standing of the turn as a string.
   */
  std::string completeTurn(Die* humansDie, Die* computersDie);

 private:
  std::vector<DiceSet*> playersLivePool;
  std::vector<DiceSet*> playersUsedPool;
  DiceSet* prizePool;
};

#endif //DICEATWAR_H_INCLUDED
