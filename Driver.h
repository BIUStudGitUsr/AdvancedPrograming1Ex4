/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/


#ifndef _H_GURD_DRIVER
#define _H_GURD_DRIVER

#include "Point.h"
#include <string>
#include "Cab.h"
#include "Trip.h"

using namespace std;

class Driver 
{

public:
	
	typedef enum MartialStatus {SINGLE,MARRIED,DIVORCED,WIDOWED} MartialStatus;

private:
	
	unsigned int m_id;
	
	unsigned int m_age;
	
	unsigned int m_exp;
	
	double m_satisfaction;
	
	MartialStatus m_status;
	
	Point m_location;

	Cab* m_cab;

public:

	unsigned int GetAge() const { return m_age; }

	unsigned int GetExp() const { return m_exp; }

	unsigned int GetID() const { return m_id; }

	double GetSatisfacation() const { return m_satisfaction; }

	MartialStatus GetStatus() const { return m_status; }

	Point GetLocation() const { return m_location; }
	
	void PrintLocation() const {cout<< GetLocation();}
	
	void SetID(unsigned int ui)  { m_id = ui; }

	void SetAge(unsigned int ui) { m_age = ui; }

	void SetExp(unsigned int ui) { m_exp = ui; }

	void SetCab(Cab* cab) {m_cab = cab;}

	void SetSatisfacation(double d) { m_satisfaction = d; }

	void SetStatus(MartialStatus ms) { m_status = ms; }

	void SetLocation(Point p) { m_location.x = p.x; m_location.y = p.y; }
	
	Driver();
 
	Driver(const Point& p);
 
	~Driver();
};

#endif /* _H_GURD_DRIVER */
