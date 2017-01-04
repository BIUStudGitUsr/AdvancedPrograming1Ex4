/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/
#define TO_STRING(OUTPUT,NAME) (OUTPUT) += std::to_string((NAME));
#include "Trip.h"
#include <string>
using namespace std;
std::string Trip::toString()
{
	string output = "Trip:\n";//recogniser
	/* using macro function to add each of the parameters to this string */
	output+="Id:";
	TO_STRING(output,GetID())
	output+="Meters:";
	TO_STRING(output,GetMetersPassed())
	output+="Start:";
	output+= GetStart().toString();
	output+="End:";
	output+= GetEnd().toString();
	output+="Price:";
	output+=TO_STRING(output,GetPrice())
}

Trip::Trip(string tString)
{
	int temp;
	std::string::size_type sz;
	if(!ifContaining("Trip:\n",tString))
	{
		throw string("N");
	}

	if(ifContaining("Id:",tString))
	{
		SetID(stoi(tString));
		ifContaining(to_string(GetID()),tString);
	}
	if(ifContaining("meters:",tString))
	{
		SetMetersPassed(stoi(tString));
		ifContaining(to_string(GetMetersPassed()),tString);
	}
	if(ifContaining("Start:",tString))
	{
		SetStart(Point(tString));
	}
	if(ifContaining("End:",tString))
	{
		SetEnd(Point(tString));
	}
	if(ifContaining("Price:",tString))
	{
		SetPrice(atof(tString.c_str()))/*return this string as const char * */));
		ifContaining(to_string(GetPrice()),tString);
	}
}
Trip::Trip() 
{

}

Trip::~Trip() 
{

}

