/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2022-09-19, 2022-10-08
*/

#ifndef DIE_H_INCLUDED
#define DIE_H_INCLUDED

#include <string>
#include <vector>

#include "Face.h"
#include "MakeFace.h"

/**
 * @class Die Die.h "Die.h"
 * @brief Abstract base class for dice.
 */
class Die {
 public:
  /**
   * @brief Default constructor.
   * @param[in] identifier A very short description of the die.
   * @param[in] randomSeed The random seed used to initialize the randomizer.
   */
  Die(std::string identifier = "a die", unsigned randomSeed = 0);

  /**
   * @brief Copy constructor.
   * @param[in] die A pointer to a die.
   * @param[in] copyIdentifier A very short description of the die.
   * @param[in] randomSeed The random seed used to initialize the randomizer.
   */
  Die(Die* die, std::string copyIdentifier = "copied die",
      unsigned randomSeed = 0);

  /**
   * @brief Default destructor.
   */
  virtual ~Die();

  /**
   * @brief Access the identifier of the die.
   * @return The identifier of the die.
   */
  const std::string getIdentifier() const;

  /**
   * @brief Access the number of faces in the die.
   * @return The number of faces.
   */
  const int getNumFaces() const;

  /**
   * @brief Modify the identifier of the die.
   * @param[in] identifier a new identifier for the die.
   * @throw invalid_identifier if the new identifier is an
   * empty string
   */
  void setIdentifier(std::string identifier);

  /**
   * @brief Add a copy of face to the die.
   * @details The new face becomes the new top of the die.
   * @param[in] face A pointer to the face to be copied.
   */
  virtual void addFace(Face* face);

  /**
   * @brief Display the die.
   * @details Returns an appropriate string for identifier
   * and the top of the die.
   * @return A string display of the die's top.
   * @throw invalid_object if there are no faces on the die
   */
  virtual const std::string getDisplay() const;

  /**
   * @brief Access the top of the die.
   * @return a pointer to the top of the die.
   * @throw invalid_object if there are no faces on the die
   */
  const Face* getTop() const;

  /**
   * @brief Access all the faces on the die.
   * @return a string showing all the faces on the die.
   * @throw invalid_object if there are no faces on the die
   */
  const std::string getAllFaces() const;

  /**
   * @brief Roll the die.
   * @details Use a random engine to set the top of the die.
   * @throw invalid_object if there are no faces on the die
   */
  virtual void roll() = 0;

 protected:
  unsigned _randomSeed;
  unsigned _top;
  std::vector<Face*> _faces;
  std::string _identifier;
};

#endif // DIE_H_INCLUDED
