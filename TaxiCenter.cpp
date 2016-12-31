/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "TaxiCenter.h"


list<Driver*> TaxiCenter::m_drivers(1, NULL);
list<Trip*> TaxiCenter::m_trips(1, NULL);
list<Cab*> TaxiCenter::m_cabs(1, NULL);	

void* TaxiCenter::AnswerCall()
{
    return NULL;
}

const Driver* TaxiCenter::GetDriver(unsigned int id)
{
    list<Driver*>::iterator it = GetDrivers().begin();
    for (it++; it != GetDrivers().end(); it++)
    {
        if ((*it)->GetID() == id)
        {
            return (*it);
        }
    }
    return NULL;
}
