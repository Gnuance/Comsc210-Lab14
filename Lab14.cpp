// Lab 14: Creates multiple color objects consisting of RGB values and outputs those object values to console.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector> // For vector instead of array
#include <string>
#include <random>

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
    int getR() const;
    int getG() const;
    int getB() const;
    Color getRandomColor(); // Returns color object with random RGB
    string toString() const; // print() method but returns a string
    ~Color();
};

int main()
{
    // Initialize variables
    const unsigned int COLORS_SIZE = 20;
    Color colors[COLORS_SIZE] = {};

    for (size_t i = 0; i < COLORS_SIZE; i++)
    {
        colors[i] = Color();
        cout << colors[i].toString() << endl;
    }      

    cout << endl; // Spacing
    return 0;
}

// COLOR CLASS
// Default constructor
Color::Color()
    : r(0), g(0), b(0) // Initialized default if none specified
{
}

// Overloaded constructor
Color::Color(int red, int green, int blue)
// Initialized default if none specified
{
    setR(red);
    setG(green);
    setB(blue);
}

void Color::setR(int Red)
{
    if (Red >= 0 && Red <= 255)
    {
        r = Red;
    }
    else
    {
        throw invalid_argument("Red value must be between 0 and 255.");
    }
}
void Color::setG(int Green)
{
    if (Green >= 0 && Green <= 255)
    {
        g = Green;
    }
    else
    {
        throw invalid_argument("Green value must be between 0 and 255.");
    }
}
void Color::setB(int Blue)
{
    if (Blue >= 0 && Blue <= 255)
    {
        b = Blue;
    }
    else
    {
        throw invalid_argument("Blue value must be between 0 and 255.");
    }
}
void Color::setColor(int Red, int Green, int Blue)
{
    setR(Red);
    setG(Green);
    setB(Blue);
}
int Color::getR() const
{
    return r;
}
int Color::getG() const
{
    return g;
}
int Color::getB() const
{
    return b;
}

// Randomize color
Color Color::getRandomColor(){
    // Random number generator to create RGB
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 255);  // For creating colors
    return Color(dist(gen), dist(gen), dist(gen));
}

// Standard toString function for class
string Color::toString() const
{
    stringstream oss;
    oss << "r: " << r << " g: " << g << " b: " << b;
    string output = oss.str();
    return output;
}

// Overriden operator<<
ostream &operator<<(ostream &os, const Color &c)
{
    os << c.toString();
    return os;
}

Color::~Color()
{
}
