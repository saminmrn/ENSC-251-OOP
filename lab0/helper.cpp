/*
 * Filename: helper.cpp
 * Author: Zhenman Fang
 * Original author: Kevan Thompson 
 * Date Created: April 30, 2019
 * Date Update:
 *
 * Description:
 *
 * This is a very basic tutorial on C part of C++. If you have any questions 
 * about any keywords, functions, or operators vast amounts of information can
 * be found easily online. A note of programming style. Every program you write
 * should begin with a programmers block similar to this one. Every function
 * should have a description similar to the ones used in this program. You should
 * also attempt to layout your code in a similar manner to this program. Properly
 * indenting your code isn't really optional. It makes code legible and easier to
 * debug. Also don't forget to comment your code. This isn't just nitpicking by
 * your professor/TA's. If you follow this advice it will greatly help you and 
 * your group members (if any) to understand and debug your code.
 *
 * To compile, use the following command
 *   g++ -g -c helper.cpp
 */

//--------------------------------------------------------- 
//INCLUDES 
//---------------------------------------------------------
#include "helper.hpp"

//Functions:
//If we want to reuse code we can always write our 
//own functions. Remember while a function can take in 
//any number of arguements. It can only return one.

//--------------------------------------------------------- 
//Function Name: addcomplex()
//Author: Kevan Thompson
//Date Created:
//Date Update:
//Inputs: num a, num b
//Outputs: num c
//Purpose: Adds complex number a to complex number b
//         and returns the result in c 
//---------------------------------------------------------
num addcomplex(num a, num b){
  num c;
  c.real = a.real + b.real; 
  c.imag = a.imag + b.imag; 
  return c;
}

//--------------------------------------------------------- 
//Function Name: addcomplexPtr()
//Author: Kevan Thompson
//Date Created:
//Date Update:
//Inputs: num *a, num b
//Outputs:
//Purpose: Adds complex number a to complex number b
//         and returns the result in a 
//---------------------------------------------------------
void addcomplexPtr(num * a, num b) {
  a->real = a->real + b.real;
  a->imag = a->imag + b.imag;
}
