/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2023-01-30
*/

#ifndef DICESET_H_INCLUDED
#define DICESET_H_INCLUDED

#include <string>
#include <vector>

#include "Die.h"
/**
 * @class DiceSet DiceSet.h, "DiceSet.h"
 * @brief A class that implements a set of dice.
 */
class DiceSet {
 public:
  /**
   * @brief Default constructor
   */
  DiceSet();

  /**
   * @brief Constructor
   * @param[in] dice a vector of dice
   */
  DiceSet(std::vector<Die*> dice);

  /**
   * @brief Destructor
   */
  virtual ~DiceSet();

  /**
   * @brief Add the die to the dice.
   * @param die a pointer to a die.
   * @throw invalid_object if die is a nullptr.
   */
  void addDie(Die* die);

  /**
   * @brief Find and remove a die from dice.
   * @param identifier the identifier of the desired die.
   * @return A pointer to the desired die or nullptr if the die couldn't be
   *   found.
   */
  Die* removeDie(std::string identifier);

  /**
   * @brief Move all of this set's dice to the given DiceSet.
   * @param destination The DiceSet all the dice are moving to.
   */
  void transferDiceTo(DiceSet* destination);

  /**
   * @brief A dash (-) delimited list of identifiers of the dice.
   * @details If there are no dice then "empty" is returned.
   * @return the list of die identifiers.
   */
  std::string listDice() const;

  /**
   * @brief Access the number of dice.
   * @return the number of dice.
   */
  int getNumDice() const;

 private:
  std::vector<Die*> _dice;
};

#endif //DICESET_H_INCLUDED
