//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <string> 
#include "time.hpp"
#include "date.hpp"

using namespace std; 

int main()
{
  // output to console to welcome user to Calendar Booking System
  // Displaying information regarding dates and times.
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout << "Welcome to our Calendar Booking System!"<<endl<<endl;
  cout << "Before you book an appointment, please note:"<<endl<<endl;
  cout << "Calendar bookings are unavailable on weekends & holidays, and are only from 05/09 to 08/08"<<endl;
  cout << "Time bookings must be in 30 minute intervals having the format a xx:00 or xx:30"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
  cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;

  //Declare the date and time variables 
  int day_1, month_1; 
  int hour_start, hour_end; 
  int minute_start, minute_end; 
  
  //Asking for user input for the date (month & day)
  cout<<"Please enter the month in which you would like to book your appointment: ";
  cin>> month_1; 
  cout<<endl<<"please enter the day you would like to book your appointment: ";
  cin>> day_1; 


  //Create a dummy object for checking while loop condition 
  Date date_1(day_1, month_1); 

  //Create a loop where it asks for user's input for day and month until both inputs are valid, not a holiday date or a weekend 
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
 
    //update the dummy date object in each iteration 
    date_1.set_day(day_1); 
    date_1.set_month(month_1); 
  }

  //Create the date object with the valid inputs 
  //We ensure that the user input is correct at this stage 
  Date date(day_1, month_1); 
  

  //Now that the date is a correct value, ask the user for the appointment time 
  cout<<"Please enter the time for your appointment: "<<endl; 
  
  cout<<"Starting hour: "<<endl; 
  cin>> hour_start;
  cout<<"Starting minute: "<<endl; 
  cin>>minute_start; 
  cout<<"Ending hour: "<<endl;
  cin>> hour_end;
  cout<<"Ending Minute: "<<endl; 
  cin>>minute_end; 

  //Create a dummy time object to check the loop condition iteration of the loop 
  //so that the input values are correct at the end 
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

  //Create the time object for the valid time values
  TimeRange time(hour_start, minute_start, hour_end, minute_end);

    int a= (hour_end*60)+minute_end; // find the starting minute of the appointment 
    int b= (hour_start*60)+minute_start; //find the ending minute of the appointment 
    int duration= (a-b)/30; // find the duration of the aappointment 

    if (minute_start==0) //if the time starts at a whole hour the corresponding index in the appointed array is 2*h 
    {
        int start_index= 2*hour_start; 
        for (int i=start_index; i<(start_index+duration); i++)
        {   
            if (date.get_available(i))
            {
                date.set_appointed(i, true); 
            }
            else 
            {
                cout<<"This time slot is already booked."<<endl; 
            }  
            
        }
    }
    else if (minute_start==30)//if the time starts at an hour and half the corresponding index in the appointed array is 2*h+1
    {
        int start_index= (2*hour_start)+1; 
        for (int i=start_index; i<(start_index+duration); i++)
        {
            if (date.get_available(i))
            {
              date.set_appointed(i, true);
            }
            else 
            {
                cout<<"This time slot is already booked."<<endl; 
            }  
        }
    }
    

  //Create an appontment for the date object with the given appointment time
  //date.setAppointment(hour_start,minute_start,hour_end,minute_end); 

  //print out the information for both date and time classes
  date.output(cout); 
  time.output(cout); 
  // Print the free and appointed time slots 
  date.printFreeTimeSlots(cout);
  date.printAppointedTimeSlots(cout);

  //Ask the user if they want to change the appointment time 
  std:: string answer; 
  cout<<"Would you like to change the date and time you booked your appointment on?"<<endl; 
  cout<< "if yes, please press y, if not, press n ";
  cin>> answer; 

  //if the answer is yes we go through the same process as in the beginning
  if (answer=="y" || answer=="Y")
  {
    //delete the previous appoitment
    for(int i=0; i<48; i++)
    {
       if (!date.get_available(i))
      {
        date.set_appointed(i, false);
      }
      
    }
    cout<<"Please enter the month in which you would like to book your appointment: ";
    cin>> month_1; 
    cout<<endl<<"please enter the day you would like to book your appointment: ";
    cin>> day_1; 
    date_1.set_day(day_1); 
    date_1.set_month(month_1);

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
        date.set_day(day_1);
        date.set_month(month_1);

    }
    //Set the date with the correct inputs 
    date.set_day(day_1);
    date.set_month(month_1);

    cout<<"Please enter the time for your appointment: "<<endl; 
    cout<<"Starting hour: "<<endl; 
    cin>> hour_start;
    cout<<"Starting minute: "<<endl; 
    cin>>minute_start; 
    cout<<"Ending hour: "<<endl;
    cin>> hour_end;
    cout<<"Ending Minute: "<<endl; 
    cin>>minute_end; 
    //set the time with the initial time inputs
    time_1.set_hour_start(hour_start);
    time_1.set_min_start(minute_start); 
    time_1.set_hour_end(hour_end); 
    time_1.set_min_end(minute_end);
    //check the validity of the inputs until the valid inputs are given 
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
      //update the time values to be check in the condition again 
      time_1.set_hour_start(hour_start);
      time_1.set_min_start(minute_start); 
      time_1.set_hour_end(hour_end); 
      time_1.set_min_end(minute_end);
    }
      cout<<endl; 
      //set the right time values for the appointment time 
      time.set_hour_start(hour_start);
      time.set_min_start(minute_start); 
      time.set_hour_end(hour_end); 
      time.set_min_end(minute_end);
      //date.setAppointment(hour_start,minute_start,hour_end,minute_end); 

      a= (hour_end*60)+minute_end; // find the starting minute of the appointment 
      b= (hour_start*60)+minute_start; //find the ending minute of the appointment 
      duration= (a-b)/30; // find the duration of the aappointment 

    if (minute_start==0) //if the time starts at a whole hour the corresponding index in the appointed array is 2*h 
    {
        int start_idx= 2*hour_start; 
        for (int j=start_idx; j<(start_idx+duration); j++)
        {   
            if (date.get_available(j))
            {
                date.set_appointed(j, true); 
            }
            else 
            {
                cout<<"This time slot is already booked."<<endl; 
            }  
            
        }
    }
    else if (minute_start==30)//if the time starts at an hour and half the corresponding index in the appointed array is 2*h+1
    {
        int start_idx= (2*hour_start)+1; 
        for (int i=start_idx; i<(start_idx+duration); i++)
        {
            if (date.get_available(i))
            {
              date.set_appointed(i, true);
            }
            else 
            {
                cout<<"This time slot is already booked."<<endl; 
            }  
        }
    }

      //call the get functions to see the updated values 
      cout<<"The new appontment day is: "<<date.getDay()<<endl;
      cout<< "The new appointment month is: "<<date.getMonth()<<endl;

      cout << "The appointment is from "<<time.get_hour_start()<<":"<<time.get_min_start();
      cout << " to "<<time.get_hour_end()<<":"<<time.get_min_end()<<endl;

   
      //Print the updated time slots
      date.printFreeTimeSlots(cout);
      date.printAppointedTimeSlots(cout);

  }

  //If the answer is no, the previous appointment is confirmed
  else if (answer=="n" || answer=="N")
  {
    cout<<"Your previous appointment is confirmed."<<endl; 
  }
  else 
  {
    cout<<""; 
  }
  

  return 0;
}