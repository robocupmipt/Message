#include"custom.h"
#include"iostream"

/* --------------------- Custom classes ------------------------ */

/*
 *
 * Input class for trasnmission
 *
*/

void Input::Print()
{
  std::cout << "(x,y) = (" << x << ", " << y << ")" << std::endl;
}

void Input::Write(float x1, float y1)
{
  x = x1;
  y = y1;
}

/*
 *
 * Output class for receiving
 *
*/

void Output::Print()
{
  std::cout << "(x,y) = (" << x << ", " << y << ")" << std::endl;
}

void Output::Write(float x1, float y1)
{
  x = x1;
  y = y1;
}

