//stu_sort.cpp to implement your sorting functions
#include "stu_sort.hpp"
#include <string>
#include <vector> 
#include <iostream>
#include "student.hpp"
#include "Domestic.hpp"
#include "International.hpp"
#include "TOFEL.hpp"
using namespace std;

//quick sort functions for domestic students 
int partition_D( vector <DomesticStudent> &vec, int l, int h, int critera);
void quicksort_D(vector <DomesticStudent> &vec, int criteria);
void swap_Domestic(DomesticStudent* x, DomesticStudent* y);

//quick sort functions for international students 
int partition_I( vector <InternationalStudent> &vec, int l, int h, int critera);
void quicksort_I(vector <InternationalStudent> &vec, int criteria);
void swap_International(InternationalStudent* x, InternationalStudent* y);



//Sorting functions for domestic students 

// sort by CGPA (high to low)
//criteria is 1 for cgpa sort 
void SortByCGPA_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 1);

}
// sort by research score (high to low)
//criteria is 2 for research score sort 
void SortByResearchScore_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 2);
}
//sort by first name (a-z)
//criteria is 3 for first name sort 
void SortByFirstName_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 3);
} 
//sort by last name (a-z)
//critera is 4 for last name sort 
void SortByLastName_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 4);
}

//sort by the province 
//critera is 5 for province sort 
void SortByProv_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 5);
}
//sorting overall 
// based on research score, then CGPA, then province/country; ascending order
void SortOverall_D(vector <DomesticStudent> &students)
{
    quicksort_D(students, 6);

}

//Sorting functions for international students 
// sort by CGPA (high to low)
void SortByCGPA_I(vector <InternationalStudent> &students)
{
    quicksort_I(students, 1);
}
// sort by research score (high to low)
void SortByResearchScore_I(vector  <InternationalStudent> &students)
{
    quicksort_I(students, 2);
} 
//sort by first name (a-z)
void SortByFirstName_I(vector  <InternationalStudent> &students)
{
    quicksort_I(students, 3);
}
//sort by last name (a-z) 
void SortByLastName_I(vector  <InternationalStudent> &students)
{
    quicksort_I(students, 4);
} 

void SortByCountry_I(vector  <InternationalStudent> &students)
{
    quicksort_I(students, 5);
}

void SortByTofel_I(vector  <InternationalStudent> &students)
{
    quicksort_I(students, 6);
}

//sorting overall 
// based on research score, then CGPA, then province/country; ascending order
void SortOverall_I(vector <InternationalStudent> &students)
{
    quicksort_I(students, 7);
}

//this funstion swaps the value of two elements 

void swap_Domestic(DomesticStudent* x, DomesticStudent* y)
{
    DomesticStudent temp = *x;
    *x = *y;
    *y = temp;
}

//This function partitions the array into low and high values 
//using the last element as the pivot
//places the low values on the left of the pivot and the high values on the right

