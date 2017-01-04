/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/
#define TO_STRING(OUTPUT,NAME) (OUTPUT) += to_string((NAME));

using namespace std;
#include "Driver.h"


std::string Driver::toString()
{
	string output = "Driver:\n";//recogniser
	/* using macro function to add each of the parameters to this string */
	output+="Id:";
	TO_STRING(output,GetID())
	output+="Age:";
	TO_STRING(output,GetAge())
	output+="Exp:";
	TO_STRING(output,GetExp())
	output+="Satisfaction:";
	TO_STRING(output,GetSatisfacation())
	output+="Cab:";
	output+=GetCab()->toString();
	output+="MartialStatus:";
	TO_STRING(output,GetStatus())
	output+="Location:";
	output+=GetLocation().toString();
	output +="Destination:";
	output+=GetDestination().toString();
	return output;
}
/********************************
function name: constructor
input:a string that describes the wanted driver
output:the driver via the string
usaeg: when passing an driver with socket we pass 
is as a string, here is the translation back;
*********************************/
bool ifContaining(string str1,string str2) 
//checks if the first variables in str2 are str1
//[str1 <= str2]
//after the comparison it deletes str1 from str2
//if they aren't the same return false and change nothing
{
	int i;
	for(i=0;i<str2.size();i++)
		if(str1[i]!=str2[i])
			return false;
	str2.erase(1,str1.length());
	return true;
}

Driver::Driver(string dString)
{
	int temp;

	if(!ifContaining("Driver:\n",dString))
	{
        throw string("N");
	}
	
	if(ifContaining("Id:",dString))
	{
		SetID(stoi(dString));
		ifContaining(to_string(GetID()),dString);
	}
	
	if(ifContaining("Age:",dString))
	{
		SetAge(std::stoi(dString));
		ifContaining(to_string(GetAge()),dString); //removes the number from the string; 
	}
	
	if(ifContaining("Exp:",dString))
	{
		SetExp(stoi(dString));
		ifContaining(to_string(GetExp()),dString);
	}
	if(ifContaining("Satisfaction:",dString))
	{
		SetSatisfacation(atof(dString.c_str()/*return this string as const char * */));
		ifContaining(to_string(GetSatisfacation()),dString);
	}
	if(ifContaining("Cab:",dString))
	{
		SetCab(new Cab(dString));
	}

	if(ifContaining("MartialStatus:",dString))
	{
		temp = stoi(dString);
		SetStatus((MartialStatus)temp);
		ifContaining(to_string(GetStatus()),dString);
	}

	if(ifContaining("Location:",dString))
	{
		SetLocation(Point(dString));
	}

	if(ifContaining("Destination:",dString))
	{
		SetDestination(Point(dString));
	}	
}

Driver::Driver() 
{
	Point *p = new Point(0,0);
	m_location = *p;
}

Driver::Driver(const Point& p)
{
	m_location = p;
}

Driver::~Driver() 
{

}

