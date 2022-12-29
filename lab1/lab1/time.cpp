//time.cpp to implement your class
#include <iostream>
#include "time.hpp"
using namespace std;
  
//Declare the variables 
int initialTime;
int finalTime;


//default construction
//Sets the time range to 0
TimeRange:: TimeRange()
{
    beginHour=0;
    beginMinute=0;
    endHour=0;
    endMinute=0;
}

//Constructor
//Creates a timerange object with the given initial and final time values for hours and minutes if they are in valid range
TimeRange:: TimeRange(int hour_start, int minute_start, int hour_end, int minute_end)
{
    beginHour= hour_start;
    beginMinute= minute_start;
    endHour= hour_end;
    endMinute= minute_end;
}

    //Get Functions
    
    //returns the appointment's starting minute value
    int TimeRange:: get_min_start()
    {
        return beginMinute;
    }
    //returns the appointment's starting hour value
    int TimeRange:: get_hour_start()
    {
        return beginHour;
    }
    //returns the appointment's ending minute value
    int TimeRange:: get_min_end()
    {
        return endMinute;
    }
    //returns the appointment's ending hour value
    int TimeRange:: get_hour_end()
    {
        return endHour;
    }

    //Set Functions
    //Sets the appointment's starting minute value
    void TimeRange:: set_min_start(int minute_start)
    {
        beginMinute= minute_start;
    }
    //Sets the appointment's starting hour value
    void TimeRange:: set_hour_start(int hour_start)
    {
        beginHour= hour_start;
    }
    //Sets the appointment's ending minute value
    void TimeRange:: set_min_end(int minute_end)
    {
        endMinute= minute_end;
    }
    //Sets the appointment's ending minute value
    void TimeRange:: set_hour_end(int hour_end)
    {
        endHour= hour_end;
    }

    /* Implement member function isValid to check if a user input time falls within the
    valid time range as described in our assumptions. If they do not, print out the error
    message, and return false.*/

    bool TimeRange:: isValid ()
    {
        //Checks if the hours are within the correct range
        if (beginHour<0 || beginHour >23 || endHour<0 || endHour >24)
        {
            cout<<"Hour is not in acceptable range. "<<endl;
            return 0; 
        }
        //Checks if the minutes ar within the correct range
        if (beginMinute<0 || beginMinute>59 || endMinute<0 || endMinute>59)
        {
            cout<<"Minutes are not in acceptable range. " << endl; //
            return 0; 
        }
        //Checks if the minutes are a multiple of 30 minutes.
        else if (beginMinute%30 !=0 || endMinute%30 !=0 )
        {
            cout <<"The minutes is not in an acceptable range. " <<endl; //specify initial?
           return 0;
        }
        else 
        {
            initialTime = (beginHour*60)+beginMinute;
            finalTime = (endHour*60)+endMinute;
            
            //Checks if the appointment starts and ends at the same time.
            if (initialTime == finalTime)
            {
                cout << "Appointment needs to be a minimum of 30 minutes in length." << endl;
                return 0;  
            }
            //Checks if the initial date begins on one day and ends on another.
            else if (finalTime < initialTime)
            {
                cout << "The selected time is between two different dates. " << endl; //diff note.
                return 0;  
            }
        }

    return 1; 
    }
    
    //Output function that states the values when called in the main file
    void TimeRange:: output(ostream& outs)
    {
        if (beginMinute==0  && endMinute==0)
        {
            outs << "Your appointment time begins at " << beginHour << ":" << beginMinute<<"0" <<endl;
            outs << "Your appointment time ends at " << endHour << ":" << endMinute<<"0";
            outs << endl;
        }
        if (beginMinute==30  && endMinute==30)
        {
            outs << "Your appointment time begins at " << beginHour << ":" << beginMinute <<endl;
            outs << "Your appointment time ends at " << endHour << ":" << endMinute;
            outs << endl;
        }

        if (beginMinute==30  && endMinute==0)
        {
            outs << "Your appointment time begins at " << beginHour << ":" << beginMinute <<endl;
            outs << "Your appointment time ends at " << endHour << ":" << endMinute<<"0";
            outs << endl;
        }

        if (beginMinute==0  && endMinute==30)
        {
            outs << "Your appointment time begins " << beginHour << ":" << beginMinute<<"0" <<endl;
            outs << "Your appointment time ends " << endHour << ":" << endMinute;
            outs << endl;
        }
    }

