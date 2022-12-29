//Source file Calendar.cpp to define your class member functions
/*Filename: Calendar.hpp
Author: Samin Moradkhan, James Ryan Martin
Date Created: Jun 10, 2022*/

#include "Calendar.hpp"
#include "date.hpp"
#include "time.hpp"
#include <iostream>
using std::ostream;

//Creates dates in each month in the valid range
Calendar::Calendar()
{
    for(int i = 0; i < 31; i++) // May Dates Initialization
    {
        May[i].set_day(i+1);
        May[i].set_month(5);
    }

    for(int i = 0; i < 30; i ++) //June Dates Initialization
    {
        June[i].set_day(i+1);
        June[i].set_month(6);
    }

    for (int i = 0; i < 31; i++) // July Dates Initialization
    {
        July[i].set_day(i+1);
        July[i].set_month(7);
    }

    for(int i = 0; i < 8; i++) // August Dates Initialization
    {
        August[i].set_day(i+1);
        August[i].set_month(8);
    }

}

/*This function books an appointment at the given date and time,
assuming it is a valid workday,and the given valid time range
of the day has not been booked yet*/
bool Calendar:: book(const Date &date,  const TimeRange &time )
{
    //check if the time is valid and if the date is valid, not a holiday or weekend
    if (date.isValid() && time.isValid() && !(date.isHoliday()) && !(date.isWeekend()))
    {
        int a= time.get_hour_start() * 60+ time.get_min_start();
        int b= time.get_hour_end()*60+time.get_min_end();
        int duration= (b-a)/30;
        int start_index=2*time.get_hour_start();//if the starting minute is 0, the index is 2*h1
        if (time.get_min_start()==30)//if the starting minute is 30, the index is 2*h1+1
        {
            start_index= (2*time.get_hour_start())+1;
        }
          
        for (int i= start_index; i<(start_index+duration); i++)
        {
            //if the month is may
            if (date.getMonth()==5)
            {
                //return false if the appointment is partially booked
                if (!(May[date.getDay()].get_available(i)))
                {
                cout<<"A part of this time slot is already booked"<<endl;
                return false;
                }
                //otherwise set the array to true, meaning its booked
                May[date.getDay()].set_appointed(i,1);
            }
            //if june
            else if (date.getMonth()==6)
            {
                //return false if the appoitmnet is partially booked
                if (!(June[date.getDay()].get_available(i)))
                {
                cout<<"A part of this time slot is already booked"<<endl;
                return false;
                }
                //otherwise set the array to true, meaning its booked
                June[date.getDay()].set_appointed(i,1);
            }
            //July
            else if (date.getMonth()==7)
            {
                //return false if the appointment is partially booked
                if (!(July[date.getDay()].get_available(i)))
                {
                cout<<"A part of this time slot is already booked"<<endl;
                return false;
                }
                //otherwise set the array to true, meaning its booked
                July[date.getDay()].set_appointed(i,1);
            }
            //August
            else if (date.getMonth()==8)
            {
                //return false if the appointment is partially booked
                if (!(August[date.getDay()].get_available(i)))
                {
                cout<<"A part of this time slot is already booked"<<endl;
                return false;
                }
                //otherwise set the array to true, meaning its booked
                August[date.getDay()].set_appointed(i,1);
            }
        }
        
        //print the freetime slots after the appointment is booked
        //call the printFreeTimeSlots in date.cpp
        if (date.getMonth()==5)
        {
            May[date.getDay()].printFreeTimeSlots(cout);
        }
        else if (date.getMonth()==6)
        {
            June[date.getDay()].printFreeTimeSlots(cout);
        }
        else if (date.getMonth()==7)
        {
            July[date.getDay()].printFreeTimeSlots(cout);
        }
        else if (date.getMonth()==8)
        {
            August[date.getDay()].printFreeTimeSlots(cout);
        }
        //tell the user that the appointment is booked
        cout<<endl<<"The appointment is booked."<<endl<<endl;
        return true;
    }

}

