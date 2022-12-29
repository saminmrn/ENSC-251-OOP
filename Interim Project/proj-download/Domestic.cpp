//header file domestic.cpp to declare DomesticStudent classes
#include "Domestic.hpp"

#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

//left blank on purpose 
DomesticStudent:: DomesticStudent()
{

}
    

//get functions for Domestic Students 
string DomesticStudent:: get_province()
{
    return this->province;
} 


//set functions for Domestic Students 
void DomesticStudent::set_province(string Province)
{
    province= Province;
} 
            
// output
// output Domestic Student
ostream &operator <<(ostream&  outs, DomesticStudent& stu) 
{

    outs << std::left << setw(18) << std::left << setw(18) << stu.get_studentName() <<std::fixed << std::left << setw(18) << stu.get_studentLastName() << std::left<< setw(18) << stu.get_province();
    outs << std::left << setw(18) <<std::fixed << setprecision(2) << stu.get_student_CGPA() <<std::fixed << std::left << stu.get_student_ResearchScore() << std::left << setw(18) <<endl;
    return outs;
}

 
int compareProv(const DomesticStudent& stu1, const DomesticStudent& stu2)
{
    // return 0: student1 after student2
    // return 1: student2 after student1
    // return 2: student1 same as student2 (equal)
    //bigger alphabets come later 
    if(stu1.province == stu2.province)
    {
        return 2;
    }

    else if (stu1.province < stu2.province) 
    { 
        return 1; // student 2 comes sfter student 2
    }

    
    else if (stu2.province < stu1.province)
    {
        return 0; // student 1 comes sfter student 2
    }
    return 0;
}
