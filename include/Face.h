/**
* @author LN Wilson <n.wilson@uleth.ca>
* @date 2022-09-19, 2022-10-03, 2023-01-16
*/

#ifndef FACE_H_INCLUDED
#define FACE_H_INCLUDED

#include <string>

/**
 * @class Face Face.h "Face.h"
 * @brief Abstract class, base of all *Face classes.
 */
class Face {
 public:
  enum FaceType
  {DOTTED, FRACTION, INTEGER, INT_NAME, REAL, ROMAN, TALLY};

  /** Set on creation. */
  const FaceType _TYPE = INTEGER;

  /**
   * @brief Default constructor
   * @param[in] type one of the values in the enum FaceType,
   * matches subclass.
   */
  Face(FaceType type = INTEGER);

  /**
   * @brief Default destructor.
   */
  virtual ~Face();

  /**
   * @brief Access the identifier.
   * @return The identifier of the face.
   */
  const std::string getDisplay() const;

  /**
   * @brief Return the value of the face.
   * @return the value of the face.
   */
  virtual float getValue() const = 0;

  /**
   * @brief Set the identifier, throws an exception if the identifier is empty.
   * @details The identifier must be in the correct format for the FaceType. All
   * other member variables are set based on this input string.
   * @param[in] identifier The new identifier.
   * @throws invalid_identifier when the identifier is empty or not in the
   * correct format for the FaceType.
   */
  virtual void setFace(std::string identifier) = 0;

 protected:
  /** Currently a string, awaiting graphics department contributions. */
  std::string _identifier;
};

#endif // FACE_H_INCLUDED
