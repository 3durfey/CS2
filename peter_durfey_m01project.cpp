/* Program name: peter_durfey_m01project.cpp
*  Author: Peter Durfey
*  Date last updated: 8/25/2022
* Purpose: basic function
*/

#include <iostream>
using namespace std;

class Cube 
{
//initilize variables
    int length, width, height;
    string color;
    public:
    Cube(int x, int y, int q, string f) 
    {
        length = x;
        width = y;
        height = q;
        color = f;
    }
    //accessors
    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    string getColor()
    {
        return color;
    }
    //mutators
    void setLength(int l)
    {
        length = l; 
    }
    void setWidth(int l)
    {
        width = l; 
    }
    void setHeight(int h)
    {
        height = h;
    }
    void setColor(string c)
    {
        color = c;
    }
    //volume= length*height
    int calculateVolume(int l, int h, int c)
    {
        return (l * h * c);
    }

};

int main() 
{
    //get variables and validate
    double length, width, height;
    string color;
    cout<<"Enter cube length: ";
    while(!(cin >> length))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter length: ";
    }
    cout<<"Enter cube width: ";
    while(!(cin >> width))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter width: ";
    }
    cout<<"Enter cube height: ";
    while(!(cin >> height))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter height: ";
    }

    cout<<"Enter cube color: ";
    cin >> color;
    //create cube object
    Cube myCube(length, width, height, color);
    //output results
    cout << "length: " << myCube.getLength() << endl <<
    "Width: " << myCube.getWidth() << endl <<
    "Height: " << myCube.getHeight() << endl <<
    "Color: " << myCube.getColor() << endl <<
    "Volume: " << myCube.calculateVolume(height, width, length) << endl;
    //update variables
    cout<<"Update cube length: ";
    while(!(cin >> length))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter length: ";
    }
    myCube.setLength(length);

    cout<<"Update cube width: ";
    while(!(cin >> width))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter width: ";
    }
    myCube.setWidth(length);

    cout<<"Update cube height: ";
    while(!(cin >> height))
    {
        cout << "Invalid input\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Re-Enter height: ";
    }
    myCube.setHeight(height);

    cout<<"Update cube color: ";
    cin >> color;
    myCube.setColor(color);

    //output updated variables
    cout << "Updated length: " << myCube.getLength() << endl <<
    "Updated Width: " << myCube.getWidth() << endl <<
    "Updated Height: " << myCube.getHeight() << endl <<
    "Updated Color: " << myCube.getColor() << endl <<
    "Updated volume: " << myCube.calculateVolume(height, width, length) << endl;

    return 0;
}



