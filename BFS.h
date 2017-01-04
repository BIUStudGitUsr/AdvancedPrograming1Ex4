/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_BFS
#define _H_GURD_BFS


#include <list>
#include <vector>
#include "Point.h"
#include "functions.h"
using namespace std;

/**********************************************

* Class Name: BFS

* Class Aim: To be able to use BFS algorithem
	wisely and generaclly.

***********************************************/
class BFS
{
private:

	typedef enum { O = 0, W, N, E, S, X } Dir;


	BFS() {}
	vector<vector<Dir>* >* m_board;
	list<Point> obsticles;
public:

	BFS(const Point& start, const Point& dest, int xsize, int ysize, list<Point>* ret);

	bool IsOk(const Point& p);

};

#endif /* _H_GURD_BFS */
