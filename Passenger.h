/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_PASSENGER
#define _H_GURD_PASSENGER
#include "Point.h"
/**********************************************

* Class Name: Passenger

* Class Aim: saves all we need to know about a certain 
	passenger.

***********************************************/
class Passenger 
{
private:
    
	Point m_source;

	Point m_destination;

public:

	Point GetSource() const { return m_source; }

	Point GetDestination() const { return m_destination; }

	void SetSource(Point p) { m_source = p; }

	void SetDestination(Point p) { m_destination = p; }

	double MySatisfaction();

	Passenger();

	virtual ~Passenger();

};

#endif /* _H_GURD_PASSENGER */
