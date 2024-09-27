// Program reads 30 ints from a file ranging from 0-255 representing 8-bit color codes, stores those codes in a VECTOR,
//  and exercises various std::VECTOR methods and outputs colors to console

#include <iostream>
#include <fstream>
#include <iomanip>
// #include <array>
#include <vector> // For vector instead of array
#include <string>
#include <algorithm> // sort(), find()
#include <numeric>   // accumulate()

using namespace std;

bool IsInt(const string &str);      // Checks if string is an integer
void SetForegroundColor(int color); // Changes cout letter color
void SetBackgroundColor(int color); // Changes cout background color
void ResetColor();                  // Resets console output color

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
    if (inputFile)
    {
        // File is good, begin checking data and add to array if int 0-255
        while (getline(inputFile, fileLine))
        {
            if (stoi(fileLine) >= 0 && stoi(fileLine) <= 255)
            {
                colorCodes.push_back(stoi(fileLine));
                index++;
            }
        }
        // CLOSE THE F-ING FILE
        inputFile.close();

        // Now we have color codes in the array, let's play with array methods and output some colors to console :-D
        // Output all colors numbers to screen with colored font
        cout << "Color Codes:" << endl;
        index = 0;
        for (auto it = colorCodes.begin(); it != colorCodes.end(); ++it)
        {
            cout << *it << " ";
            index++;
            if (index % 10 == 0)
                cout << endl; // Add line spacing
        }

        cout << "\nColored Color Codes:" << endl;
        index = 0;
        for (auto it = colorCodes.begin(); it != colorCodes.end(); ++it)
        {
            SetForegroundColor(*it);
            cout << *it << " ";
            index++;
            if (index % 10 == 0)
                cout << endl; // Add line spacing
        }
        ResetColor();

        cout << "\nReverse Iterated Color Background Color Codes:" << endl;
        index = 0;
        for (auto it = colorCodes.rbegin(); it != colorCodes.rend(); ++it)
        {
            SetBackgroundColor(*it);
            cout << *it << " ";
            index++;
            ResetColor();
            if (index % 10 == 0)
                cout << endl; // Add line spacing
        }

        // Output front, back min, max and average
        cout << "\nFront Color: ";
        SetBackgroundColor(colorCodes.front());
        cout << COLOR_BAR;
        ResetColor();
        cout << endl
             << endl;

        cout << "Back Color: ";
        SetBackgroundColor(colorCodes.back());
        cout << COLOR_BAR;
        ResetColor();
        cout << endl
             << endl;

        cout << "Min Color: ";
        SetBackgroundColor(*min_element(colorCodes.begin(), colorCodes.end()));
        cout << COLOR_BAR;
        ResetColor();
        cout << endl
             << endl;

        cout << "Max Color: ";
        SetBackgroundColor(*max_element(colorCodes.begin(), colorCodes.end()));
        cout << COLOR_BAR;
        ResetColor();
        cout << endl
             << endl;

        cout << "Ave Color (accumulate / array size): ";
        SetBackgroundColor(int(accumulate(colorCodes.begin(), colorCodes.end(), 0) / colorCodes.size()));
        cout << accumulate(colorCodes.begin(), colorCodes.end(), 0) / colorCodes.size() << "     ";
        ResetColor();
        cout << endl
             << endl;

        // Sort codes and print list
        sort(colorCodes.begin(), colorCodes.end());
        cout << "Colored Color Codes After Sorting:" << endl;
        index = 0;
        for (auto it = colorCodes.begin(); it != colorCodes.end(); ++it)
        {
            SetForegroundColor(*it);
            cout << *it << " ";
            index++;
            if (index % 10 == 0)
                cout << endl; // Add line spacing
        }
        ResetColor();

        // Print color at index 17
        cout << "\nColor Code At Index 17: ";
        SetBackgroundColor(colorCodes.at(17));
        cout << colorCodes.at(17) << " ";
        ResetColor();
        cout << endl
             << endl;

        // Sum of all color codes
        cout << "Sum of color codes: " << accumulate(colorCodes.begin(), colorCodes.end(), 0) << endl
             << endl;

        // Find target color code
        cout << "Find position of target 209: ";
        it = find(colorCodes.begin(), colorCodes.end(), 209);
        // If iterator is passed end, color not found
        if (it > colorCodes.end())
        {
            cout << "Color not found." << endl;
        }
        else
        {
            cout << "Color found in index: " << it - colorCodes.begin() << endl;
        }
    }
    else // Output error if file no good
    {
        cerr << "Error opening file! Better luck next time..." << endl;
    }
    cout << endl; // Spacing
    return 0;
}

// Check if input is an integer
bool IsInt(const string &str)
{
    for (char c : str)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }
    return true;
}

// Changes cout letter color
void SetForegroundColor(int color)
{
    cout << "\033[38;5;" << color << "m";
}

// Changes cout background color
void SetBackgroundColor(int color)
{
    cout << "\033[48;5;" << color << "m";
}

// Resets console output color
void ResetColor()
{
    cout << "\033[0m";
}