//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <string> 
#include "time.hpp"
#include "date.hpp"
#include "Calendar.hpp"

using namespace std; 


int main()
{
  //create a calendar object
  Calendar summer; 

  int option=0; 

  // output to console to welcome user to Calendar Booking System
  // Displaying information regarding dates and times.
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout << "Welcome to our Calendar Booking System!"<<endl<<endl;
  cout << "Before you book an appointment, please note:"<<endl<<endl;
  cout << "Calendar bookings are unavailable on weekends & holidays, and are only from 05/09 to 08/08"<<endl;
  cout << "Time bookings must be in 30 minute intervals having the format a xx:00 or xx:30"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;

  cout<<"Please choose from the options below: "<<endl<<endl; 

  cout<<"If you would like to view all booked appointments please press 1."<<endl<<endl; 
  cout<<"To view the days with free time slots please press 2."<<endl<<endl; 
  cin>> option; 

    //User option to view all booked appointments
  if (option==1)
  {
    cout<< summer; 
  }
    //User option to view free days
  else if (option==2)
  {
    summer.printFreeDays(); 
  }



  //Declare the date and time variables 
  int day_1, month_1; 
  //Asking for user input for the date (month & day)
  cout<<"Please enter the month in which you would like to book your appointment: ";
  cin>> month_1; 
  cout<<endl<<"please enter the day you would like to book your appointment: ";
  cin>> day_1; 

  //Create a loop where it asks for user's input for day and month until both inputs are valid, 
  //not a holiday date or a weekend 
  Date date_1(day_1, month_1);
  while (!date_1.isValid() || (date_1.isHoliday()) || (date_1.isWeekend()))
  {
    cout<<"Please enter the month in which you would like to book your appointment: ";
    cin>> month_1; 
    cout<<endl<<"please enter the day you would like to book your appointment: ";
    cin>> day_1 ;
    if(std::cin.fail())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter a number in the valid range."<<endl;
    }
 
    //update date object in each iteration 
    date_1.set_day(day_1); 
    date_1.set_month(month_1); 
  }

  cout<<endl; 

  cout<<"To view all the available time slots for the chosen date, please press 3."<<endl<<endl; 
  cout<<"To book an appointment please press 4."<<endl<<endl; 
  cout<<"To query an appointment please press 5."<<endl<<endl; 
  cout<<"To cancel an appoitment please press 6."<<endl<<endl; 
  cout<<"Please input your chosen option:";
  cin>> option; 
  cout<<endl;

//User option to view all the available time slots
if (option==3)
{
  summer.printFreeTimeSlots(date_1); 
}

//Now that the date is a correct value, ask the user for the appointment time 
int hour_start, hour_end; 
int minute_start, minute_end; 

    
//USer option to book an appointment
if (option==4)
{
  cout<<"Please enter the time for your appointment: "<<endl; 
  cout<<"Starting hour: "<<endl; 
  cin>> hour_start;
  cout<<"Starting minute: "<<endl; 
  cin>>minute_start; 
  cout<<"Ending hour: "<<endl;
  cin>> hour_end;
  cout<<"Ending Minute: "<<endl; 
  cin>>minute_end; 
  //Ask the user for the input until the input is correct
  TimeRange time_1(hour_start, minute_start, hour_end, minute_end);
    while (!time_1.isValid())
    {
      cout<<"Starting hour: "<<endl; 
      cin>> hour_start;
      cout<<"Starting minute: "<<endl; 
      cin>>minute_start; 
      cout<<"Ending hour: "<<endl;
      cin>> hour_end;
      cout<<"Ending Minute: "<<endl; 
      cin>>minute_end; 
      if(std::cin.fail())
      {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number in the valid range."<<endl;
      }
      //updating the time values for each iteration 
      time_1.set_hour_start(hour_start);
      time_1.set_min_start(minute_start); 
      time_1.set_hour_end(hour_end); 
      time_1.set_min_end(minute_end);

    }  
     
     summer.book(date_1,time_1);
    cout<< summer;
    summer.printFreeDays();
}

//introducing time variables
int day_2, month_2;
int  hour_start_2, minute_start_2, hour_end_2, minute_end_2;

