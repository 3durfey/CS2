/* Program name: pdurfey_M03_1B.cpp
*  Author: Peter Durfey
*  Date last updated: 9/01/2022
* Purpose: Create a class that can be used for a Personal Computer. 
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void validate();

string getmanufacturer();
string getFormFactor();
int getSerialNumber();
string getProcessor();
int getRAM();
string getStorageType();
string getStorageSize();

class personal_computer
{
private:
    //declare variables
    string manufacturer, form_factor, processor, storage_size, storage_type;
    int serial_number, RAM;
public:
    personal_computer(string m, string ff, string p, string ss, int sn, int r, string st)
    {
        manufacturer = m; 
        form_factor = ff;
        processor = p;
        storage_size = ss;
        serial_number = sn;
        RAM = r; 
        storage_type = st;
    }
//tostring method
string tostring()
{
    string info = manufacturer + ", " + form_factor + ", " + processor + ", " + storage_size + ", " + std::to_string(serial_number) + ", " + std::to_string(RAM) + "GB" + ", " + storage_type;
    return info;
}
//accessor methods
string getmanufacturer()
{
    return manufacturer;
}
string getform_factor()
{
    return form_factor;
}
string getprocessor()
{
    return processor;
}
string getstorage_size()
{
    return storage_size;
}
int getserial_number()
{
    return serial_number;
}
int getRAM()
{
    return RAM;
} 
string getstorage_type()
{
    return storage_type;
}
void setRAM(int r)
{
    RAM = r;
}
void setStorageSize(string r)
{
    storage_size = r;
}
};


int main()
{
//declare variables
    string manufacturer, form_factor, processor, storage_size, storage_type;
    int serial_number, RAM, pc_num;
    vector<personal_computer> pcs;
    cout << "Enter the number of personal computers: ";
    cin >> pc_num;

    for (int x = 0; x < pc_num; x++)
    {
        manufacturer = getmanufacturer();
        form_factor = getFormFactor();
        serial_number = getSerialNumber();
        processor = getProcessor();
        RAM = getRAM();
        storage_type = getStorageType();
        storage_size = getStorageSize();

        personal_computer pc(manufacturer, form_factor, processor, storage_size, serial_number, RAM, storage_type);
        pcs.push_back (pc);
        string p = pc.tostring();
        cout << p << endl;
        cout << "Number of computers on record: "<< pcs.size() << endl;
    }
    cout << "complete list of computers on record: " << endl;
    for (int x = 0; x < pc_num; x++)
    {
        cout << pcs[x].tostring() << endl;
    }
}

void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}
string getmanufacturer()
{
    string x;
    cout <<"Enter Manufacturer: ";
        while(!(cin >> x))
        {
            validate();
        }
    return x;
}
int getSerialNumber()
{
    int x;
        cout <<"Enter Serial Number: ";
        while(!(cin >>x))
        {
            validate();
        }
    return x;
}
string getProcessor()
{
    string x;
        cout <<"Enter Processor: ";
        while(!(cin >>x))
        {
            validate();
        }
    return x;
}
string getFormFactor()
{
    string x;
    string exception = "invalid form factor.";
    getformfactor:
    cout<<"Enter Form factor: ";
    try
    {
        if ((cin >> x) && x == "PC" || x == "laptop")
        {
            return x;
        }
        else 
        {
            throw(exception);
        }
    }
    catch(string r)
    {
        cout << r << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto getformfactor;
    }    
    return x;
}

int getRAM()
{
    int x;
    string exception = "RAM input invalid, must be 4, 8, 16, 32 or 64.";
    getram:
        cout <<"Enter RAM: ";
        while(!(cin >>x))
        {
            validate();
        }
    try
    {
        if (x == 4 || x == 8 || x == 16 || x == 32 || x == 64)
        {
            ;
        }
        else 
        {
            throw(exception);
        }
    }
    catch(string r)
    {
        cout << r << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto getram;
    }
    return x;
}
string getStorageType()
{      
    string a;
    string exception = "Invalid storage type, must be UFS, SDD, or HDD.";
    storagetype:
        cout <<"Enter Storage Type: ";
        while(!(cin >>a))
        {
            validate();
        }
    try
    {
        if ( a == "UFS" || a == "SDD" || a == "HDD")
        {
            ;
        }
        else 
        {
            throw(exception);
        }
    }
    catch(string r)
    {
        cout << r << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto storagetype;
    } 
    return a;
}
string getStorageSize()
{
    string a;
    string exception = "Storage Size input invalid, must be 128GB, 256GB, 512GB, 1TB or 2TB";
    getstoragesize:
        cout <<"Enter Storage Size: ";
        while(!(cin >> a))
        {
            validate();
        }
    try
    {
        if ( a == "128GB" || a == "256GB" || a == "512GB" || a == "1TB" || a == "2TB")
        {
            ;
        }
        else 
        {
            throw(exception);
        }
    }
    catch(string r)
    {
        cout << r << endl;
        cin.clear();
        cin.ignore(256, '\n');
        goto getstoragesize;
    } 
    return a;
}