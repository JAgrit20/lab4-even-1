/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03, 2023-01-17
 */

#ifndef DIEFACTORY_H_INCLUDED
#define DIEFACTORY_H_INCLUDED

#include <string>
#include <vector>

#include "Die.h"
#include "Face.h"

/**
 * @class DieFactory DieFactory.h "DieFactory.h"
 * @brief A factory method used to create dice.
 */
class DieFactory {
 public:
  /**
   * @brief Default constructor, uses setDie.
   */
  DieFactory();

  /**
   * @brief Destructor
   */
  virtual ~DieFactory();

  /**
   * @brief Makes a die of the desired type with no faces.
   */
  virtual void setDie(unsigned randomSeed = 0) = 0;

  /**
   * @brief Makes a die with faces numbered from min to max of a given type.
   * @param[in] type The FaceType to be used for all faces.
   * @param[in] max The maximum value on the die.
   * @param[in] min The minimum value on the die.
   * @param[in] step The difference between one value and the next on the die.
   * @return A pointer to the newly constructed die.
   * @throw value_out_of_range If min is greater than max or step is negative.
   */
  Die* makeDie(Face::FaceType type = Face::INTEGER,
               float max = 6, float min = 1, float step = 1);

  /**
   * @brief Makes all the dice needed for a player of Wit Arcade (Dice at War).
   * @return a vector of dice.
   */
  virtual std::vector<Die*> makeWitArcadeDice() = 0;

 protected:
  Die* _construct;
  bool shipped;
};

/**
 * @class FairDieFactory DieFactory.h "DieFactory.h"
 * @brief A factory method used to create fair dice.
 */
class FairDieFactory : public DieFactory {
 public:
  /**
   * @brief Default constructor, uses setDie to make a fair die with the
   * identifier "Fair die".
   */
  FairDieFactory();

  /**
   * @brief Destructor
   */
  virtual ~FairDieFactory();

  void setDie(unsigned randomSeed = 0);

  std::vector<Die*> makeWitArcadeDice();
};

/**
 * @class SkewDieFactory DieFactory.h "DieFactory.h"
 * @brief 
 */
class SkewDieFactory : public DieFactory {
 public:
  /**
   * @brief Default constructor, uses setDie to make a skew die with the
   * identifier "Skew die".
   */
  SkewDieFactory();

  /**
   * @brief Destructor
   */
  virtual ~SkewDieFactory();

  void setDie(unsigned randomSeed = 0);

  std::vector<Die*> makeWitArcadeDice();
};

#endif //DIEFACTORY_H_INCLUDED
