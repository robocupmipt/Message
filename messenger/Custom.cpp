//
// Created by Vladislav Molodtsov on 2019-03-31.
//

#include"Custom.h"
#include"iostream"

/* --------------------- Custom classes ------------------------ */

/*
 *
 * You can change these on your own.
 *
 */

/*
 *
 * Receive class for receiving
 *
*/

using namespace message;

void Receive::Print()
{
  std::cout << "(x,y) = (" << x << ", " << y << ")" << std::endl;
}

void Receive::Write(float x1, float y1)
{
  x = x1;
  y = y1;
}

/*
 *
 * Send class for trasnmission
 *
*/

void Send::Print()
{
  std::cout << "(x,y) = (" << x << ", " << y << ")" << std::endl;
}

void Send::Write(float x1, float y1)
{
  x = x1;
  y = y1;
}