int partition_D(vector <DomesticStudent> &vec, int l, int h, int critera)
{
    DomesticStudent x = vec[h];//.get_student_CGPA();
    int i = (l - 1);
    //compare each value with the last value and then swap with 
    //the right element if necessary 
    for (int j = l; j <= h - 1; j++) 
    {
        if (critera==1)
        {
            if ((compareCGPA(vec[j],x))==0) //if x (student h) is greater than student j
            {
                i++;
                swap_Domestic(&vec[i], &vec[j]);
            }
        }
        else if (critera==2)
        {
            if ((compareResearchScore(vec[j],x))==0) //if x (student h) is greater than student j
            {
                i++;
                swap_Domestic(&vec[i], &vec[j]);
            }
        }
        else if (critera==3)
        {
            if ((compareFirstName(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_Domestic(&vec[i], &vec[j]);
            }
        }
        else if (critera==4)
        {
            if ((compareLastName(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_Domestic(&vec[i], &vec[j]);
            }
        }
        else if (critera==5)
        {
            if ((compareProv(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_Domestic(&vec[i], &vec[j]);
            }
        }
        else if (critera==6)//overall sorting 
        {
             if (compareResearchScore(vec[j],x) == 1) 
            {
                i++;
               swap_Domestic(&vec[i], &vec[j]);
            }
            //if research scores are the same 
            else if (compareResearchScore(vec[j],x) == 2) 
            {
                if (compareCGPA(vec[j],x) == 1) 
                { 
                    i++;
                    swap_Domestic(&vec[i], &vec[j]);
                }
                // if cgpas are equal 
                else if (compareCGPA(vec[j],x) == 2) 
                { 
                    if (compareProv(vec[j],x) == 1) 
                    {
                        i++;
                        swap_Domestic(&vec[i], &vec[j]);
                    }
                }
            }
        }

    }
    swap_Domestic(&vec[i + 1], &vec[h]);
    // and swapping with the right value 
    return (i + 1);
}


void quicksort_D(vector <DomesticStudent> &vec, int criteria )
{
    int low= 0; 
    int high= vec.size()-1; 
    int temp[vec.size()-1]; 

    int top= -1; 
    temp [++top]= low;
    temp[++top]= high; 
    while (top>= 0)
    {
        high=temp[top--];
        low= temp[top--];
        //put the pivot element at the right place 
        int pivot = partition_D(vec, low, high, criteria);
        //if there are elements on the left of the pivot 
        //add it to the left side of the array 
        if (pivot- 1 > low)
        {
            temp[++top] = low;
            temp[++top] = pivot - 1;
        }
        //if there are elements on the right of the pivot 
        //add it to the right side of the array 
        if (pivot + 1 < high) 
        {
            temp[++top] = pivot + 1;
            temp[++top] = high;
        }
    }
  
}

void swap_International(InternationalStudent* x, InternationalStudent* y)
{
    InternationalStudent temp = *x;
    *x = *y;
    *y = temp;
}

int partition_I(vector <InternationalStudent> &vec, int l, int h, int critera)
{
    InternationalStudent x = vec[h];
    int i = (l - 1);
    //compare each value with the last value and then swap with 
    //the right element if necessary 
    for (int j = l; j <= h - 1; j++) 
    {
        if (critera==1)
        {
            if ((compareCGPA(vec[j],x))==0) //if x has higher gpa
            {
                i++;
                swap_International(&vec[i], &vec[j]);
            }
        }
        else if (critera==2)
        {
            if ((compareResearchScore(vec[j],x))==0) //if x has highr research score 
            {
                i++;
                swap_International(&vec[i], &vec[j]);
            }
        }
        else if (critera==3)
        {
            if ((compareFirstName(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_International(&vec[i], &vec[j]);

            }
        }
        else if (critera==4)
        {
            if ((compareLastName(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_International(&vec[i], &vec[j]);
            }
        }
        else if (critera==5)
        {
            if ((compareCountry(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_International(&vec[i], &vec[j]);
            }
        }
        else if (critera==6)
        {
            if ((compareTofel(vec[j],x))==1) //if x (student h) is greater than student j
            {
                i++;
                swap_International(&vec[i], &vec[j]);
            }
        }
        else if (critera==7)//overall sorting 
        {
            if (  (compareResearchScore(vec[j],x))==1 ) //if x (student h) is greater than student j
            {
                i++;
                swap_International(&vec[i], &vec[j]);
                
            }
            else if (compareResearchScore(vec[j],x) == 2) //same research score 
                {
                    if (compareCGPA(vec[j],x) == 1) 
                    { 
                        i++;
                       swap_International(&vec[i], &vec[j]);
                    }
                    // if cgpas are equal 
                    else if (compareCGPA(vec[j],x) == 2) 
                    { 
                        if (compareCountry(vec[j],x) == 1) 
                        {
                            i++;
                           swap_International(&vec[i], &vec[j]);
                        }
                    }
                }
        }
        

    }
    swap_International(&vec[i + 1], &vec[h]);
    // and swapping with the right value 
    return (i + 1);
}



//this function uses the quick sort algorithm to sort an array 
///it return the number of barometer operations 
void quicksort_I(vector <InternationalStudent> &vec, int criteria )
{
    int low= 0; 
    int high= vec.size()-1; 
    int temp[vec.size()-1]; 

    int top= -1; 
    temp [++top]= low;
    temp[++top]= high; 
    while (top>= 0)
    {
        high=temp[top--];
        low= temp[top--];
        //put the pivot element at the right place 
        int pivot = partition_I(vec, low, high, criteria);
        //if there are elements on the left of the pivot 
        //add it to the left side of the array 
        if (pivot- 1 > low)
        {
            temp[++top] = low;
            temp[++top] = pivot - 1;
        }
        //if there are elements on the right of the pivot 
        //add it to the right side of the array 
        if (pivot + 1 < high) 
        {
            temp[++top] = pivot + 1;
            temp[++top] = high;
        }
    }
  
}


