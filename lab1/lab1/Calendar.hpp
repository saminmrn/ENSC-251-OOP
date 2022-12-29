//header file Calendar.hpp to declare your class
/*Filename: Calendar.hpp
Author: Samin Moradkhan, James Ryan Martin 
Date Created: Jun 10, 2022*/

#ifndef Calendar_hpp
#define Calendar_hpp

#include <iostream> //cin and cout
#include <iomanip>
#include <stdlib.h>
#include <string>
#include "date.hpp"
#include "time.hpp"

using namespace std;

class Calendar: public Date, public TimeRange
{
public:
    //default constructor
    Calendar(); 

    bool book(const Date &date,const TimeRange &time );

    bool query(const Date &date, const TimeRange &time);

    bool cancel(const Date &date, const TimeRange&time); 

    void  printFreeTimeSlots(const Date & date); 

    void printFreeDays(); 

    friend ostream& operator<<(ostream &outs, const calendar &cal);

private:
Date May[31]; 
Date June[30]; 
Date July[31];
Date August[8]; 

}