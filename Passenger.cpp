/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/

#include "Passenger.h"
#include <cstdlib>

Passenger::Passenger()
{

}

Passenger::~Passenger() 
{

}

double Passenger::MySatisfaction()
{
    return (((double)rand()/RAND_MAX)*4)+1;
}
