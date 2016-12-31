/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_TAXICENTER
#define _H_GURD_TAXICENTER

#include <list>
#include "Driver.h"
#include "Cab.h"
#include "Trip.h"


using namespace std;


class TaxiCenter 
{
private:

    TaxiCenter() {};
    
    ~TaxiCenter() {};

    static list<Driver*> m_drivers;

    static list<Trip*> m_trips;

    static list<Cab*> m_cabs;

public:

    static list<Driver*>& GetDrivers() { return TaxiCenter::m_drivers; }

    static list<Trip*>& GetTrips() { return TaxiCenter::m_trips; }

    static list<Cab*>& GetCabs() { return TaxiCenter::m_cabs; }

    static const Driver* GetDriver(unsigned int id);

    static void* AnswerCall();

};



#endif /* _H_GURD_TAXICENTER */
