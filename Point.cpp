/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "Point.h"
bool ifContaining(string str1,string str2);

/******************************************

* function goal: keep the point as string to pass 
	by socket later

* Operator Arguments: none

* Operator Output: The string that descrribes this point

* Operator Aim: keep the point as string to pass 
	bye socket later

***********************************************/
std::string Point::toString()
{
		std::string output = "Point:\n";
		output += "x:";
		output += std::to_string(x);
		output += "y:";
		output += std::to_string(y);
}
/********************
	constructor that receives a string created with 
	toString of another Point.
**********************/
Point::Point(std::string str)
{
	if(!ifContaining("Point:\n",str))
	{
        throw string("N");
	}
	if(ifContaining("x:",str))
	{
		x=stoi(str);
		ifContaining(to_string(x),str);
	}
	if(ifContaining("y:",str))
	{
		y=stoi(str);
		ifContaining(to_string(y),str);
	}
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
