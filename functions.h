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


bool ifContaining(string str1,string str2) ;

char* itos(int i, char* b)
{
    char const digit[] = "0123456789";
    char* p = b;
    if(i<0)
    {
        *p++ = '-';
        i *= -1;
    }
    int shifter = i;
    do
    { //Move to where representation ends
        p++;
        shifter = shifter/10;
    } while(shifter);
    *p = '\0';
    do
    { //Move back, inserting digits as u go
        *(p--) = digit[i % 10];
        i = i/10;
    } while(i);
    return b;
}

#define in *
template<class Obj>
bool operator* (Obj o,list<Obj> lis)
{
	for(typename list<Obj>::iterator it=lis.begin(); it!=lis.end();++it)
	{
		if(o == *it)
			return true;
	}
	return false;
}
#endif /* _H_GURD_FUNCTIONS */
