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

    //books an appointment if the time and day is available and returns true otherwise returns false 
    bool book(const Date &date, const TimeRange &time );

    //searches the calender and tells the user whether the given time and range has been booked or partially booked
    bool query(const Date &date, const TimeRange &time);

    //if the date and time are booked or partially booked, cancel the appointment 
    bool cancel(const Date &date, const TimeRange&time); 

    //printing the free time slots 
    void  printFreeTimeSlots(const Date & date); 

    //prints all days that have free time slots to be booked 
    void printFreeDays(); 

    //to print out all the booked time slots (including
    //dates and their corresponding time ranges) in the calendar
    friend ostream& operator<<(ostream &outs, Calendar &cal);

private:
//create a date array for each month in our calendar 
Date May[31]; 
Date June[30]; 
Date July[31];
Date August[8]; 

};
#endif