/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "TaxiCenter.h"


list<Driver*> TaxiCenter::m_drivers(1, new Driver());
list<Trip*> TaxiCenter::m_trips(1, new Trip());
list<Cab*> TaxiCenter::m_cabs(1, new Cab());	

void* TaxiCenter::AnswerCall()
{
    return NULL;
}

const Driver* TaxiCenter::GetDriver(unsigned int id)
{
    for (list<Driver*>::iterator it = GetDrivers().begin(); \
        it != GetDrivers().end(); it++)
    {
        if ((*it)->GetID() == id)
        {
            return (*it);
        }
    }
    return NULL;
}
