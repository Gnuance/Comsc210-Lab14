// Lab 14: Creates multiple color objects consisting of RGB values and outputs those object values to console.

#include <iostream>
#include <iomanip>
#include <vector> // For vector instead of array
#include <string>

using namespace std;

// Declare color class to store RGB values
class Color
{
private:
    int r;
    int g;
    int b;
public:
    Color();
    Color(int, int, int);
    void setR(int);
    void setG(int);
    void setB(int);
    void setColor(int, int, int);
    ~Color();
};

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

Color::Color(/* args */)
: r(0), g(0), b(0) // Initialized default if none specified
{
}

Color::Color(int red, int green, int blue)
: r(red), g(green), b(blue) // Initialized default if none specified
{
}

void Color::setR(int Red){
    if (Red >= 0 && Red <= 255)
    {
        r = Red;
    } else {
        throw invalid_argument("Red value must be between 0 and 255.");
    }
}
void Color::setG(int Green){
    if (Green >= 0 && Green <= 255)
    {
        g = Green;
    } else {
        throw invalid_argument("Green value must be between 0 and 255.");
    }
}
void Color::setB(int Blue){
    if (Blue >= 0 && Blue <= 255)
    {
        b = Blue;
    } else {
        throw invalid_argument("Blue value must be between 0 and 255.");
    }
}
void Color::setColor(int Red, int Green, int Blue){
    setR(Red);
    setG(Green);
    setB(Blue);
}

Color::~Color()
{
}
