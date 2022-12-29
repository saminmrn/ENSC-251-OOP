/*
 * Filename: helper.hpp
 * Author: Zhenman Fang
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
 * This header file should be include by both helper.cpp and tutorial.cpp
 */

//--------------------------------------------------------- 
//STRUCTS 
//---------------------------------------------------------

//This is where we can define structs
typedef struct{ 
  int real;
  int imag; 
} num;

//--------------------------------------------------------- 
//FUNCTION PROTOTPYES 
//---------------------------------------------------------

//This tells the compiler how to use your functions
num addcomplex(num a, num b);
void addcomplexPtr(num * a, num b);
