#ifndef _H_GURD_MAIN_FLOW
#define _H_GURD_MAIN_FLOW

#include "Driver.h"
#include "StandardCab.h"
#include "LuxuryCab.h"
#include <iostream>
#include "Driver.h"
#include <list>
#include <string>
#include "functions.h"
#include "Trip.h"
#include "TaxiCenter.h"
#include "StatisticCenter.h"

using namespace std;
class MainFlow
{
private:

    list <Point> obstacles;

	/*the functions used by the main*/
	void InsertDriver();
	
	void InsertVehicle();
	
	void RequestLocation();

	void DeleteAllData();

	void InsertRide();

	void StartDriving();
	
	
public:

	MainFlow();

    
};

#endif
