// Jeff Leonard 
// CS 3800
// Binary Search Assignment Due 9-17
// Write a quick binary search progam using the attached sorted ints file - count comparisons. Test for 0, 200000, and 2 - 2 between 1000 and 50000 and 2 between 50001 and 99999.
//Write your results to an output file named: xyz.out - where xyz is replaced by your initials


#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int timesRan = 0;

int binarySearch(int arr[], int input, int lowEnd, int highEnd)
{

    if (highEnd >= lowEnd)
    {
        int middle = lowEnd + (highEnd - lowEnd) / 2;

        if (arr[middle] == input) // returns middle if it is equal to it
        {
            timesRan++;
            return middle;
        }

        if (arr[middle] > input)
        {
            timesRan++;
            return binarySearch(arr, input, lowEnd, middle - 1); // searches left side
        }

        timesRan++;
        return binarySearch(arr, input, middle + 1, highEnd); // searches right side
    }

    timesRan++;
    return 0;
}

int readFile(int arr[])
{
    ifstream myfile;
    myfile.open("ints.txt"); // opens file
    string line;
    int input = 0;   // the number after converted from string to int
    int counter = 0; // counts how many numbers there are

    cout << "Unsorted:" << endl;
    while (!myfile.eof()) // runs to end of file printing out the original group of numbers to prove it is unsorted
    {
        getline(myfile, line);
        counter++;
    }
    cout << endl;
    arr[counter];    // array initialization
    myfile.seekg(0); // resets to the beginning of the file

    while (!myfile.eof()) // converts the line string to an int
    {
        for (int i = 0; i < counter; i++)
        {
            getline(myfile, line);
            input = stoi(line);
            arr[i] = input;
        }
    }

    myfile.close();
    return (counter);
}

void commandLineInput(int arr[], int counter)
{
    ofstream outFile;
    outFile.open("jwleonard.out.txt");

    int userChoice = 0;

    while (userChoice != 2) // runs the user input until they choose stop
    {
        timesRan = 0;
        cout << "1. run search \n2. stop " << endl;
        cin >> userChoice;
        if (userChoice == 1)
        {
            int userInput;
            cout << "Enter an number to search: " << endl;
            cin >> userInput;

            int result = binarySearch(arr, userInput, 0, counter - 1);

            cout << "Comparisons ran: " << timesRan << endl;

            outFile << "-------------------------------------------" << endl;
            outFile << "number searched: " << userInput << endl;
            outFile << "Comparisons ran: " << timesRan << endl;

            if (result == 0)
            {
                cout << "sorry your number was not in the file." << endl;
                outFile << "sorry your number was not in the file." << endl;
                outFile << "-------------------------------------------" << endl;
            }
            else
            {
                cout << "Element was found at index " << result << endl;
                outFile << "Element was found at index " << result << endl;
                outFile << "-------------------------------------------" << endl;
            }
        }
    }
    outFile.close();
}
int main(void)
{
    ifstream myfile;
    myfile.open("sortedints.txt"); // opens file
    string line;
    int input = 0;   // the number after converted from string to int
    int counter = 0; // counts how many numbers there are

    while (!myfile.eof()) // runs to end of file printing out the original group of numbers to prove it is unsorted
    {
        getline(myfile, line);
        //cout << line << " ";
        counter++;
    }
    cout << endl;
    int arr[counter]; // array initialization
    myfile.seekg(0);  // resets to the beginning of the file

    while (!myfile.eof()) // converts the line string to an int
    {
        for (int i = 0; i < counter; i++)
        {
            getline(myfile, line);
            input = stoi(line);
            arr[i] = input;
        }
    }
    myfile.close();

    commandLineInput(arr, counter);
}
