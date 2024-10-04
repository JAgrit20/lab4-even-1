/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2022-09-19, 2022-10-03
*/

#ifndef REALFACE_H_INCLUDED
#define REALFACE_H_INCLUDED

#include <string>

#include "Face.h"

/**
 * @class RealFace RealFace.h "RealFace.h"
 * @brief Implements a Face that displays a real.
 * @details The magnitude of the value must be less than 1000000 and the value
 * will be rounded to 6 decimal places.
 */
class RealFace : public Face {
 public:
  /**
   * @brief Default constructor, calls setFace.
   * @param[in] value the real.
   */
  RealFace(float value = 0);

  /**
   * @brief Constructor with string, calls setFace.
   * @param[in] display a string display for the face.
   */
  RealFace(std::string display);

  /**
   * @brief Copy constructor, calls setFace.
   * @param[in] face A pointer to a RealFace.
   */
  RealFace(RealFace* face);

  /**
   * @brief Default destructor.
   */
  virtual ~RealFace();

  /**
   * @brief Access the value on the face.
   * @return The value of the face.
   */
  float getValue() const;

  void setFace(std::string display);

  /**
   * @brief Set the number value and the display.
   * @param[in] value The number on the face.
   * @throw value_out of range if the magnitude of value exceeds 1000000.
   */
  void setFace(float value);

 private:
  float _value;
};

#endif // REALFACE_H_INCLUDED