//User option to query an appointment
if (option==5)
{
    cout<<"Please enter the month you would like to query: ";
    cin>> month_2; 
    cout<<endl<<"please enter the day you would like query: ";
    cin>> day_2 ;

  Date date_2(day_2, month_2);
  while (!date_2.isValid() || (date_2.isHoliday()) || (date_2.isWeekend()))
  {
    cout<<"Please enter the month in which you would like to book your appointment: ";
    cin>> month_2; 
    cout<<endl<<"please enter the day you would like to book your appointment: ";
    cin>> day_2 ;
    if(std::cin.fail())
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Please enter a number in the valid range."<<endl;
    }
 
    //update date object in each iteration 
    date_1.set_day(day_2); 
    date_1.set_month(month_2); 
  }


  cout<<"Please enter the time for your appointment: "<<endl; 
  cout<<"Starting hour: "<<endl; 
  cin>> hour_start_2;
  cout<<"Starting minute: "<<endl; 
  cin>>minute_start_2; 
  cout<<"Ending hour: "<<endl;
  cin>> hour_end_2;
  cout<<"Ending Minute: "<<endl; 
  cin>>minute_end_2; 
  //Ask the user for the input until the input is correct
  TimeRange time_2(hour_start_2, minute_start_2, hour_end_2, minute_end_2);
    while (!time_2.isValid())
    {
      cout<<"Starting hour: "<<endl; 
      cin>> hour_start_2;
      cout<<"Starting minute: "<<endl; 
      cin>>minute_start_2; 
      cout<<"Ending hour: "<<endl;
      cin>> hour_end_2;
      cout<<"Ending Minute: "<<endl; 
      cin>>minute_end_2; 
      if(std::cin.fail())
      {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number in the valid range."<<endl;
      }
      //updating the time values for each iteration 
      time_2.set_hour_start(hour_start_2);
      time_2.set_min_start(minute_start_2); 
      time_2.set_hour_end(hour_end_2); 
      time_2.set_min_end(minute_end_2);

    }


  summer.query(date_2, time_2); 
}

//introducing variables
int day_3, month_3;
int  hour_start_3, minute_start_3, hour_end_3, minute_end_3;

//User option to cancel an appointment
if (option==6)
{
    cout<<"Please enter the month of the appointment you would like to cancel: ";
    cin>> month_3; 
    cout<<endl<<"Please enter the day of the appointment you would like cancel: ";
    cin>> day_3 ;


    Date date_3(day_3, month_3);
    while (!date_3.isValid() || (date_3.isHoliday()) || (date_3.isWeekend()))
    {
      cout<<"Please enter the month of the appointment you would like to cancel: ";
      cin>> month_3; 
      cout<<endl<<"Please enter the day of the appointment you would like cancel: ";
      cin>> day_3 ;

      if(std::cin.fail())
      {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number in the valid range."<<endl;
      }
 
    //update date object in each iteration 
      date_3.set_day(day_3); 
      date_3.set_month(month_3); 
    }

  cout<<"Please enter the time you would like to cancel: "<<endl; 
  cout<<"Starting hour: "<<endl; 
  cin>> hour_start_3;
  cout<<"Starting minute: "<<endl; 
  cin>>minute_start_3; 
  cout<<"Ending hour: "<<endl;
  cin>> hour_end_3;
  cout<<"Ending Minute: "<<endl; 
  cin>>minute_end_3;
    
  //Ask the user for the input until the input is correct
  TimeRange time_3(hour_start_3, minute_start_3, hour_end_3, minute_end_3);
    while (!time_3.isValid())
    {
      cout<<"Starting hour: "<<endl; 
      cin>> hour_start_3;
      cout<<"Starting minute: "<<endl; 
      cin>>minute_start_3; 
      cout<<"Ending hour: "<<endl;
      cin>> hour_end_3;
      cout<<"Ending Minute: "<<endl; 
      cin>>minute_end_3; 
      if(std::cin.fail())
      {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Please enter a number in the valid range."<<endl;
      }
      //updating the time values for each iteration 
      time_3.set_hour_start(hour_start_3);
      time_3.set_min_start(minute_start_3); 
      time_3.set_hour_end(hour_end_3); 
      time_3.set_min_end(minute_end_3);

    }

  summer.cancel(date_3, time_3); 
}
  return 0;
}
