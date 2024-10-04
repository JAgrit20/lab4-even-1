/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-01, 2022-02, 2022-10
 */
#ifndef ROMANFACE_H_INCLUDED
#define ROMANFACE_H_INCLUDED

#include <map>
#include <string>

#include "Face.h"
/**
 * @class RomanFace RomanFace.h "RomanFace.h"
 * @brief A face that displays a roman number between 1 and
 * 3999 inclusively.
 */
class RomanFace : public Face {
 public:
  const int MAX_ROMAN_NUMBER = 3999;
  const std::map<int, std::string> ROMAN_VALUE
    = {{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"},
       {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"},
       {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};

  /**
   * @brief Default constructor, this function uses setFace.
   * @param[in] value an integer between 1 and
   * MAX_ROMAN_NUMBER
   */
  RomanFace(int value = 1);

  /**
   * @brief Constructor, this function uses setFace.
   * @param[in] display A roman numeral
   */
  RomanFace(std::string display);

  /**
   * @brief Copy constructor, this function uses setFace.
   * @param face a pointer to the face to be copied.
   */
  RomanFace(RomanFace* face);

  /**
   * @brief Default destructor
   */
  virtual ~RomanFace();

  /**
   * @brief Access the decimal value of the roman number.
   * @return the decimal value of the roman number.
   */
  float getValue() const;

  /**
   * @brief Modify the display of the face.
   * @param[in] display the new display of the face.
   */
  void setFace(std::string display);

  /**
   * @brief Modify the display.
   * @param[in] value the new value for the roman number.
   */
  void setFace(int value);

 private:
  /**
   * @brief Convert a roman number to a string.
   * @param[in] display the roman number.
   * @return the decimal equivalent to the roman numberal
   * @throw invalid_display if the roman number isn't in the
   * correct format, or doesn't have a properly formed roman
   * number .
   */
  int romanToDecimal(const std::string display) const;

  /**
   * @brief Convert from decimal to a Roman number.
   * @param[in] value an integer between 1 and
   * MAX_ROMAN-NUMBER
   * @return the roman number equivalent to the given value
   * @throw value_out_of_range if the value is less than 1
   * or greater than the MAX_ROMAN_NUMBER.
   */
  std::string decimalToRoman(int value) const;
};

#endif // ROMANFACE_H_INCLUDED
