/* Program name: pdurfey_M04_a1.cpp
*  Author: Peter Durfey
*  Date last updated: 9/16/2022
* Purpose:  develop a class for nerf guns
*/

#include <iostream>
#include <vector>
#include <time.h>
#include <time.h>
using namespace std;
void validate();

class nerfGun
{
    string model;
    int range, capacity, dart_num;
public:
    nerfGun(string model, int range, int capacity)
    {
        this->model= model;
        this->range = range;
        this->capacity = capacity;
        this->dart_num = capacity;
    }
    string getModel()
    {
        return this->model;
    }
    int getCapacity()
    {
        return this->capacity;
    }
    int getDartCount()
    {
        return this->dart_num;
    }
    int getRange()
    {
        return this->range;
    }
    void fire()
    {
        this->dart_num--;
    }
    void reload(int quantity)
    {
        this->dart_num =+ quantity;
    }
    bool operator == (nerfGun nf)
    {
        if (dart_num == nf.dart_num)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    bool operator > (nerfGun nf)
    {
        if (dart_num > nf.dart_num)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    nerfGun& operator--()
    {
        dart_num--;
        return *this;
    }
    nerfGun operator--(int)
    {
        nerfGun temp = *this;
        --*this;
        return temp;
    }
    void operator +=(int reload_amount)
    {
        dart_num += reload_amount;
    }
    friend ostream& operator<<(ostream& os, const nerfGun& ng)
    {
        os << "model: " << ng.model << ", " << "range: " <<  ng.range << ", " << "capacity: " << ng.capacity << ", " << "number of darts in gun: " << ng.dart_num << endl;
        return os;
    }

};
vector<nerfGun> nerf_list;


int main()
{
    //get number of nerf guns to be entered
    string model;
    int range, capacity, dart_num, num;
    cout << "Enter number of nerfguns to be entered: ";
    while (!(cin >> num) || num > 7)
    {
        validate();
    }
    cin.ignore();
    //cycle through nerfguns and get info
    for(int x = 0; x < num; x++)
    {
        //get model
        cout << "Enter model name: ";
        getline(cin, model);
        //get range
        cout << "enter range:";
        while (!(cin >> range))
        {
            validate();
        }
        //get capacity
        cout << "enter capacity:";
        while (!(cin >> capacity) || capacity <= 144)
        {
            validate();
        }
        //add to vector
        nerf_list.push_back (nerfGun(model, range, capacity));
        cin.ignore();
    }
    cout << "-------------------------------------------------"  << endl;
    //list all nerfguns
    cout << endl;
    cout << "List of all nerfguns: " << endl;
    for(int x = 0; x < nerf_list.size(); x++)
    {
        cout << nerf_list[x];
    }
    //nerfgun with the most ammo
    nerfGun most_ammo = nerf_list[0];
    for (int x = 1; x < num; x++)
    {
        if(nerf_list[x] > most_ammo)
        {
            most_ammo = nerf_list[x];
        }
    }
    cout << "-------------------------------------------------"  << endl;
    cout << "Gun with most ammo: " << most_ammo.getModel() << endl;
    cout << "-------------------------------------------------"  << endl;
    //randomly shoot nerfguns
    srand((unsigned) time(0));
    for (int x = 0; x < 3; x++)
    {
       int random = 0 + (rand() % num);
       cout << "Random gun shot: ";
       cout << nerf_list[random].getModel() << ", Ammo count: " << nerf_list[random].getDartCount() << endl;
       --nerf_list[random];
       cout << "After shot ammo count: " << nerf_list[random].getDartCount() << endl;
    }
    //randomly reload gun
    cout << "-------------------------------------------------"  << endl;
    for (int x = 0; x < 3; x++)
    {
       int random = 0 + (rand() % num);
       cout << "Random gun reloaded: ";
       cout << nerf_list[random].getModel() << ", Ammo count: " << nerf_list[random].getDartCount() << endl;
       nerf_list[random] += (random + 1);
       cout << "Reload amount: " << random + 1 << endl;
       cout << "After reload: ";
       cout << nerf_list[random].getModel() << ", Ammo count: " << nerf_list[random].getDartCount() << endl;
    }
}
//void function
void validate()
{
    cout << "Invalid input\n";
    cin.clear();
    cin.ignore(256, '\n');
    cout << "Re-Enter: ";
}