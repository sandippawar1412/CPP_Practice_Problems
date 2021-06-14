/*
enum:
scoped
conflicts multiple declaration, use scoped enums
*/

#include <iostream>
using namespace std;

#define SCOPED_ENUM
#ifndef SCOPED_ENUM
enum Color
{
    RED,
    GREEN,
    BLUE
};

enum TrafficLights
{
    //RED, Error Multiple declaraion    
    YELLOW

};
#else 
enum class  Color
{
    RED,
    GREEN,
    BLUE
};

enum class TrafficLights: char
{
    RED = 'r', 
    YELLOW,
    GREEN

};

#endif

enum RGB{
    RED,
    GREEN,
    BLUE
};

int main()
{ 
    Color c;//gargbage
    c = Color::RED;
    int x = static_cast<int>(c);    
    cout << "color No:" << x << endl;

    //c = 2;  // Not allowed conversion
    c = static_cast<Color> (2);
    cout << "color:" << static_cast<int>(c) << endl;

    TrafficLights tl = TrafficLights::YELLOW;
    cout << "Traffic light: " << static_cast<char>(tl)<<endl;

    RGB rgb = GREEN;
    //int x = c; //Doesn't work, needs static cast
    int y = rgb;
        
}