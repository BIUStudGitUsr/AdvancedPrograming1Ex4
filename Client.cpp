/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include <iostream>
#include "Point.h"
#include "Driver.h"
#include "Client.h"
#include "SocketClient.h"
#include "functions.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "invalid input!" << endl;
        return -1;
    }
    SocketClient sc = SocketClient(string(argv[1]), stoi(argv[2]));
    Driver* d = CreatDriver();
    bool quit = false;
    Send(itos(f->GetID());
    Cab* c = new Cab(Recive());
    Send(string("Trip"));
    while (!quit)
    {
        string str = Recive();
        try
        {
            Trip* t = new Trip(str);
            bool tripFinished = false;
            while (!tripFinished)
            {
                Send(string("Advance"));
                Point move = Recive();
                
            }
            Send(string("Quit"));
            quit = Recive();
        }
        catch (...)
        {
            try 
            {
                if (str == "Location")
                {
                    Send(d.GetLocation().toString())
                }
            }
            catch (...)
            {
                
            }
        }
        
    }
    delete c;
    return 0;
}

/*****************************************************************

*    Function Name: CreatDriver

*    Function Arguments: void

*    Function Output: void

*    Function Operation: Receives input from the user about
        a certain driver, creat this driver

*********************************************************************/
Driver* CreatDriver()
{
    unsigned int id;
    unsigned int age;
    char status;
    Driver::MartialStatus driversStatus;
    unsigned int experience;
    unsigned int vehicleId;
    Driver* newDriver = new Driver();
    char temp; // the temp will take the comma each time
    bool toContinue = true;
    
    cin >> id >>  temp;
    cin >> age >>  temp;
    cin >> status >>  temp;
    cin >> experience >>  temp;
    cin >> vehicleId;
    
    switch(status)
    {
    case 'S': 
        driversStatus = Driver::SINGLE;
        break;
    case 'M':
        driversStatus = Driver::MARRIED;
        break;
    case 'D':
        driversStatus = Driver::DIVORCED;
        break;
    case 'W':
        driversStatus = Driver::WIDOWED;
        break;
    default: 
        cout << "bad input new driver" << endl;
        break;
    }
    
    newDriver->SetID(id);
    newDriver->SetAge(age);
    newDriver->SetStatus(driversStatus);
    newDriver->SetExp(experience);
    newDriver->SetCab(cab);
    
    return newDriver;
}
