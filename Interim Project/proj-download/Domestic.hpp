//domestic.hpp to implement DomesticStudent class
#ifndef DOMESTIC_HPP
#define DOMESTIC_HPP

#include "student.hpp"
#include <string>
using std::ostream;

class DomesticStudent : public Student
{
public:
    //default constructor 
    DomesticStudent();
    //get functions for Domestic Students 
    std:: string get_province(); 
    //set functions for Domestic Students 
    void set_province(string Province);        
    // output
    // overloads the insertion operator to print out domestic students
    friend ostream &operator <<(ostream&  outs, DomesticStudent& stu); 
    // comparing domestic students provinces for sorting overall        
    friend int compareProv(const DomesticStudent& stu1, const DomesticStudent& stu2);

private: 
    std::string province;  
};
#endif