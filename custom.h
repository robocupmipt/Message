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

  long type;

  float x = 0, y = 0;

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

  long type;

  float x = 0, y = 0;

  void Write(float x1, float y1);
  void Print();
};

#endif /* __CUSTOM_H__ */
