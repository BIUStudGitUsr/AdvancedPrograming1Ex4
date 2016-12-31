/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "Driver.h"
Driver::Driver() 
{
	Point *p = new Point(0,0);
	m_location = *p;
	m_id = -1;
}

Driver::Driver(const Point& p)
{
	m_location = p;
}

Driver::~Driver() 
{

}

