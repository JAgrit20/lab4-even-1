/**
* @author Dr. Anvik <john.anvik@uleth.ca>, LN Wilson <n.wilson@uleth.ca>
* @date 2018-09, 2020-10-03
*/

#ifndef EXCEPTIONS_H_INCLUDED
#define EXCEPTIONS_H_INCLUDED

#include <stdexcept>

/**
* @class container_full Exceptions.h "Exceptions.h"
* @brief Exception for when an object cannot accomodate an addition.
*/
class container_full: public std::runtime_error {
 public:
  /**
  * @brief Exception for when an object cannot accomodate an addition.
  * @param errMessage An error message.
  */
  explicit container_full(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class division_by_zero_error Exceptions.h "Exceptions.h"
* @brief Exception for attempting to divide by zero.
*/
class division_by_zero_error: public std::runtime_error {
 public:
  /**
  * @brief Exception for attempting to divide by zero.
  * @param errMessage An error message.
  */
  explicit division_by_zero_error(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class invalid_identifier Exceptions.h "Exceptions.h"
* @brief Exception for when an identifier has an invalid format.
*/
class invalid_identifier: public std::runtime_error {
 public:
  /**
  * Exception for when an identifier has an invalid format.
  * @param errMessage An error message.
  */
  explicit invalid_identifier(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class invalid_object Exceptions.h "Exceptions.h"
* @brief Exception for when an object is not ready to be used or has a problem.
*/
class invalid_object: public std::runtime_error {
 public:
  /**
  * @brief Exception for when an object is not ready to be used or has a problem.
  * @param errMessage An error message.
  */
  explicit invalid_object(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class mismatched_faces Exceptions.h "Exceptions.h"
* @brief Exception for attempting to sum faces that cannot be summed.
*/
class mismatched_faces: public std::runtime_error {
 public:
  /**
  * @brief Exception for attempting to divide by zero.
  * @param errMessage An error message.
  */
  explicit mismatched_faces(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};

/**
* @class value_out_of_range Exceptions.h "Exceptions.h"
* @brief Exception for when a value is not within the set of valid values.
*/
class value_out_of_range: public std::runtime_error {
 public:
  /**
  * Exception for when a value is not within the set of valid values.
  * @param errMessage An error message.
  */
  explicit value_out_of_range(const char* errMessage) :
    std::runtime_error(errMessage) {
  }
};
#endif //EXCEPTIONS_H_INCLUDED