//print all days that have some free time slots in the calendar which can be booked.
//Don’t include holidays and weekends.
void Calendar:: printFreeDays()
{
    
    cout<<"Free Days for May: "<<endl;
    
    //check that the date is not on a weekend or holiday
    for (int i=9; i<=31; i++)
    {
        if ( !(this->May[i-1].isWeekend()) && !(this->May[i-1].isHoliday()))
        {
            bool check;
            for (int j=0; j<48; j++)
            {
                //check if any day in may has free time slots
                if (this->May[i].get_available(j))
                {
                    check=1;
                }
                //no free time slot
                else
                {
                    check=0;
                }
            }
            //if there is an available timeslot print out as an available day
            if (check)
            {
                cout<<i<<endl;
            }
        }

    }

    //it's the same process for the months seperately
    cout<<endl<<"Free Days for June: "<<endl;
    for (int i=1; i<=30; i++)
    {
        if (!(this->June[i-1].isHoliday()) && !(this->June[i-1].isWeekend()))
        {
            bool check;
            for (int j=0; j<48; j++)
            {
                //check if any day in may has free time slots
                if (this->June[i].get_available(j))
                {
                    check=1;
                }
                else
                {
                    check=0;
                }
            }
            if (check)
            {
                cout<<i<<endl;
            }
        }
    }
    cout<<endl<<"Free Days for July: "<<endl;

    
    for (int i=1; i<=31; i++)
    {
        if (!(this->July[i-1].isHoliday()) && !(this->July[i-1].isWeekend()))
        {
            bool check;
            for (int j=0; j<48; j++)
            {
                //check if any day in may has free time slots
                if (this->July[i].get_available(j))
                {
                    check=1;
                }
                else
                {
                    check=0;
                }
            }
            if (check)
            {
                cout<<i<<endl;
            }
        }
    }
    cout<<endl<<"Free Days for August: "<<endl;
    for (int i=1; i<=8; i++)
    {
        if (!(this->August[i-1].isHoliday()) && !(this->August[i-1].isWeekend()))
        {
            bool check;
            for (int j=0; j<48; j++)
            {
                //check if any day in may has free time slots
                if (this->August[i].get_available(j))
                {
                    check=1;
                }
                else
                {
                    check=0;
                }
            }
            if (check)
            {
                cout<<i<<endl;
            }
        }
        
    }
}

//print all free time slots for the given date in the calendar, which can be booked
void  Calendar :: printFreeTimeSlots(const Date & date)
{
    //check the month that is in the date object and print out the free time slots
    if (date.getMonth()==5)
        {
            May[date.getDay()].printFreeTimeSlots(cout);
        }
    else if (date.getMonth()==6)
        {
            June[date.getDay()].printFreeTimeSlots(cout);
        }
    else if (date.getMonth()==7)
        {
            July[date.getDay()].printFreeTimeSlots(cout);
        }
    else if (date.getMonth()==8)
        {
            August[date.getDay()].printFreeTimeSlots(cout);
        }

}

