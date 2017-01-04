/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_TRIP
#define _H_GURD_TRIP
#include "Driver.h"
#include "Point.h"
#include <string>
#include <iostream>
using namespace std;
/**********************************************

* Class Name: Trip

* Class Aim: easily  saves a kinda struct of all he input
	about a certain Trip.

***********************************************/
class Trip 
{
private:
    
	int m_id;

	unsigned int m_metersPassed;

	Point m_start;

	Point m_end;

	unsigned int m_passengers;

	double m_price;

public:

	int GetID() const { return m_id; }

	unsigned int GetMetersPassed() const { return m_metersPassed; }

	Point GetStart() const { return m_start; }

	Point GetEnd() const { return m_end; }

	unsigned int GetPassengers() const { return m_passengers; }

	unsigned int GetPrice() const { return m_price; }

	void SetID(int id) { m_id = id; }

	void SetMetersPassed(unsigned int ui) { m_metersPassed = ui; }

	void SetStart(Point p) { m_start = p; }

	void SetEnd(Point p) { m_end = p; }

	void SetPassangers(unsigned int ui) { m_passengers = ui; }

	void SetPrice(double ui) { m_price = ui; }

	string toString();

	Trip(string tString);

	Trip();

	virtual ~Trip();

};

#endif /* _H_GURD_TRIP */
