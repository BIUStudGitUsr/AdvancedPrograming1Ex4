/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "Point.h"

/**********************************************

* Operator Type: +

* Operator Arguments: Two points

* Operator Output: The sum of the points

* Operator Aim: Sum points

***********************************************/
const Point& operator+(const Point& p, const Point& q)
{
	return Point(p.x + q.x, p.y + q.y);
}



/**********************************************

* Operator Type: <<

* Operator Arguments: ostream (a specific output
    manager) and a point

* Operator Output: The ostream

* Operator Aim: To be able to output points

***********************************************/
std::ostream& operator<<(std::ostream& os, const Point& p)
{
	return os << "(" << p.x << "," << p.y << ")";
}






/**********************************************

* Operator Type: >>

* Operator Arguments: istream (a specific input
                     manager) and a point

* Operator Output: The istream

* Operator Aim: To be able to input points

***********************************************/
std::istream& operator>>(std::istream& is, Point& p)
{
	return (is >> p.x >> p.y);
}
