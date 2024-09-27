// Lab 14: Creates multiple color objects consisting of RGB values and outputs those object values to console.

#include <iostream>
#include <iomanip>
#include <vector> // For vector instead of array
#include <string>

using namespace std;

// Declare color class to store RGB values


int main()
{
    // Initialize variables
    const string DIVIDER = string(25, '*');
    const string COLOR_BAR = string(15, ' ');
    const unsigned int SIZE = 30;
    string fileLine = "";
    vector<int> colorCodes = {}; // Initialize vector, will be destroyed and redefined during file read
    vector<int>::iterator it;    // Iterator to traverse array. Not really needed because each loop redeclares iterator anyways
    unsigned int index = 0;
    // File to read from
    const string INPUT_FILE_NAME = "colorCodes.txt";
    ifstream inputFile;


    // Try opening file and output error to console if file is no good
    inputFile.open(INPUT_FILE_NAME);
    
    
    cout << endl; // Spacing
    return 0;
}

