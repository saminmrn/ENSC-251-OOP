//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <string> 
#include "time.hpp"
#include "date.hpp"

using namespace std; 

void testtime(){

  int hour_start;
  int minute_start;
  int hour_end;
  int minute_end;

  

  cout << "Please input the hour you want to meet: " <<endl;
  cin >> hour_start;
  cout << "Please input the minute you want to meet: " <<endl;
  cin >> minute_start;
  cout << "Please input the hour you want to end the meeting: " << endl;
  cin >> hour_end;
  cout << "Please input the minute you want to end the meeting: " <<endl;
  cin >> minute_end;

TimeRange obj(hour_start, minute_start, hour_end, minute_end); 

  if (obj.isValid(hour_start, minute_start, hour_end, minute_end))
  {
    cout<<" the meeting time is confirmed"<<endl; 
  }
  else 
  {
    cout<<" the time is not in valid range"<<endl; 
  }

  

  /*obj.set_hour_start(hour_start);
  obj.set_min_start(minute_start);
  obj.set_hour_end(hour_end);
  obj.set_min_end(minute_end);*/

  cout << "the starting hour is: "<<obj.get_hour_start()<<endl;
  cout << "the starting minute is: "<<obj.get_min_start()<<endl;
  cout << "the ending  hour is: "<<obj.get_hour_end()<<endl;
  cout << "the ending  minute is: "<<obj.get_min_end()<<endl;
//once the appointment time is confirmed we can call a function to book the time slots in the appointed array 

int h1= obj.get_hour_start();
cout<<h1<<endl; 
int m1= obj.get_min_start();
cout<<m1<<endl;
int h2= obj.get_hour_end();
int m2= obj.get_min_end();

int day_1; 
int month_1; 
cout << "Please input the day of appointement  " <<endl;
cin >> day_1;
cout << "Please input the month of your appointment " <<endl;
cin >> month_1; 

Date date_1;
date_1.setDate(day_1, month_1); 

date_1.setAppointment(h1, m1, h2, m2); 
if (!date_1.isHoliday(date_1))
{
  date_1.printFreeTimeSlots();
}




}

void test1()
{
  //Check Date Validity//
  //if the given date is not valid it will set it to default constructor value 
  int day, month; 
  Date date_2; 
  //cout<<"please enter the day:"; 
  //cin>> day;

  date_2.setDate(24,78);
  cout<<date_2.getDay()<<endl;//9 
  cout<<date_2.getMonth()<<endl;//5


  ///Check holiday//
  Date date_1(23,5); 
  cout<<date_1.getDay()<<endl;
  cout<<date_1.getMonth()<<endl;

  if (date_1.isHoliday(date_1))
  cout<<"the given date is holiday"<<endl ; 

  //Check Weekend//
  Date date_3(67,8); 
  if (date_3.isWeekend())
  {
    cout<<"the given date is weekend in August"<<endl ;
  } 

  date_3.output(cout); 
  //date_3.printFreeTimeSlots(); 
  //date_2.output(cout);
  //date_2.setAppointment(10); 
  //if (date_2.getAppointment(10))
  //cout<<"the time index requested is booked for you!";

  //date_2.printFreeTimeSlots();
  //date_2.printAppointedTimeSlots();

  //date_3.printAppointedTimeSlots();
}

int main()
{

  //test1(); 


  //testtime(); 


  // output to console to welcome user to Calendar Booking System
  // Displaying important formatting and input information regarding dates and times.
  cout << "Welcome to our Calendar Booking System!"<<endl<<endl;
  cout << "Before you book an appointment, please note:"<<endl<<endl;
  cout << "Calendar bookings are unavailable on weekends & holidays, and are only from 09/05 to 08/08"<<endl;
  cout << "Time bookings must be in 30 minute intervals having the format a xx:00 or xx:30"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

  //Asking for user input
  int day_1, month_1; 
  int hour_start, hour_end; 
  int minute_start, minute_end; 
  

  cout<<"Please enter the month in which you would like to book your appointment: ";
  cin>> month_1; 
  cout<<endl<<"please enter the day you would like to book your appointment: ";
  cin>> day_1; 
  Date date_1(day_1, month_1);  
  date_1.output(cout); 

  if(date_1.isValid(day_1, month_1) && !(date_1.isHoliday(date_1)) && !(date_1.isWeekend()))
  {
    cout<<"Please enter the time for your appointment: "<<endl; 
  
    cout<<"Starting hour"<<endl; 
    cin>> hour_start;
    cout<<"Starting minute"<<endl; 
    cin>>minute_start; 
    cout<<"Ending hour"<<endl;
    cin>> hour_end;
    cout<<"ending Minute"<<endl; 
    cin>>minute_end; 
    TimeRange time_1(hour_start, minute_start, hour_end, minute_end);
    //call the set appointment time to set the time for the appointment 
    if (time_1.isValid(hour_start, minute_start, hour_end, minute_end))
    {
      date_1.setAppointment(hour_start,minute_start,hour_end,minute_end); 
      date_1.output(cout); 
      time_1.output(cout); 
      
      cout<<endl; 
      date_1.printFreeTimeSlots();
      date_1.printAppointedTimeSlots();
  
    }

    
  }
  else 
  {
    cout<<"Please Start again. ";
  }

  std:: string answer; 
  cout<<"Would you like to change the date and time you booked your appointment on? if yes, please press y";
  cin>> answer; 


  int day_2, month_2; 
  //Date date_2; 
  int hour_start2, hour_end2; 
  int minute_start2, minute_end2; 
  
  //call the set functions to change the date and time of the objects 
  if (answer=="y" || answer=="Y")
  {
    cout<<"Please enter the month in which you would like to book your appointment: ";
    cin>> month_2; 
    cout<<endl<<"please enter the day you would like to book your appointment: ";
    cin>> day_2; 
    date_1.setDate(day_2,month_2); 
    date_1.output(cout);

    if(date_1.isValid(day_2, month_2) && !(date_1.isHoliday(date_1)) && !(date_1.isWeekend()))
    {
      cout<<"Please enter the time for your appointment: "<<endl; 
      cout<<"Starting hour"<<endl; 
      cin>> hour_start2;
      cout<<"Starting minute"<<endl; 
      cin>>minute_start2; 
      cout<<"Ending hour"<<endl;
      cin>> hour_end2;
      cout<<"ending Minute"<<endl; 
      cin>>minute_end2;

      TimeRange time_2(hour_start2, minute_start2, hour_end2, minute_end2);
      //call the set appointment time to set the time for the appointment 
      if (time_2.isValid(hour_start2, minute_start2, hour_end2, minute_end2))
      {
        date_1.setAppointment(hour_start2,minute_start2,hour_end2,minute_end2); 
        date_1.output(cout); 
        time_2.output(cout); 
      
        cout<<endl; 
         //call the get fnctions to see the updated values 
        cout<<"The new appontment day is: "<<date_1.getDay()<<endl;
        cout<< "The new appointment month is: "<<date_1.getMonth()<<endl;


      //date_1.printFreeTimeSlots();
      //date_1.printAppointedTimeSlots();
      }  
    }
    else 
    {
      cout<<"Please Start again. ";
    } 
  }
  else
  {
    cout<<"Your appointment is confirmed."; 
  }

  return 0;
}

//problems
//if the first input date is invalid do not ask if the want to change the date
//if the user changes the date and time, the previous time slot is still booked 