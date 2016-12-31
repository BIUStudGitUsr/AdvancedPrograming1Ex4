/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_STATISTICCENTER
#define _H_GURD_STATISTICCENTER
#include "Point.h"
#include "Driver.h"

/**********************************************

* Class Name: Point

* Class Aim: a saving place that contains the data
	of all the things in the system

***********************************************/
class StatisticCenter
{
public:

    static Point LocationOfDriver(const Driver* d);

};


#endif /* _H_GURD_STATISTICCENTER */
