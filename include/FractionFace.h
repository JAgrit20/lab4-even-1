/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2022-09-19, 2022-10-03, 2023-01-16
*/

#ifndef FRACTIONFACE_H_INCLUDED
#define FRACTIONFACE_H_INCLUDED

#include <string>

#include "Face.h"

/**
 * @class FractionFace FractionFace.h "FractionFace.h"
 * @brief Implements a Face that displays a valid fraction.
 */
class FractionFace : public Face {
 public:
  /**
   * @brief Default constructor, calls setFace.
   * @param[in] numerator the numerator of the fraction.
   * @param[in] denominator the denominator of the fraction.
   */
  FractionFace(int numerator = 0, int denominator = 1);

  /**
   * @brief Constructor with string, calls setFace.
   * @param[in] display a string display for the face.
   */
  FractionFace(std::string display);

  /**
   * @brief Copy Constructor, calls setFace.
   * @param[in] face A pointer to a FractionFace.
   */
  FractionFace(FractionFace* face);

  /**
   * @brief Default destructor.
   */
  virtual ~FractionFace();

  /**
   * @brief Access the numerator.
   * @return The numerator.
   */
  const int getNumerator() const;

  /**
   * @brief Access the denominator.
   * @return The denominator.
   */
  const int getDenominator() const;

  /**
   * @brief Calculate and return the real value equivalent
   * to the fraction.
   * @return The real value of the fraction.
   */
  float getValue() const;

  void setFace(std::string display);

  /**
   * @brief Set the fraction values and the display.
   * @param[in] numerator The numerator of the fraction.
   * @param[in] denominator The denominator of the fraction,
   * must be non-zero.
   * @throws division_by_zero_error if the denominator is 0.
   */
  void setFace(int numerator, int denominator);

 private:
  int _numerator;
  int _denominator;

  /**
   * @brief Determine the gcd of a and b.
   * @details Determine the gcd (greatest common divisor) of
   * two integers, a and b. If either of the parameters are
   * 0 then 0 is returned.
   * @param[in] a one of the two numbers
   * @param[in] b one of the two numbers
   * @return The gcd (greatest common divisor) of a and b.
   */
  int gcd(int a, int b);
};

#endif // FRACTIONFACE_H_INCLUDED
