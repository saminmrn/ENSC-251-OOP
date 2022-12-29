//date.cpp to implement your class
#include "date.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
using std::ostream;
using namespace std; 


//Weekend Dates in each month
const int  May_weekend[6]= {14,15,21,22,28,29};
const int June_weekend[8]= {4,5,11,12,18,19,25,26};
const int July_weekend[10]= {2,3,9,10,16,17,23,24,30,31};
const int August_weekend[2]= {6,7};

//default constructor
//sets the date to the first day of summer term 
Date:: Date()
{
    day=9; 
    month=5; 
    appointed[48]={false};  

}

//Constructor 
//Creates a date object with the given day and month if they are in valid range 
Date:: Date(int day_new, int month_new)
{

    day= day_new; 
    month= month_new; 
    appointed[48]={false};
}

//Friend Function equal
//Compares two dates and returns true if they are the same date 
const bool equal(const Date & date_1, const Date & date_2)
{
    bool result= (date_1.day== date_2.day)&&(date_1.month==date_2.month); 
    return result; 
}

//Get Functions 

//returns the month of the appointment  
int Date:: getMonth()const
{
    return month; 
}
//returns the day of the appointment 
int Date:: getDay()const
{ 
    return day; 
}

//returns the index of the appointment from the appointed array 
bool Date:: get_Appointed(int i)const
{

    return appointed[i]; 
}

//Set Functions
//sets the date of the appointment if the parameters are in valid ramge 
void Date:: set_day(int day_new) 
{
    day= day_new; 

}

void Date:: set_month(int month_new)
{
    month= month_new;  
}

//sets the index to true if the timeslot is booked
void Date::set_appointed(int idx,  bool appt_val)
{
    appointed[idx]= appt_val; 
}

//returns true if the input date is a holiday
bool Date:: isHoliday()const
{
    // checks if holiday Victoria Day (May 23), Canada Day (July 1), and BC Day (August 1)
    int check_1= (this->month==5 && this->day==23); 
    int check_2= (this->month==7 && this->day==1);
    int check_3= (this->month==8 && this->day==1);

    if ( check_1 || check_2 || check_3)
    {
        cout<<"This is a holiday"<<endl; 
        return true; 
    }
    else 
    {
        return false; 
    }
} 

//Check if the calling object is a weekend day
//The weekend days are declared in an array on the top
bool Date:: isWeekend()const
{
    if (this->month== 5)//May
    {
        for (int i=0; i<6; i++)//has 6 weekend days
        {
            if (this->day==May_weekend[i])
            {
                cout<<"This is a weekend."<<endl;
                return true;  
            }
        }   
    }
    else if (this-> month==6)//June
    {
        for (int i=0; i<8; i++)//has 8 weekend days
        {
            if (this-> day==June_weekend[i])
            {
                cout<<"This is a weekend."<<endl;
                return true;  
            }
        }
    }
    else if (this-> month==7)//July
    {
        for (int i=0; i<10; i++)//has 10 weekend days
        {
            if (this-> day==July_weekend[i])
            {
                cout<<"This is a weekend."<<endl;
                return true;  
            }
        }
    }
    else if (this->month ==8)//August  
    {
        for (int i=0; i<2; i++)//has 2 weekend days
        {
            if (this->day==August_weekend[i])
            {
                cout<<"This is a weekend."<<endl;
                return true;  
            }  
        }
    }
    return false; 
}

/* Function isValid checks if a user input date falls within the
valid date range as described in our assumptions. If they do not, print out the error
message, and return false.*/
bool Date:: isValid()const
{
    if (month<5 || month >9)
    {
        cout<<"Month is not in  acceptable range."<<endl; 
        return 0; 
    }
    
    //May
    else if (month==5 )
    {
        if (day>31 || day<9)        
        {       
            cout<< "Day is not acceptable in May, the range is 9th to 31st."<<endl; 
            return 0;
        }
    }
    //June
    else if (month==6 )
    {
        if (day>31 || day<1)        
        {       
            cout<< "Day is not acceptable in June, the range is 1st to 31st."<<endl; 
            return 0;
        }
    }
    //July 
    else if (month==7 )
    {
        if (day>30 || day<1)
        {       
            cout<< "Day is not acceptable in July, the range is 1st to 30th."<<endl; 
            return 0;
        }
    }
    //August 
    else if (month==8)
    {
        if (day>8 || day<1)        
        {       
            cout<< "Day is not acceptable in August, the range is 1st to 8th."<<endl; 
            return 0;
        }
    }
    return 1; 
}

void Date::output(ostream& outs)
{    
    
        if(day<10)
        {
            outs << "Your date: " << "0" << month << "/" << "0" << day <<" ";
        }
        else
        {
            outs << "Your date: " << "0" << month << "/" << day <<" ";
        }

        if (this->isHoliday())
        {
            outs << " is a holiday.";
        }
        else if (this->isWeekend())
        {
            outs << " is a weekend.";
        }
        else
        {
            outs << " is a weekday and you may book an appointment.";
        }
        outs << endl;
 
}
// Returns true if index is available, and false if index is not available.
bool Date::get_available(int index)const
{
    // if already booked at this time
    if (appointed[index] != 0) // checks for appt
    {
        return false;
    }
    return true;
}

/*
e. Implement printFreeTimeSlots member function to print all free time slots of the
day that haven’t been booked. */
void Date:: printFreeTimeSlots(ostream &outs)
{
    outs<< "Here are the free time slots you can book:"<<endl;
    for (int i=0; i<48; i++)
    {   
        if (appointed[i]==false)
        {
             TimePrint(i, outs);
        }     
    }
}


/*Implement printAppointedTimeSlots member
function to print all time slots of the day that have already been booked. Note your
print out information should be easy to understand, e.g., print out the actual time
slots instead of the array indices.*/
void Date:: printAppointedTimeSlots(ostream &outs)
{
    outs<< "Booked time slots for "<< month<< "/" <<day <<": "<<endl;
    for (int i=0; i<48; i++)
    {
        if (appointed[i]==true)
        {
            TimePrint(i, outs);
        }
    }  
} 

void Date::TimePrint(int index, ostream &outs)
{
    // hour = index / 2;
    // if remainder when dividing by 2 make minute = 30, else minute = 0
    int minute = 0;
    int hour = index / 2;
    if ((index % 2) == 1) // if remainder minute is 30
    {
        minute = 30;
    }

    if (minute==30)
    {
        outs << hour << " : " << minute << endl; // prints time
    }
    else 
    {
        outs << hour << " : " << "0"<< minute << endl; // prints time
    }
   
}

//helper function to print the time slot that was booked
void Date:: printAppointedTimeSlotsCalender(ostream &outs)
{
    outs<< "Booked time slots for "<< month<< "/" << day <<": "<<endl;
    for (int i=0; i<48; i++)
    {
        if (appointed[i-1]==false && appointed[i]==true && appointed[i+1]==true)
        {
            TimePrint(i, outs);
            outs << " to " << endl;
        }
        else if (appointed[i+1]==false && appointed[i]==true && appointed[i-1]==true)
        {
            TimePrint(i, outs);
        }
    }
}