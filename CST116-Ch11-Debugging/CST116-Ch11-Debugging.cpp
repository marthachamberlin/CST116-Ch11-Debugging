/********************************************************************
* File: Chapter 11 Debug.cpp
*
* General Instructions: Complete each step before proceeding to the
* next.
*
* Debugging Exercise 1
*
* 1) Make your own data file like Troy 12, with the next person on the
*    next line and save it to a directory you create on your drive.
* 2) Under the Project menu, select Add Existing Item and
*    add the input file you just placed on your drive to your
*    current project. Make sure your Solution Explorer window
*    is visible. If not, you can display it by selecting Solution
*    Explorer (or Ctrl+Alt+L).
* 3) Open the input file by simply double clicking the name of the
*    file in your Solution Explorer.
* 4) Build and execute the program.
* 5) Update the file paths below to correctly represent the path you
*    created.
* 6) Rebuild and execute the program.
* 7) Examine the code and the output and notice the use of
*    parallel arrays.
* 8) Add the output file created via the execution of
*    your program to your Project.  Execute your program again
*    and notice how Visual Studio has rewritten your output file
*    and asks if you would like to reload the file (select Yes).
* 9) Examine the contents of both the input and the output file.
* 10) Fix all the problems in your code that exist in relation to
*     the output. Verify that your output is appropriate for your
      input file.
* 11) Build and execute your code until you have all errors
*     removed and all the output is correct.
*
* Debugging Exercise 2
*
* 1) Replace the double slashes (\\) in the input file open statement
*    with only a single slash
*    (i.e., inFile.open("C:\TEMP\Chap_11_data.txt").
* 2) Build your code, noticing the impact of the invalid path you
*    created in the previous step.
* 3) Replace the backslashes as they were.
* 4) Change both the input and output filenames so they are
*    invalid.
* 5) Update the file related error messages within the code
*    to also provide the specific name of the file that is having a
*    problem.
* 6) Rebuild and execute your program to verify that your messages
*    are correct.
* 7) Correct the path names.
* 8) Build and execute your code and carefully check your
*    output on both the console and in the output file.
*
********************************************************************/
#include <iostream>
#include <fstream>	// For the files!!!!
#include <iomanip>	// For manipulators & formatting options
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::ios;

using std::ifstream;
using std::ofstream;

const int EMPLOYEES = 20;
const int MAX = 21;

int ReadData(ifstream& inFile, ofstream& outFile, char name[][MAX], int age[]);
void WriteOutputFile(ofstream& outFile, char name[][MAX], int age[],
    int counter);
void PrintTotalsAndSummary(ofstream& out, int totalRecords);

int main()
{
    char name[EMPLOYEES][MAX];
    int age[EMPLOYEES];
    int record_counter(0);

    ifstream inFile;

    // Notice how this automatically opens the file
    ofstream outFile("C:\\TEMP\\Chap_11_Report.txt");

    inFile.open("C:\\TEMP\\Chap_11_data.txt");

    if (inFile.is_open())
    {
        record_counter = ReadData(inFile, outFile, name, age);
        inFile.close();

        if (outFile.is_open())
        {
            WriteOutputFile(outFile, name, age, record_counter);
            PrintTotalsAndSummary(outFile, record_counter);
            outFile.close();
        }
        else
        {
            cout << "Trouble Opening File";
            cout << "\n\n\t\t ** About to EXIT NOW! ** ";
        }
    }
    else
    {
        cout << "Trouble Opening File";
        cout << "\n\n\t\t ** About to EXIT NOW! ** ";
    }
    return 0;
}
int ReadData(ifstream& inFile, ofstream& outFile, char name[][MAX], int age[])
{
    int counter = 0;
    inFile >> name[counter] >> age[counter]; // Priming Read

    while (!inFile.eof())
    {
        cout << setiosflags(ios::left) << setw(25)
            << name[counter] << resetiosflags(ios::left)
            << setw(4) << age[counter] << endl;
        counter++;
        inFile >> name[counter] >> age[counter];
    }

    return counter;
}
void WriteOutputFile(ofstream& outFile, char name[][MAX], int age[], int counter)
{
    outFile << "   Here is the Output File" << endl;
    for (int r = 0; r <= counter; r++)
    {
        outFile << setiosflags(ios::left) << setw(25)
            << name[r] << setw(4)
            << resetiosflags(ios::left) << age[r]
            << endl;
    }
}
void PrintTotalsAndSummary(ofstream& outFile, int totalRecords)
{
    // To screen
    cout << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";

    // To file
    outFile << "\n\n\t** Total Records: " << totalRecords << " **\n"
        << "\t\t The End \n";
}
