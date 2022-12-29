//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <vector> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"
#include "stu_sort.hpp"
#include "Domestic.hpp"
#include "International.hpp"



//helper functions 
void Create_Domestic(vector <DomesticStudent> &DomesticStudents)
{
  string line;
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;

  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(domesticFile, line);
  //cout << "File format: " << line << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */
  int stu_count = 1;
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, province, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    DomesticStudent stuD;
    stuD.set_Applicant(firstName, lastName, cgpa , researchScore); 
    stuD.set_province(province);
    stuD.set_studentID(stu_count);
    DomesticStudents.push_back(stuD);
    
    //print the student info to the screen
    /*cout << "Domestic student " << stu_count << " " << firstName << " " 
	 << lastName << " from " << province << " province has cgpa of "
	 << cgpa << ", and research score of " << researchScore << endl;*/

    stu_count++;
  }
  //close your file
  domesticFile.close();
}

void Create_International(vector<InternationalStudent> &InternationalStudents)
{
  string line;
  ifstream InternationalFile("international-stu.txt");
  if(!InternationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
  }

  //Read the first line of domestic-stu.txt, which specifies
  //the file format. And then print it out to the screen
  getline(InternationalFile, line);
  //cout << "File format: " << line << endl;

  /*Keep reading the rest of the lines in domestic-stu.txt.
   *In the example code here, I will read each data separated
   *by a comma, and then print it out to the screen.
   *In your lab assignment 1, you should use these read data
   *to initialize your DomesticStudent object. Then you can
   *use get and set functions to manipulate your object, and
   *print the object content to the screen
   */
  int stu_count = 1;
  while( getline(InternationalFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases. We will leave the
     *error and exception handling of file format to Lab Assignment 4
     */
    istringstream ss(line);

    string firstName, lastName, country , s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
    float cgpa;
    int researchScore, reading, listening, speaking, writing;

    //get firstName separated by comma
    getline(ss, firstName, ',');

    //get lastName separated by comma
    getline(ss, lastName, ',');

    //get province separated by comma
    getline(ss, country, ',');

    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    getline(ss, s_reading, ',');
    reading = atoi(s_reading.c_str());
    //get listening separated by comma, and convert it to int
    getline(ss, s_listening, ',');
    listening = atoi(s_listening.c_str());
    //get writing separated by comma, and convert it to int
    getline(ss, s_speaking, ',');
    speaking = atoi(s_speaking.c_str());
    //get reading separated by comma, and convert it to int
    getline(ss, s_writing, ',');
    writing = atoi(s_writing.c_str());

    InternationalStudent stuI;
    stuI.set_Applicant(firstName, lastName, cgpa , researchScore); 
    stuI.set_Country(country);
    stuI.set_Toefl(reading, listening, speaking, writing);
    stuI.set_studentID(stu_count);
    InternationalStudents.push_back(stuI);

    //print the student info to the screen
    /*cout << "Domestic student " << stu_count << " " << firstName << " " 
	 << lastName << " from " << province << " province has cgpa of "
	 << cgpa << ", and research score of " << researchScore << endl;*/

    stu_count++;
  }
  //close your file
  InternationalFile.close();
}


/*I provide example code here to help you read the input
 *data from a file, so that you can focus on creating
 *and manipulating classes and objects
 */

//void Create_Domestic(vector <DomesticStudent> & stu);
//void Create_International(vector <InternationalStudent> & stu);

int main(){
  //Read the domestic-stu.txt file and exit if failed
vector<DomesticStudent> stuDom;
vector<InternationalStudent> stuInt; 
Create_Domestic(stuDom);
Create_International(stuInt);
/*SortOverall_I(stuInt);
SortOverall_D(stuDom);*/

    // variable introduction
    bool loop = 0;
    int inner_loop = 0;
    char option;
    char input;
    char studentType;
    
    // user interface to summarize the options to our users
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout << "Welcome to our Graduate Student Admission System!"<<endl<<endl;
    cout << "Before you select a sorting option, please note:"<<endl<<endl;
    cout << "For Domestic students, there are four sorting categories:"<<endl;
    cout << "Students are sorted based on their CGPA, Research Score, First Name, Last Name, or Overall."<<endl;
    cout << "For International students, there are four sorting categories:"<<endl;
    cout << "Students are sorted based on their CGPA, Research Score, First Name, Last Name, Toefl score, or Overall."<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl;
    cout<<"Please choose from the options below: "<<endl<<endl;

    // loop to allow user to continuously change their sorting type and option
    while (loop == 0)
    {
        // asks the user whether they would prefer to sort for international or domestic students, then takes their input for the decision
        cout << "Would you like to sort international or domestic studnts? " << endl;
        cout << "Press D for domestic and I for international: ";
        cin >> studentType;
            // clears and resets the input if it's invalid, then asks again.
            if(std::cin.fail())
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter an option from the menu."<<endl;
            }
 
        // if the user chooses 'd' for domestic, provides the user with the five sorting options
        if (studentType == 'd' || studentType == 'D')
        {
            // asks for user input to choose a sorting option
            cout << endl << endl<< "Please choose the option you want to sort domestic student admissions by: " << endl << "Press c for CGPA, r for Research Score, F for First name, L for Last name, and o for Overall " << endl << "Input: ";
            cin >> option;

            // sorting option to sort by CGPA
            if (option == 'c' || option == 'C')
            {
                SortByCGPA_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions sorted by CGPA: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                
                // prints out every index of the dometic student vector
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
            }
            
            // sorting option to sort by Research Score
            else if (option == 'r' || option == 'R')
            {
                SortByResearchScore_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions sorted by Research Score: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
            }
            
            // sorting option to sort by First Name
            else if (option == 'f' || option == 'F')
            {
                SortByFirstName_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions sorted by First Name: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
                cout << endl;
            }
            
            // sorting option to sort by Last Name
            else if (option == 'l' || option == 'L')
            {
                SortByLastName_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions sorted by Last Name: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
                cout << endl;
            }
            
            // sorting option to sort by Province
            else if (option == 'p' || option == 'P')
            {
                SortByProv_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions overall sorted by Province: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
                cout << endl;
            }
            
            // sorting option to sort Overall, which is by all the options listed above
            else if (option == 'o' || option == 'O')
            {
                SortOverall_D(stuDom);
                cout << endl;
                cout << "Graduate domestic student admissions overall sorted by all sorting options : " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Province  "<<"        CGPA        "<< "      Research Score"<<endl<<endl;
                for (int i=0; i<100; i++)
                {
                    cout << stuDom[i];
                }
                cout << endl;
            }
            
            // if a char is inputted that is not a valid option char, repeats the process
            else
            {
                cout << "The option you chose does not exist. Please choose again." << endl;
                inner_loop=1; 
            }
        
           // creates a loop to keep asking whether user are satisfied with the sort or not, then takes user's input
            while (inner_loop == 0)
            {
                cout << "If you are satisfied with the sorting of the data, please press y. If you would like to choose another sorting method, please press n. " << endl << "Confirm: ";
                cin >> input;
                
                // if the user input is 'y' then it closes the  current inner loop and the main loop for sorting
                if (input == 'y')
                {
                    loop = 1;
                    inner_loop = 1;
                }
                
                // if the user input is 'n' then it closes the current inner loop but not the main loop. Restarts the process
                else if (input == 'n')
                {
                    loop = 0;
                    inner_loop = 1;
                }
                
                // if any other char is entered other than 'y' or 'n', it repeats the loop and asks for a valid input
                else
                {
                    cout << "The option you have confirmed, does not exist." << endl << "Confirm: ";
                }
            }
            // resets inner loop back to 0 for the next inner_loop
            inner_loop = 0;
    }
    
        // if the user chooses 'i' for international, provides the user with the six sorting options
        if (studentType == 'i'  || studentType == 'I')
        {
            // asks for user input to choose a sorting option
            cout << "Please choose the option you want to sort the international admissions by: " << endl << "Press c for CGPA, r for Research Score, F for First name, L for Last name, t for Toefl, and o for Overall " << endl << "Input: ";
            cin >> option;
            
            // sorting option to sort by CGPA
            if (option == 'c' || option == 'C')
            {
                SortByCGPA_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by CGPA: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                  cout << stuInt[i];
                  
                }
                cout << endl;
            }
            
            // sorting option to sort by Research Score
            else if (option == 'r' || option == 'R')
            {
                SortByResearchScore_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by Research Score: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                  cout << stuInt[i];

                }
                cout << endl;
            }
            
            // sorting option to sort by First Name
            else if (option == 'f' || option == 'F')
            {
                SortByFirstName_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by First Name: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                    cout <<stuInt[i];
                    
                    
                }
                cout << endl;
            }
            
            // sorting option to sort by Last Name
            else if (option == 'l' || option == 'L')
            {
                SortByLastName_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by Last Name: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                    cout << stuInt[i];

                }
                cout << endl;
            }
            
            // sorting option to sort by Country
            else if (option == 'k' || option == 'K')
            {
                SortByCountry_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by their country: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                  cout << stuInt[i];

                }
                cout << endl;
            }
            
            // sorting option to sort by Toefl
            else if (option == 't' || option == 'T')
            {
                SortByTofel_I(stuInt);
                cout<<endl;
                cout << "Graduate international student admissions sorted by Toefl score: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {

                  cout << stuInt[i];

                }
                cout << endl;
            }
            
            // sorting option to sort Overall, which is by all the options listed above
            else if (option == 'o' || option == 'O')
            {
                SortOverall_I(stuInt);
                cout<<endl;
                cout << "Graduate domestic student admissions overall sorted by all sorting options: " <<endl;
                cout<< "First Name        "<< "Last Name        "<<" Country  "<<"     CGPA        "<< "Research Score"<< "    Toefl Score"<< endl<<endl;
                for (int i=0; i<100; i++)
                {  
                  if (stuInt[i].valid_Toefl(stuInt[i]))
                  {
                    cout << stuInt[i];
                  }
                }
                cout << endl;
            }
            
            // if a char is inputted that is not a valid option char, repeats the process
            else
            {
                cout << "The option you chose does not exist. Please choose again." << endl;
                inner_loop=1; 
            }
            
            // creates a loop to keep asking whether user are satisfied with the sort or not, then takes user's input
            while (inner_loop == 0)
            {
                cout << "If you are satisfied with the sorting of the data, please press y. If you would like to choose another sorting method, please press n. " << endl << "Confirm: ";
                cin >> input;
                
                // if the user input is 'y' then it closes the  current inner loop and the main loop for sorting
                if (input == 'y')
                {
                    loop = 1;
                    inner_loop = 1;
                }
                
                // if the user input is 'n' then it closes the current inner loop but not the main loop. Restarts the process
                else if (input == 'n')
                {
                    loop = 0;
                    inner_loop = 1;
                }
                
                // if any other char is entered other than 'y' or 'n', it repeats the loop and asks for a valid input
                else
                {
                    cout << "The option you have confirmed, does not exist." << endl << "Confirm: ";
                }
            }
            // resets inner loop back to 0 for the next inner_loop
            inner_loop = 0;
            
        }
    }

  return 0;
}



