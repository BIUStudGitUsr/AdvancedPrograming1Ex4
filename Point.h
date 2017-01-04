/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_POINT
#define _H_GURD_POINT

#include <iostream>
#include <string>
using namespace std;

/**********************************************

* Class Name: Point

* Class Aim: To be able to use Points from Z x Z
    easily

***********************************************/
class Point
{
public:

	int x;

	int y;

	bool operator==(const Point& p) const { return p.x==this->x && p.y==this->y; } 
	
	Point() : x(0), y(0) {}

	Point(int x, int y) : x(x), y(y) {}

	Point(const Point& p) : x(p.x), y(p.y) {}
	
	Point(std::string str);
	
	~Point() {}
	
	std::string toString();
	
};

const Point& operator+(const Point& p, const Point& q);
std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);


#endif /* _H_GURD_POINT */
