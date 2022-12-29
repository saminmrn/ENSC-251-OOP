
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


bool Calendar:: book(const Date &date,const TimeRange &time )
{
    if (date.isValid() && time.isValid())
    {
        int a=time.get_hour_start() * 60+ time.get_minute_start();
        int b= time.get_hour_end()*60+time.get_min_end(); 
        int duration= (b-a)/30;
    
        if (time.get_minute_start()==0)
        {
            int start_index= 2*time.get_hour_start(); 
            for (int i= start_index; i<start_index+duration; i++)
            {
                if (date.get_available(i))
                {
                    date.set_appointed(i,true); 
                    cout<<"The appointment is booked."
                    return true; 
                }
                else 
                {
                    cout<<"A part of this time slot is already booked"<<endl; 
                    return false;
                }  

            }
        }

        if (time.get_minute_start()==30)
        {
            int start_index= 2*time.get_hour_start()+1; 
            for (int i= start_index; i<start_index+duration; i++)
            {
                if (date.get_available(i))
                {
                    date.set_appointed(i,true); 
                    cout<<"The appointment is booked."
                    return true; 
                }
                else 
                {
                    cout<<"A part of this time slot is already booked"<<endl; 
                    return false; 
                }  

            }
        }

    }
    else if (!date.isValid() && time.isValid())
    {
        cout<<"The Chosen date is not valid."<<endl; 
        return false;
    }
    else if(!time.isValid() && date.isValid())
    {
        cout<<"The Chosen date is not valid."<<endl; 
        return false;
    }
    else if (!date.isValid() && !time.isValid())
    {
        cout<<"The chosen date and time are not valid."<<endl; 
        return false; 
    }
    
    

}







