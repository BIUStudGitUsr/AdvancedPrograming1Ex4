/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include <list>
#include <vector>
#include "Point.h"
#include "BFS.h"
using namespace std;


/**********************************************

* Macro Name: CHECK_NEIGBOURS

* Macro Arguments: Node point in grid

* Macro Output: -

* Macro Aim: To check if the node is visited
	and if not go there

***********************************************/
#define CHECK_NEIGBOURS(X, Y) \
if (IsOk(Point((X), (Y)))) \
{ \
	if (!((*((*m_board)[(X)]))[(Y)])) \
	{ \
		queue.push_front(Point((X), (Y))); \
		(*(*m_board)[(X)])[(Y)] = curDir; \
	} \
} \
curDir = (Dir)(curDir + 1);



/**********************************************

* Function Name: IsOk

* Function Arguments: A point

* Function Output: Whether or not it is possible
	to move to specified point

* Function Aim: To be able to tell easily if target
	point is accacable or not

***********************************************/
bool BFS::IsOk(const Point& p)
{
	if(p in obsticles)
		return false;	
	return p.x >= 0 && p.y >= 0 && p.x < m_board->size() && p.y < ((*m_board)[0])->size();
}




/**********************************************

* Function Name: BFS (C'tor)

* Function Arguments: Starting point, ending point,
	size of board and a pointer to a list as a
	return value

* Function Output: Return value is detected by the
    pointer to a list, this list is a list of point
    that represents a path from the starting point
    to the destenation point

* Function Aim: To be able to find legal pathes in
    the grid world using BFS algorithem

***********************************************/
BFS::BFS(const Point& start, const Point& dest, int xsize, int ysize, list<Point>* ret)
{
	m_board = new vector<vector<Dir>* >(xsize);
	for (int i = 0; i < xsize; i++)
	{
		(*m_board)[i] = new vector<Dir>(ysize);
	}
	for (int i = 0; i < xsize; i++)
	{
		for (int j = 0; j < ysize; j++)
		{
			(*(*m_board)[i])[j] = O;
		}
	}
	list<Point> path(0);
	list<Point> queue(0);
	queue.push_front(start);
	(*(*m_board)[start.x])[start.y] = X;
	while (queue.size() != 0)
	{
		Point here = queue.back();
		queue.pop_back();
		if (here.x == dest.x && here.y == dest.y)
			break;
		Dir curDir = W;
		CHECK_NEIGBOURS(here.x - 1, here.y)
		CHECK_NEIGBOURS(here.x, here.y + 1)
		CHECK_NEIGBOURS(here.x + 1, here.y)
		CHECK_NEIGBOURS(here.x, here.y - 1)
	}

	Point p = Point(dest);
	bool quit = false;
	while (!quit)
	{
		path.push_back(p);
		switch ((*(*m_board)[p.x])[p.y])
		{
		case W:
			p = Point(p.x + 1, p.y);
			break;
		case N:
			p = Point(p.x, p.y - 1);
			break;
		case E:
			p = Point(p.x - 1, p.y);
			break;
		case S:
			p = Point(p.x, p.y + 1);
			break;
		case X:
			quit = true;
			break;
		default:
			break;
		}
	}

	*ret = path;

}

