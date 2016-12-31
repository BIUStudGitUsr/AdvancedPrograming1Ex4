/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#ifndef _H_GURD_FUNCTIONS
#define _H_GURD_FUNCTIONS

#include <list>
using namespace std;


template<class Obj>
list<Obj>& operator<<(list<Obj>& lis, const Obj& o)
{
    lis.push_back(o);
    return lis;
}

template<class Obj>
list<Obj>& operator>>(list<Obj>& lis, Obj& o)
{
    o = lis.back();
    lis.pop_back(o);
    return lis;
}


template<class Obj>
bool operator==(const list<Obj>& lis1, const list<Obj>& lis2)
{
    typename list<Obj>::iterator it = lis1.begin();
    typename list<Obj>::iterator jt = lis2.begin();
    for(; it != lis1.end() && jt != lis2.end(); it++, jt++)
    {
        if (*it != *jt)
            return false;
    }
    return (it == lis1.end() && jt == lis2.end());
}





#endif /* _H_GURD_FUNCTIONS */
