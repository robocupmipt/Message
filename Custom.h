//
// Created by Vladislav Molodtsov on 2019-03-31.
//

#ifndef __CUSTOM_H__
#define __CUSTOM_H__

/* --------------------- Custom classes ------------------------ */

/*
 *
 * You can change these on your own.
 *
 */

/*
 *
 * Input class for trasnmission
 *
*/

namespace message
{

class Receive
{
  public:

  float x = 0, y = 0;

  void Write(float x1, float y1);
  void Print();
};

/*
 *
 * Output class for receiving
 *
*/

class Send
{
  public:

  float x = 0, y = 0;

  void Write(float x1, float y1);
  void Print();
};

} /* namespace message */

#endif /* __CUSTOM_H__ */
