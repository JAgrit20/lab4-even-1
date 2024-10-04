/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-09-19, 2022-10-03
 */

#ifndef INTEGERFACE_H_INCLUDED
#define INTEGERFACE_H_INCLUDED

#include <string>

#include "Face.h"

/**
 * @class IntegerFace IntegerFace.h "IntegerFace.h"
 * @brief Implements a Face that displays an integer.
 */
class IntegerFace : public Face {
 public:
  /**
   * @brief Default constructor, calls setFace.
   * @param[in] value the number on the face.
   */
  IntegerFace(int value = 0);

  /**
   * @brief Constructor with string, calls setFace.
   * @param[in] display a string display for the face.
   */
  IntegerFace(std::string display);

  /**
   * @brief Copy constructor.
   * @param[in] face A pointer to an IntegerFace.
   */
  IntegerFace(IntegerFace* face);

  /**
   * @brief Default destructor.
   */
  virtual ~IntegerFace();

  /**
   * @brief Return the value of the face.
   * @return the value of the face.
   */
  float getValue() const;

  void setFace(std::string display);

  /**
   * @brief Set the integer value and the display.
   * @param[in] value The integer on the face.
   */
  void setFace(int value);

 private:
  int _value;
};

#endif // INTEGERFACE_H_INCLUDED
