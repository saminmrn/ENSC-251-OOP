//header file time.hpp to declare your class

/*
Filename: time.hpp
Author: Samin Moradkhan, James Ryan Martin 
Date Created: May 26, 2022
Description: This contains the TimeRange class member function declarations.
*/

#include <iostream>
using std::ostream;

class TimeRange 
{
public: 

//Default Constructor
TimeRange(); 
//Constructor
TimeRange(int hour_start, int minute_start, int hour_end, int minute_end);

//get functions
int get_min_start(); 
int get_hour_start(); 
int get_min_end();
int get_hour_end(); 


//set functions
void set_min_start(int minute_start); 
void set_hour_start(int hour_start); 
void set_min_end(int minute_end);
void set_hour_end(int hour_end); 

//output function 
void output(ostream& outs);

//isValid function 
bool isValid();

//private variables 
private: 
    int beginHour;
    int beginMinute;
    int endHour;
    int endMinute; 
  
};