/*This function first searches the current calendar. If the given date and time
range has been booked or partially booked, delete the corresponding booking
and make those time slots available for booking again.*/
bool Calendar:: cancel(const Date &date,  const TimeRange &time )
{
    //check if the time is valid and if the date is valid, not a holiday or weekend
    if (date.isValid() && time.isValid() && !(date.isHoliday()) && !(date.isWeekend()))
    {
        int a= time.get_hour_start() * 60+ time.get_min_start();
        int b= time.get_hour_end()*60+time.get_min_end();
        int duration= (b-a)/30;
        int start_index=2*time.get_hour_start();//if the starting minute is 0, the index is 2*h1
        if (time.get_min_start()==30)//if the starting minute is 30, the index is 2*h1+1
        {
            start_index= (2*time.get_hour_start())+1;
        }
          
        for (int i= start_index; i<(start_index+duration); i++)
        {
            if (date.getMonth()==5)
            {
                //check if the timeslot in the day is booked and set it to free
                if (!(May[date.getDay()].get_available(i)))
                {
                    May[date.getDay()].set_appointed(i,0);
                }
                //if its not booked then there is no need to cancel
                else
                {
                    cout<<"No appointment booked to be canceled."<<endl;
                    return false;
                }
            }
            else if (date.getMonth()==6)
            {
                if (!(June[date.getDay()].get_available(i)))
                {
                    June[date.getDay()].set_appointed(i,0);
                }
                else
                {
                    cout<<"No appointment booked to be canceled."<<endl;
                    return false;
                }
            }
            else if (date.getMonth()==7)
            {
                if (!(July[date.getDay()].get_available(i)))
                {
                    July[date.getDay()].set_appointed(i,0);
                }
                else
                {
                    cout<<"No appointment booked to be canceled."<<endl;
                    return false;
                }
            }
            else if (date.getMonth()==8)
            {
                if (!(August[date.getDay()].get_available(i)))
                {
                    August[date.getDay()].set_appointed(i,0);
                }
                else
                {
                    cout<<"No appointment booked to be canceled."<<endl;
                    return false;
                }
            }
   
        }
        cout<<"Appointment time has been cancelled. "<<endl;
        return true;
    }

}

/*This function searches the current calendar
and tells the user whether the given date and time
range has been booked or partially booked.*/
bool Calendar:: query(const Date &date,  const TimeRange &time )
{
    //check if the time is valid and if the date is valid, not a holiday or weekend
    if (date.isValid() && time.isValid() && !(date.isHoliday()) && !(date.isWeekend()))
    {
        int counter=0; //the counter counts the number of booked time slots within a time range
        int a= time.get_hour_start() * 60+ time.get_min_start();
        int b= time.get_hour_end()*60+time.get_min_end();
        int duration= (b-a)/30;
        int start_index=2*time.get_hour_start();//if the starting minute is 0, the index is 2*h1
        if (time.get_min_start()==30)//if the starting minute is 30, the index is 2*h1+1
        {
            start_index= (2*time.get_hour_start())+1;
        }
          
        for (int i= start_index; i<(start_index+duration); i++)
        {
            if (date.getMonth()==5)
            {
                if (!(May[date.getDay()].get_available(i)))
                {
                    counter++; //increment counter for each booked timeslot
                }
                
            }
            else if (date.getMonth()==6)
            {
                if (!(June[date.getDay()].get_available(i)))
                {
                    counter++;
                }
                
            }
            else if (date.getMonth()==7)
            {
                if (!(July[date.getDay()].get_available(i)))
                {
                    counter++;
                }
                
            }
            else if (date.getMonth()==8)
            {
                if (!(August[date.getDay()].get_available(i)))
                {
                    counter++;
                }
                
            }
        }
        //means that the whole time range is booked
        if (counter== duration)
        {
            cout<<"This appointment is fully booked."<<endl;
            return true;
        }
        //this mean that the time range is partially booked
        else if (counter< duration and counter!=0)
        {
            cout<<"This appointment is partially booked."<<endl;
            return true;
        }
        //if not booked at all
        else
        {
            cout<<"There is no appointment booked at this time.";
        }
        return false;
    }

}

//Overload the << operator to print out all the booked time slots (including
//dates and their corresponding time ranges) in the calendar.
ostream& operator<<(ostream &outs, Calendar &cal)
{
    //are month (May) and the respective days defined already for the pATS function?
    for (int i=8; i<31; i++)
    {
        cal.May[i].printAppointedTimeSlotsCalender(cout);
    }
    cout<<endl;
    for (int i=0; i<30; i++)
    {
        cal.June[i].printAppointedTimeSlotsCalender(cout);
    }
    cout<<endl;
    for (int i=0; i<31; i++)
    {
        cal.July[i].printAppointedTimeSlotsCalender(cout);
    }
    cout<<endl;
    for (int i=0; i<8; i++)
    {
        cal.August[i].printAppointedTimeSlotsCalender(cout);
    }

}
