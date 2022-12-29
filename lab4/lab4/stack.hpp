// stack header file created by 
//Samin Moradkhan and James Ryan Martin 
//July 2022 
#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <iostream>
#include <cstddef>
#include <vector>

using namespace std;
// explicit instantiations

// using template to generalize stack class and member functions
template<class T> struct StackFrame; 
//template<class T> using StackFramePtr = StackFrame<T>*;

template<class T>
struct StackFrame 
{
    T data;
    StackFrame *link;
};


template<class T>
class Stack 
{
public:
    //default constructor
    Stack();
    //destructor 
    ~Stack();
    //copy constructor 
    Stack(const Stack<T>& copy);
    //check if the stack is empty 
    bool empty() const;
    //helper function for reverse 
    void insert_bottom(T val);
    //overloaded assignment operator
    Stack<T>& operator =(Stack<T>& ST);
    //adding to the top of the stack
    void push(T val);
    //removing and returning the top value of the stack 
    T pop(); 
    //returns the pointer to the top of the stack
    StackFrame<T>*peek() const;
    //reversing the content of the stack 
    StackFrame<T>*reverse();
    //retruns the value at the top of the stack
    T  get_val();
private:
    StackFrame<T>*top;
};

//prints the stack from top to bottom
template<class T>
void printStack (const Stack<T>& s);
#endif


//default constructor 
template<class T>
Stack<T>:: Stack()
{
    top = NULL; 
}
//destructor 
template<class T>
Stack<T>:: ~Stack() 
{
    //deleting the stack while its not empty 
    while(!empty())
    {
        pop(); 
    }
}
//copy constructor 
template<class T>
Stack<T>::Stack(const Stack<T>& copy)
{
    // check if copy_stack is empty
    if (!copy.empty())
    {
        StackFrame<T>*temp = copy.top; 
        StackFrame<T>* new_top; 
        try 
        {
            new_top = new StackFrame<T>;//allocating dynamic memory 
        }
        catch (std::bad_alloc&)
        {
            cout << "Warning! Caught bad_alloc exception.\n";
        }
        new_top->data = temp->data;
        top = new_top;
        temp = temp->link; 
        //traversing through the linked list and creating new nodes 
        while (temp != NULL) 
        {
            try 
            {
                new_top->link = new StackFrame<T>;
            }
            catch (std::bad_alloc&)
            {
                cout << "Warning! Caught bad_alloc exception.\n";

            }
            //assigning values to the new node
            new_top = new_top->link;
            new_top->data = temp->data; 
            temp = temp->link;
        }
        new_top->link = NULL; 
    }
    else 
    {
        top=NULL; 
    }   
}
//adding a value to the top of the stack 
template<class T>
void Stack<T>:: push(T val)
{
    //create a pointer
    StackFrame<T>* temp;

    // catching bad alloc
    try 
    {
        temp = new StackFrame<T> ;
    }

    catch (std::bad_alloc&)
    {
        cout << "Warning! Caught bad_alloc exception.\n";
    }
    //initilize the new node and set it to top 
    temp->data = val;
    temp->link = top;
    top = temp;

}
//checking if the stack is empty 
template<class T>
bool Stack<T>:: empty() const
{
 return (top==NULL);
}
//helper functions for reverse 
template<class T>
void Stack<T>::insert_bottom(T x)
{
    if (empty())
    {
        push(x); 
    }
    else 
    {
        T a= pop();//pop the top value and store it 
        insert_bottom(x); //insert the next value 
        push(a) ;//put the stored value back in 
    }

}
//overloaded assignment operator 
template<class T>
Stack<T> &Stack<T> ::operator =(Stack<T>& copy)
{
    if (this != &copy)
    {
        while(!empty())
        {
            pop(); 
        }
        if (!copy.empty())
        {
            StackFrame<T>*temp = copy.top; 
            StackFrame<T>* new_top; 
            try 
            {
                new_top = new StackFrame<T>;
            }
            catch (std::bad_alloc&)
            {
                cout << "Warning! Caught bad_alloc exception.\n";
    
            }
            new_top->data = temp->data;
            top = new_top;
            temp = temp->link; 
            //traverisng through linked list and creating new nodes 
            while (temp != NULL) 
            {
                try 
                {
                    new_top->link = new StackFrame<T>;
                }
                catch (std::bad_alloc&)
                {
                    cout << "Warning! Caught bad_alloc exception.\n";

                }
                //initializing the new node with data and the link pointer 
                new_top = new_top->link;
                new_top->data = temp->data; 
                temp = temp->link;
            }
            new_top->link = NULL; 
        }
        else 
        {
           top=NULL; 
        } 

    }
  
    return *this; 
}
//removes and returns the top of the stack 
template<class T>
T Stack<T>::pop() 
{
    if(empty())
    {
        cout<<"Error: the stack is empty."<<endl;
 
    }
    T temp= top->data; 
    StackFrame<T>* temp2=top; 
    //the next value becomes the top of the stack 
    top = top-> link; 
    delete temp2; 
    //returning the value of the top of the stack  
    return temp; 
}
//returns the pointer pointing to the top of the stack 
template<class T>
StackFrame<T>*Stack<T>:: peek() const
{
    return top; 
}
//reverses the order of the stack 
template<class T>
StackFrame<T>*Stack<T>::reverse()
{
    if (!empty())
    {
        T x= pop(); //poping from the top of the stack
        reverse(); //calling reverse recursively to pop from the top 
        insert_bottom(x);//inserting at the bottom of the stack
    }
    return top; 
}
//returns the value of the top of the stack
template<class T>
T Stack<T>:: get_val()
{
    return top-> data;
}

template<class T>
void printStack (const Stack <T> &s)
{
    StackFrame<T>*temp= s.peek();
    if (temp== NULL)
    {
        cout<<"The stack is empty."<<endl; 
    } //traversing the stack and printing the data
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->link;
        }

}

////**** REVERSE FUNCTION ALGORITHM TIME COMPLEXITY ANALYSIS USING BIG-O ****////
// TIME COMPLEXITY OF REVERSE: O(n^2):
//there is so many o(1) operations like the if empty() consition or the comparison with null for each call
//because there is some more call that take o(n) we can ignore the constant in the big o notation calculation

// if there is n elemnts in the stack
//the function reverse we first pop the elements one by one and call the reverse function back so that will take O(n)
//for the time complexity of reverse itself but then inside reverse we have a helper funstion called insert_bottom 
//in insert_bottom : 
//T a= pop();//pop the top value and store it --> O(1)
// insert_bottom(x); //insert the next value --O(n), its called n times as the size of the stack 
//push(a) ;//put the stored value back in -->O(1)
//so the overall running time of inser_bottom is also O(n)

//Therefore the two functions together would cost --> O(n^2) 

//Because we call the insert_bottom function n times in reverse and the insert_bottom has a time complexity of 
//O(n). 

// Resulting in O(n)* O(n)---> O(n^2)

