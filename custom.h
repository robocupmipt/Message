#ifndef __CUSTOM_H__
#define __CUSTOM_H__

/* --------------------- Custom classes ------------------------ */

/*
 *
 * Input class for trasnmission
 *
*/

class Input
{
  public:
  float x, y;

  void Write(float x1, float y1);
  void Print();
};

/*
 *
 * Output class for receiving
 *
*/

class Output
{
  public:
  float x, y;

  void Write(float x1, float y1);
  void Print();
};

#endif /* __CUSTOM_H__ */
