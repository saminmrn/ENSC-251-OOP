//header file stu_sort.hpp to declare your sorting functions
#include <string> //you will have to use string in C++
#include <vector> 
#include <iostream>
#include "student.hpp"
#include "Domestic.hpp"
#include "International.hpp"
#include "TOFEL.hpp"
using namespace std;

//Sorting functions for domestic students 

// sort by CGPA (high to low)
void SortByCGPA_D(vector <DomesticStudent> &students);
// sort by research score (high to low)
void SortByResearchScore_D(vector <DomesticStudent> &students); 
//sort by first name (a-z)
void SortByFirstName_D(vector <DomesticStudent> &students); 
//sort by last name (a-z)
void SortByLastName_D(vector <DomesticStudent> &students); 
//sort by province 
void SortByProv_D(vector <DomesticStudent> &students);
// based on research score, then CGPA, then province/country; ascending order
//sorting overall 
void SortOverall_D(vector <DomesticStudent> &students); 

//Sorting functions for international students 
// sort by CGPA (high to low)
void SortByCGPA_I(vector <InternationalStudent> &students);
// sort by research score (high to low)
void SortByResearchScore_I(vector <InternationalStudent> &students); 
//sort by first name (a-z)
void SortByFirstName_I(vector <InternationalStudent> &students);
//sort by last name (a-z) 
void SortByLastName_I(vector <InternationalStudent> &students); 
//sort by country
void SortByCountry_I(vector <InternationalStudent> &students); 
//sort by tofel score 
void SortByTofel_I(vector <InternationalStudent> &students); 
//sorting overall 
// based on research score, then CGPA, then province/country; ascending order
void SortOverall_I(vector  <InternationalStudent> &students); 



