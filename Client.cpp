/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "Driver.h"
#include "Client.h"

int main()
{
    Driver* d = CreatDriver();
    bool quit = false;
    Send(f->GetID());
    Cab* c = Recive();
    Send("Trip");
    while (!quit)
    {
        Trip* t = Recive();
        bool tripFinished;
        while (!tripFinished)
        {
            Send("Advance");
            tripFinished = Recive();
        }
        Send("Quit");
        quit = Recive();
    }
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
