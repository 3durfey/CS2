/* Program name: peter_durfey_m01project2.cpp
 *  Author: Peter Durfey
 *  Date last updated: 8/27/2022
 * Purpose: create steroreceiver
 */

#include <iostream>
#include <string>
#include <limits>
using namespace std;
//create validator function for info
void validate();

//error messages
string invalidSerialNumber = "serial number";
string invalidWattage = "wattage, must be between 0 and 3000.";
string invalidChannels = "number of channels, must be between 0 and 300";
string invalidBand ="band. Must be 6 through 9.";
string invalidVolume = "volume. Must be between 1 and 10.";
string invalidFrequency = "frequency, must be between 1 and 3000.";
string invalidPower = "Must be either ON or OFF.";

//make class for stereo receiver and array for manufacterer
class StereoReceiver
{
    //declare variables

    string manufacturer, model, color, power;
    int serial_number = -1, band, channels, volume, year;
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


int setBand(int b)
{    
    band = b;
    try
    {
        if (band < 6 || band > 9)
        {
            throw invalid_argument(invalidBand);
        }
    }
    catch (invalid_argument msg)
    {
        cout << "Invalid " << msg.what() << endl;
        return 1;
    }
    return 0;
}

int setVolume(int v)
{
    volume = v;
    try
    {
        if (volume < 0 || volume > 10)
        {
            throw (invalidVolume);
        }
    }
    catch (string v)
    {
        cout << "Invalid " << invalidVolume << endl;
        return 1;
    }
    return 0;
}
void setPower(string p)
{
    power = p;
    try 
    {
        if (power == "ON" || power == "OFF")
        {
            ;
        }
        else
        {
            throw(invalidPower);
        }
    }
    catch (string p)
    {
        cout << "Invalid " << p << endl;
    }
}
int setFrequency(double f)
{
    frequency = f;
    try
    {
        if (frequency < 1 || frequency > 3000)
        {
            throw (invalidFrequency);
        }
    }
    catch (string f)
    {
        cout << "Invalid " << invalidFrequency << endl;
        return 1;
    }
    return 0;
}
};

//main program
int main()
{   //declare variables
    string manufacturer, model, color, power;
    int serial_number, channels, band, volume, year;
    double frequency, wattage; 
    //set intitial valuesw
    power = "OFF";
    band = 1;
    volume = 5;
    color = "black";
    
    //get info
    getyear:
    cout<< "Enter Year of production: ";
    while(!(cin >> year))
    {
        validate();
    }
    try
    {
        if (year > 2022 || year < 1700)
        throw (year);
    }
    catch (int y)
    {
        cout << "Invalid year. Must be between 2022 and 1700" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto getyear;
    }

    getmanufacturer:
    cout<<"Enter Manufacturer: ";
    cin >> manufacturer;
    try 
    {
        if (manufacturer.empty())
            {
                throw (manufacturer);
            }
    }
    catch (string m)
        {
            cout << "Invalid " << m << endl;
            goto getmanufacturer;
        }
    
    getmodel:
    cout<<"Enter Model: ";
    cin >> model;
    try
    {
        if (model.empty())
            {
                throw (model);
            }
    }
    catch (string m)
        {
            cout << "Invalid " << m << endl;
            goto getmodel;
        }

    getnumber:
    cout<<"Enter Serial Number: ";
    try 
    {
        if (!(cin >> serial_number))
            {
                throw (invalidSerialNumber);
            }
    }
    catch (string m)
        {
            cout << "Invalid " << m << endl;
            cin.clear();
            cin.ignore(256, '\n');
            goto getnumber;
        }

    getwattage:
    cout<<"Enter Wattage: ";
    try
    {
        if (!(cin >> wattage) || wattage > 3000 || wattage < 0)
            {
                throw (invalidWattage);
            }
    }
    catch (string m)
        {
            cout << "Invalid " << m << endl;
            cin.clear();
            cin.ignore(256, '\n');
            goto getwattage;
        }
    getchannels:
    cout<<"Enter Number of Channels: ";
    try
    {
     if (!(cin >> channels) || channels > 300 || channels < 0)
        {
            throw (invalidChannels);
        }
    }
    catch (string m)
        {
            cout << "Invalid " << m << endl;
            cin.clear();
            cin.ignore(256, '\n');
            goto getchannels;
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
    //turn radio on
    stereo.setPower("ON");
    //get info, change it using mutators

    int valid = 0;

    do 
    {
    valid = 0;
    cout<< endl <<"Enter Desired Station: ";
    while(!(cin >> frequency))
    {
        validate();
    }
    valid = stereo.setFrequency(frequency);
    } while (valid == 1);

    do
    {
    valid = 0;
    cout<<"Enter Desired Band: ";
    while(!(cin >> band))
    {
        validate();
    }
    valid = stereo.setBand(band);
    }while (valid == 1);

    do
    {
    valid = 0;
    cout<<"Enter Desired Volume: ";
    while(!(cin >> volume))
    {
        validate();
    }
    valid = stereo.setVolume(volume);
    } while (valid == 1);
    // display info

    cout << endl << "Power Status: " << stereo.getPower() << endl <<
    "Band: " << stereo.getBand() << endl << 
    "Currenty Frequency: " << stereo.getFrequency() << endl <<
    "Volume Level: " << stereo.getVolume() << endl;
    //turn radio off
    stereo.setPower("OFF");
}

void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}