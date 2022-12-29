//main file created by 
//Samin Moradkhan and James Ryan Martin 
//July 2022 

#include "stack.hpp"

#include <stdio.h>
#include <iostream>
#include <cstddef>
#include <vector>
#include <ctype.h>


using namespace std;


int main()
{
    Stack<int> sint1;
    Stack<int> sint2=sint1;
    //pushing 1-6 into the stack sint1 
    sint1.push(1);
    sint1.push(2);
    sint1.push(3);
    sint1.push(4);
    sint1.push(5);
    sint1.push(6);
    //initializing sint2 by sint1 using the overloading assignment operator  
    sint2=sint1; 
    //printing sint2 
    cout<<"Printing sint2: "<<endl;
    printStack(sint2);
    cout<<endl;
    cout<<"Printing sint1: "<<endl; 
    //reversing sint1
    sint1.reverse();
    //printing sint1 
    printStack(sint1);
    cout<<endl; 
    Stack <double> sdouble1; 
    //pushing 1.5,2.5... to 6.5 into a stack 
    sdouble1.push(1.5);
    sdouble1.push(2.5);
    sdouble1.push(3.5);
    sdouble1.push(4.5);
    sdouble1.push(5.5);
    sdouble1.push(6.5);
    //printing sdoubl1
    cout<<"Printing sdouble1: "<<endl; 
    printStack(sdouble1);
    //initializing sdouble1 with sdouble2 using the copy constructor
    Stack <double> sdouble2(sdouble1); 
    sdouble2.reverse(); 
    cout<< endl<<"Top of sdouble2: "<< sdouble2.get_val()<<endl; 
    //asking a user to input a string and then showing them the palindrome
    string user_input;
    int loop=1;  
    while (loop)
    {
        cout<<"Please input a string:   "; 
        cin>> user_input; 

        Stack <char> palindrome; 

        for (int i=0; i<user_input.size(); i++)
        {
            palindrome.push(user_input[i]); 
        }

        cout<<"The palindrome is: "<<endl; 
        //creating the palindrome by print the word and its reversed word followed by that 
        palindrome.reverse(); 
        printStack(palindrome); 
        palindrome.reverse(); 
        printStack(palindrome); 
        cout<<endl;
        char end; 
        cout<<"Would you like to continue? if yes press y.  ";
        cin>>end;
        if (end== 'y' || end== 'Y')
        {
            loop=1; 
        }
        else
        {
            loop=0; 
        }

    }
 
    return 0; 
}
