//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "bst.hpp"
using namespace std;
using namespace ENSC251_Lab3;

int main()
{
  //inserting the keys into bst1
    BinarySearchTree bst1;
    int arr[14] = {10, 5, 15, 3, 7, 13, 18, 4, 6, 9, 8, 16, 19, 17}; //make an array that contain all the node key
    for (int i=0; i < 14; i++)
  { //using a for loop to insert all the node key
        bst1.insertNode(arr[i]);
    cout <<bst1;
    cout<<endl;
  }

  //creating bst2 and bst3
      BinarySearchTree bst2, bst3;
    bst3=bst2=bst1;
    cout<<"BST2"<<endl;
    cout<<bst2;
    cout<<endl;
    cout<<"BST3"<<endl;
    cout<<bst3;
    cout<<endl;
    //creating bst4
      BinarySearchTree bst4(bst3);
    cout<<"BST 4"<<endl;
    cout<<bst4;
    cout<<endl;

    cout<<"BST 1 after deletion of nodes 4 and 9: "<<endl;
    //deleting keys 9 and 4 from bst 1
    bst1.deleteNode(9);
    cout <<bst1;
    cout<<endl;
    bst1.deleteNode(4);
    cout <<bst1;
    cout<<endl<<endl;
    //deleting key 10  from bst 2
    cout<<"BST 2: "<<endl;
    bst2.deleteNode(10);
    cout<<"BST 2 after deletion of node 10:  "<<endl;
    cout<<bst2;
    cout<<endl;
    //deleting keys 3,9,16 from bst 3
    cout<<"BST 3: "<<endl;
    bst3.deleteNode(3);
    cout<<"BST 3 after deletion of nodes 3: "<<endl;
    cout<<bst3;
    cout<<endl;
    bst3.deleteNode(9);
    cout<<"BST 3 after deletion of nodes 3 and 9: "<<endl;
    cout<<bst3;
    cout<<endl;
    bst3.deleteNode(16);
    cout<<"BST 3 after deletion of nodes 3,9 and 16: "<<endl;
    cout<<bst3;
    cout<<endl;
    //deleting keys 18,7,10 from bst 4
    cout<<"BST 4: "<<endl;
    bst4.deleteNode(18);
    cout<<"BST 4 after deletion of node 18: "<<endl;
    cout<<bst4;
    cout<<endl;
    bst4.deleteNode(7);
    cout<<"BST 4 after deletion of node 7,18: "<<endl;
    cout<<bst4;
    cout<<endl;
    bst4.deleteNode(10);
    cout<<"BST 4 after deletion of node 10,7 and 18: "<<endl;
    cout<<bst4;

//printing out all trees
    cout<<endl;
    cout<<"Printing all for trees: "<<endl;
    cout<<"BST1 :" <<endl;
    cout<<bst1;
    cout<<endl;
    cout<<"BST2 :" <<endl;
    cout<<bst2;
    cout<<endl;
    cout<<"BST3 :" <<endl;
    cout<<bst3;
    cout<<endl;
    cout<<"BST4 :" <<endl;
    cout<<bst4;


    bool loop = 0;
    int option;
    int key_1;
    int inner_loop = 0;
    char input;

cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "Welcome to our binary search tree! "<<endl<<endl;
    cout << "There are 6 options to choose from ranging from i to vi. " <<endl;
    cout << "To select an option, input one of the listed integers below ranging from 1 to 6:  "<<endl<<endl;
    cout << "Press 1-6 to input for options i-vi, respectively. "<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"Please choose from the options below: "<<endl<<endl;
   
    while (loop == 0)
    {
        cout << "1. search a key" << endl;
          cout << "2. search the successor node of a key" << endl;
          cout << "3. insert a key" << endl;
          cout << "4. delete a key" << endl;
          cout << "5. print out" << endl;
        cout << "6. exit the program" << endl << endl;
        // asks the user whether they would prefer to choose between
        cout << "Please choose an option from 1 to 6: "<<endl;
        
        cin >> option;
            // clears and resets the input if it's invalid, then asks again.
            if(std::cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter an option from the menu."<<endl;
            }

            // option to search a key in bst4
            if (option == 1)
            {
                // loop to repeat option 1
                while (inner_loop == 0)
                {
                    cout << "What key is to be searched: " << endl;
                    cin >> key_1;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another key from the menu."<<endl;
                    }
                    
                    // Creates a temporary pointer to store the returned node from the inputed key.
                    NodePtr temp = bst4.searchNode(key_1);
                    
                    // if the temp pointer is not NULL, output the key value, and the key values of its parent, left and right chidren
                    if (temp != NULL)
                    {
                        cout << "the key " << temp->key << " is in the tree\n";
                        // if the left child exists then output its value
                        if (temp->left != NULL)
                        {
                            cout << "the left child node is " << temp->left->key << endl;
                        }
                        // if the right child exists then output its value
                        if (temp->right != NULL)
                        {
                            cout << "the right child node is " << temp->right->key << endl;
                        }
                        // if the parent exists then output its value
                        if (temp->parent != NULL)
                        {
                            cout << "the parent node is " << temp->parent->key << endl;
                        }
                        cout << bst4 << endl << endl;
                        //cancels the loop
                        inner_loop = 1;
                    }
                    
                    // if the temp pointer does not exist, it outputs that the key is not found in the tree
                    else
                    {
                        cout << "the key not found in the tree" << endl;
                    }
                    
                    cout << "If you wish to search another successor press y, if not press anything else ";
                    cin >> input;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another input from the menu."<<endl;
                    }
                    
                    // if user inputs y, the loop continues
                    if (input == 'y')
                    {
                        inner_loop = 0;
                    }
                }
                // resets inner loop back to 0 for the next while loop
                inner_loop = 0;
            }
          
            // option to search the successor node of a key in bst4
            else if (option == 2)
            {
                while (inner_loop == 0)
                {
                    cout << "What successor node is to be searched: ";
                    cin >> key_1;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another option from the menu."<<endl;
                    }
                    
                    // Creates a temporary pointer to store the returned node from the inputed key.
                    NodePtr successor = bst4.searchSuccessor(key_1);
                    
                    // if the successor does not exist
                    if (successor == NULL)
                    {
                        cout << "can't find a successor from the tree\n";
                    }
                    // if the successor does exist: print the key value, the key values of its parent, left and right chidren
                    else
                    {
                        cout << "the successor node is " << successor->key << endl;
                        
                        // if the left child exists then output its value
                        if (successor->left != NULL)
                        {
                            cout << "the left child of the successor node is " << successor->left->key << endl;
                        }
                        // if the right child exists then output its value
                        if ( successor->right != NULL)
                        {
                            cout << "the right child of the successor node is " << successor->right->key << endl;
                        }
                        // if the parent exists then output its value
                        if (successor->parent != NULL)
                        {
                            cout << "the parent of the successor node is " << successor->parent->key << endl;
                        }
                    }
                    cout << bst4 << endl << endl;
                    inner_loop = 1;
                    
                    cout << "If you wish to search another successor press y, if not press anything else ";
                    cin >> input;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another input from the menu."<<endl;
                    }
                    // if the input is y, continue the loop
                    if (input == 'y')
                    {
                        inner_loop = 0;
                    }
                }
                inner_loop = 0;
            }
            
            // option to insert a key into bst4
            else if (option == 3)
            {
                while (inner_loop == 0)
                {
                    cout << "What node is to be inserted: " << endl;
                    cin >> key_1;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another node."<<endl;
                    }
                    // inserts node to bst4 from the selected key value
                    bst4.insertNode(key_1);
                    cout << endl;
                    cout << bst4 << endl << endl;
                    inner_loop = 1;
                        
                    cout << "If you wish to search another successor press y, if not press anything else ";
                    cin >> input;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another input from the menu."<<endl;
                    }
                        
                    if (input == 'y')
                    {
                        inner_loop = 0;
                    }
                }
                inner_loop = 0;
            }
            
            // option to delete a key from bst4
            else if (option == 4)
            {
                while (inner_loop == 0)
                {
                    cout << "What node is to be deleted: " << endl;
                    cin >> key_1;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another node."<<endl;
                    }
                    
                    bst4.deleteNode(key_1);
                    cout << endl;
                    cout << bst4 << endl;
                    inner_loop = 1;
                    
                    cout << "If you wish to search another successor press y, if not press anything else ";
                    cin >> input;
                    if(std::cin.fail())
                    {
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "Please enter another input from the menu."<<endl;
                    }
                        
                    if (input == 'y')
                    {
                        inner_loop = 0;
                    }
                }
                inner_loop = 0;
            }
            
            // option to print out bst4
            else if (option == 5)
            {
                cout << "Printed bst4: " << endl << endl;
                cout << bst4 << endl;
            }
         
            
            // option to exit the program
            else if (option == 6)
            {
                cout << "You have exited the program." <<endl << endl;
                //changes the loop value to end the loop
                loop = 1;
            }
            
            // if an option selected does not exist, run through the loop again
            else
            {
                cout << "The option you chose does not exist. Please choose again." << endl;
            }
        }


  return 0;
}
