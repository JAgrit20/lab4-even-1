/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#ifndef SKEWDIE_H_INCLUDED
#define SKEWDIE_H_INCLUDED

#include <random>
#include <string>
#include <vector>

#include "Die.h"
#include "Face.h"
#include "SkewDie.h"

/**
 * @class SkewDie SkewDie.h "SkewDie.h"
 * @brief Implements a SkewDie, a die must have an appropriate number of faces.
 */
class SkewDie : public Die {
 public:
  /**
   * @brief Default constructor.
   * @param[in] identifier A very short description of the die.
   * @param[in] randomSeed The random seed used to initialize the randomizer.
   */
  SkewDie(std::string identifier = "a die", unsigned randomSeed = 0);

  /**
   * @brief Constructor with face, calls addFace.
   * @param[in] face A pointer to a face.
   * @param[in] identifier A very short description of the die.
   * @param[in] randomSeed The random seed used to initialize the randomizer.
   */
  SkewDie(Face* face, std::string identifier = "a die",
          unsigned randomSeed = 0);

  /**
   * @brief Copy constructor.
   * @param[in] die A pointer to a die.
   * @param[in] copyIdentifier A very short description of the die.
   * @param[in] randomSeed The random seed used to initialize the randomizer.
   */
  SkewDie(Die* die, std::string copyIdentifier = "copied die",
          unsigned randomSeed = 0);

  /**
   * @brief Default destructor.
   */
  virtual ~SkewDie();

  void roll();

 private:
  unsigned _randomSeed;
  std::default_random_engine _generator;
};

#endif // SKEWDIE_H_INCLUDED
