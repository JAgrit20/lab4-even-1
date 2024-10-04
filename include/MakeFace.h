/**
 * @author LN Wilson <n.wilson@uleth.ca>
 * @date 2022-10-17
 */

#ifndef MAKEFACE_H_INCLUDED
#define MAKEFACE_H_INCLUDED

#include "Face.h"
#include "FractionFace.h"
#include "IntegerFace.h"
#include "RealFace.h"
#include "RomanFace.h"
#include "Exceptions.h"

/**
 * @class MakeFace MakeFace.h "MakeFace.h"
 * @brief A Factory method to create faces.
 */
class MakeFace {
 public:
  /**
   * @brief Uses the correct Face class constructor to copy the given face.
   * @details If the type of the given face has not bee defined in copyFace
   * then a nullptr is returned;
   * @param[in] face A pointer to the face to be copied.
   * @return A pointer to the copied face or a nullptr.
   */
  static Face* copyFace(Face* face);

  /**
   * @brief Uses the correct Face class constructor to copy the given face.
   * @details If the type of the given face has not been defined in copyFace
   * then a nullptr is returned;
   * @param[in] face A pointer to the face to be copied.
   * @param[in] type the type of face desired
   * @return A pointer to the copied face or a nullptr.
   */
  static Face* copyFace(Face* face, Face::FaceType type);

  /**
   * @brief Uses the correct Face class constructor to create a face.
   * @details If the type of the given face has not been defined in getFace
   * then a nullptr is returned;
   * @param[in] type the type of face desired
   * @param[in] value the value of the desired face
   * @return A pointer to the face or a nullptr.
   */
  static Face* getFace(Face::FaceType type, float value);
};

#endif // MAKEFACE_H_INCLUDED
