//header file date.hpp to declare your class
/*
Filename: date.hpp
Author: Samin Moradkhan, James Ryan Martin 
Date Created: May 26, 2022
Description: This contains the Date classs member function declarations.
*/

/* Codtitions
1) The dates supported in the calendar system are from May 9, 2022 to Aug 8, 2022, 
2) No appointment can be made on weekends and holidays.
3) The time format for each day is using the 24-hour format, from 0:00 to 24:00. We only care
about the hour and minute field and ignore the second field.
4) An appointment in the calendar system can only be made at multiples of 30 minutes, and
it only supports the same day appointment. For example, May 9th 9:00 to 9:30 appointment
is valid, May 9th 10:00 to 12:30 is also valid, May 9th 10:10 to 10:30 is invalid because
10:10 is not a multiple of 30 minutes, May 9th 19:00 to May 10th 9:00 is invalid because it
crosses two days
*/

#include <cstdlib>
#include <iostream>
using std::ostream;

class Date 
{
public:

    //Default Constructor 
    Date(); 
    //set day and month 
    Date(int day_new, int month_new); 

    //Set Functions
    void set_appointed(int index, bool book); 
    void set_day(int day_new);
    void set_month(int month_new); 
    
    //void setAppointment(int h1, int m1, int h2,int m2);

    //Get Functions
    int getMonth(); 
    int getDay(); 
    bool get_Appointed(int i); 
 
    //Member Functions 
    /*isHoliday, isWeekend to check if a date is a holiday
    or a weekend, where no appointment is allowed.*/

    bool isHoliday(); 

    bool isWeekend();

    /* isValid to check if a user input date falls within the
    valid date range as described in our assumptions. If they do not, print out the error
    message, and return false.*/
    bool isValid();
    
    /*Implement the output member function to print out the class information. Add
    ostream& outs as the function parameter to make this output function more general.
    In your output function, in addition to print out the member variables, */
    // output function:
    void output(ostream& outs);

    bool get_available(int index);
    // checks if no appt booked

    /*printFreeTimeSlots member function to print all free time slots of the
    day that haven’t been booked*/
    void printFreeTimeSlots(ostream &outs); 

    /*Implement printAppointedTimeSlots member
    function to print all time slots of the day that have already been booked*/
    void printAppointedTimeSlots(ostream &outs); 

    
    void TimePrint(int index, ostream &outs);
    // Prints the time for the appointment at index, to outs

    //Friend Function to check eaquality of two dates 
    friend const bool equal(const Date & date_1, const Date & date_2); 
    
//private variables 
private: 
    int month; 
    int day; 
    bool appointed[48]={0};
};




