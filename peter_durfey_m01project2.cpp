/* Program name: peter_durfey_m01project2.cpp
 *  Author: Peter Durfey
 *  Date last updated: 8/27/2022
 * Purpose: create steroreceiver
 */

#include <iostream>
using namespace std;
//create validator function for info
void validate();
//make class for stereo receiver
class StereoReceiver
{
    //declare variables

    string manufacturer, model, color, power;
    int serial_number, band, channels, volume, year;
    double frequency, wattage;

//create constructor
public:
    StereoReceiver(string manufact, int b, string m, int sn, double w, int c, string col, int v, int y, double f, string p)
    {
        manufacturer = manufact;
        model = m;
        serial_number = sn;
        wattage = w;
        channels = c;
        band = b;
        color = col;
        volume = v;
        year = y;
        frequency = f;
        power = p;
        
    }
//accessor methods
double getFrequency()
{
    return frequency;
}
int getYear()
{
    return year;
}
string getManufacturer()
{
    return manufacturer;
}
string getColor()
{
    return color;
}
string getModel()
{
    return model;
}
string getPower()
{
    return power;
}
int getSerialNumber()
{
    return serial_number;
}
int getVolume()
{
    return volume;
}
double getWattage()
{
    return wattage;
}
int getChannels()
{
    return channels;
}
int getBand()
{
    return band;
}

void setBand(int b)
{
    band = b;
}

void setVolume(int v)
{
    volume = v;
}
void setPower(string p)
{
    power = p;
}
void setYear(int y)
{
    year = y;
}
void setFrequency(double f)
{
    frequency = f;
}
};

//main program
int main()
{
    string manufacturer, model, color, power;
    int serial_number, channels, band, volume, year;
    double frequency, wattage; 

    power = "OFF";
    band = 1;
    volume = 5;
    color = "black";
    year = 1956;

    cout<< endl <<"Enter Year of production: ";
    while(!(cin >> year) || year > 2023 || year < 1700)
    {
        validate();
    }

    cout<<"Enter Manufacturer: ";
    while(!(cin >> manufacturer))
    {
        validate();
    }

    cout<<"Enter Model: ";
    while(!(cin >> model))
    {
        validate();
    }

    cout<<"Enter Serial Number: ";
    while(!(cin >> serial_number))
    {
        validate();
    }

    cout<<"Enter Wattage: ";
    while(!(cin >> wattage))
    {
        validate();
    }

    cout<<"Enter Number of Channels: ";
    while(!(cin >> channels))
    {
        validate();
    }


    //create object for receiver
    StereoReceiver stereo(manufacturer, band, model, serial_number, wattage, channels, color, volume, year, frequency, power);

    //output using accessor methods
    cout << endl << "Manufacturer: " << stereo.getManufacturer() << endl <<
    "Model: " << stereo.getModel() << endl <<
    "Color: " << stereo.getColor() << endl <<
    "Model Year: " << stereo.getYear() << endl <<
    "Serial Number: " << stereo.getSerialNumber() << endl <<
    "Wattage: " << stereo.getWattage() << endl <<
    "Number of Channels: " << stereo.getChannels() << endl;
    
    power = "ON";
    stereo.setPower(power);

    cout<< endl <<"Enter Desired Station: ";
    while(!(cin >> frequency) || frequency > 2000)
    {
        validate();
    }
    stereo.setFrequency(frequency);

    cout<<"Enter Desired Band: ";
    while(!(cin >> band) || band < 0 || band > 3000)
    {
        validate();
    }
    stereo.setBand(band);

    cout<<"Enter Desired Volume: ";
    while(!(cin >> volume) || volume < 0 || volume > 10)
    {
        validate();
    }
    stereo.setVolume(volume);

    cout << endl << "Power Status: " << stereo.getPower() << endl <<
    "Band: " << stereo.getBand() << endl << 
    "Currenty Frequency: " << stereo.getFrequency() << endl <<
    "Volume Level: " << stereo.getVolume() << endl;

    power = "OFF";
    stereo.setPower(power);
}

//validate function
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}