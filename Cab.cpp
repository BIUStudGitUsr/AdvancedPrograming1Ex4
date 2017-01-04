/*
* Partners :
* Names  : Efraim Vagner and Avi Kadria
* Id (Avi)    : 211991401
* Id (Efraim) : 207304262
*/
#define TO_STRING(OUTPUT,NAME) (OUTPUT) += std::to_string((NAME));
#include "Cab.h"

std::string Cab::toString()
{
	std::string output = "Cab:\n";
	output+="Kmp:";
	TO_STRING(output,GetKMP())
	output+="Id:";
	TO_STRING(output,GetID())
	output+="Speed:";
	TO_STRING(output,GetSpeed())
	output+="Manufactor:";
	TO_STRING(output,GetManufactor())
	output+="color:";
	TO_STRING(output,GetColor())
	return output;
}

bool ifContaining(string str1,string str2) ;
//checks if the first variables in str2 are str1
//[str1 <= str2]
//after the comparison it deletes str1 from str2
//if they aren't the same return false and change nothing
/*{
	int i;
	for(i=0;i<str2.size();i++)
		if(str1[i]!=str2[i])
			return false;

	str2.erase(str2.begin()+str1.size());
	return true;
}*/

Cab::Cab(std::string cString)
{
	int temp;
	if(!ifContaining("Cab:\n",cString))
	{
        throw string("N");
	}
	
	if(ifContaining("Kmp:\n",cString))
	{
		SetKMP(std::stoi(cString));
		ifContaining(to_string(GetKMP()),cString); //removes the number from the string; 
	}
	if(ifContaining("Id:",cString))
	{
		SetID(stoi(cString));
		ifContaining(to_string(GetID()),cString);
	}
	if(ifContaining("Speed:",cString))
	{
		SetSpeed(stoi(cString));
		ifContaining(to_string(GetSpeed()),cString);
	}
	if(ifContaining("Manufactor:",cString))
	{
		temp = stoi(cString);
		SetManufactor((Manufactor)temp);
		ifContaining(to_string(GetManufactor()),cString);
	}
	if(ifContaining("color:",cString))
	{
		temp = stoi(cString);
		SetColor((Color)temp);
		ifContaining(to_string(GetColor()),cString);
	}
}

Cab::Cab()
{

}

Cab::~Cab() 
{
    
}

