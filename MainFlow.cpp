#include "MainFlow.h"


#define INSERT_DRIVER 1
#define INSERT_RIDE 2
#define INSERT_VEHICLE 3
#define REQUEST_DRIVER_LOCATION 4
#define STARTDRIVING 6
#define EXIT 7

#define STANDARD_CAB 1
#define LUXURY_CAB 2


/**********************************************

* Macro Name: DELETE_LIST

* Macro Arguments: Type of list and the list

* Macro Output: -

* Macro Aim: To free all elements in list

***********************************************/
#define DELETE_LIST(TYPE, LIS) \
{\
list<TYPE*>::iterator it = LIS.begin(); \
for (it++; it != LIS.end(); it++) \
{ \
    delete (*it); \
}\
}

using namespace std;


/***********************************************************

*    Function Name: MainFlow (C'tor)

*    Function Argumants: void

*    Function Output: MainFlow

*    Function Operation: runs all the system of inputs 
        according to the specified int the exercise

************************************************************/
MainFlow::MainFlow()
{
	int input;
	bool toContinue = true; // will be used in the while loop
	int sizeOfMap[2]; //x and y max values
	int numOfObs;
	int x, y;
	char temp;

	cin >> sizeOfMap[0];
	cin >> sizeOfMap[1];
	
	cin >> numOfObs;
	
	for (int i = 0; i < numOfObs; i++)
    {
        cin >> x >> temp >> y;
        obstacles << Point(x,y);
    }
	
	/*the do while loop*/
	do
	{
		cin >> input;
		switch(input)
		{
			case INSERT_DRIVER: 
			    InsertDriver();
				break;
			case INSERT_RIDE: 
			    InsertRide();
				break;
			case INSERT_VEHICLE: 
			    InsertVehicle();
				break;
			case REQUEST_DRIVER_LOCATION: 
			    RequestLocation();
				break;
			case STARTDRIVING: 
			    StartDriving();
				break;
			case EXIT: 
			    toContinue = false; 
			    DeleteAllData();
				break;
		}
	} while(toContinue);
}


/**************************************************************

*    Function Name: StartDriving

*    Function Arguments: void

*    Function Output: void

*    Function Operation: Moves all drivers and passangers 
                         to thier destenations

****************************************************************/
void MainFlow::StartDriving()
{
    list<Driver*>::iterator itDriver = TaxiCenter::GetDrivers().begin();
    itDriver++;
    
    
    
    list<Trip*>::iterator itTrip = TaxiCenter::GetTrips().begin();
    itTrip++;

    for (;itTrip != TaxiCenter::GetTrips().end(); itTrip++)
    {
        for (; itDriver != TaxiCenter::GetDrivers().end(); itDriver++)
        {
            if ((*itDriver)->GetLocation() == (*itTrip)->GetStart())
            {
                (*itDriver)->SetLocation((*itTrip)->GetEnd());
            }
        }
        itDriver = TaxiCenter::GetDrivers().begin();
        itDriver++;
    }
    DELETE_LIST(Trip, TaxiCenter::GetTrips())
}


/**************************************************************

*    Function Name: InsertRide

*    Function Arguments: void

*    Function Output: void

*    Function Operation: receives input from the user about
        a certain ride, creat this ride and add it to the
        trips list

****************************************************************/
void MainFlow::InsertRide()
{
	int id;
	int x_start;
	int y_start;
	Point start;
	int x_end;
	int y_end;
	Point end;
	int numPassengers;
	double tariff;
	char temp;
	Trip* newTrip = new Trip();
	
	cin >> id >> temp;
	cin >> x_start >> temp >> y_start >> temp;
	cin >> x_end >> temp >> y_end >> temp;
	cin >> numPassengers >> temp;
	cin >> tariff;
	
	start.x = x_start;
	start.y = y_start;
	end.x = x_end;
	end.y = y_end;
	
	
	newTrip->SetPrice(tariff);
	newTrip->SetID(id);
	newTrip->SetStart(start);
	newTrip->SetEnd(end);
	newTrip->SetPassangers(numPassengers);
	TaxiCenter::GetTrips() << newTrip;
}

/*****************************************************************

*    Function Name: DeleteAllDate

*    Function Arguments: void

*    Function Output: void

*    Function Operation: delete all the data used in the system

********************************************************************/
void MainFlow::DeleteAllData()
{
    DELETE_LIST(Cab, TaxiCenter::GetCabs())
    DELETE_LIST(Driver, TaxiCenter::GetDrivers())
    DELETE_LIST(Trip, TaxiCenter::GetTrips())
}


/*****************************************************************

*    Function Name: RequestLocation

*    Function Arguments: void

*    Function Output: void

*    Function Operation: Prints the location of driver of id 
        
********************************************************************/
void MainFlow::RequestLocation()
{
    int id;
    cin >> id;
    const Driver* d = TaxiCenter::GetDriver(id);
    cout << StatisticCenter::LocationOfDriver(d) << endl;
}

/*****************************************************************

*    Function Name: InsertDriver

*    Function Arguments: void

*    Function Output: void

*    Function Operation: receives input from the user about
        a certain driver, creat this driver and add it to the
        drivers list
        
********************************************************************/
void MainFlow::InsertDriver()
{
	unsigned int id;
	unsigned int age;
	char status;
	Driver::MartialStatus driversStatus;
	unsigned int experience;
	unsigned int vehicleId;
	Driver* newDriver = new Driver();
	Cab* cab;
	char temp; // the temp will take the comma each time
	bool toContinue = true;
	
	cin >> id >>  temp;
	cin >> age >>  temp;
	cin >> status >>  temp;
	cin >> experience >>  temp;
	cin >> vehicleId;
	
	switch(status)
	{
	case 'S': 
	    driversStatus = Driver::SINGLE;
		break;
	case 'M':
	    driversStatus = Driver::MARRIED;
		break;
	case 'D':
	    driversStatus = Driver::DIVORCED;
		break;
	case 'W':
	    driversStatus = Driver::WIDOWED;
		break;
	default: 
	    cout << "bad input new driver" << endl;
	    break;
	}
	
	newDriver->SetID(id);
	newDriver->SetAge(age);
	newDriver->SetStatus(driversStatus);
	newDriver->SetExp(experience);

	list<Cab* >::iterator it = TaxiCenter::GetCabs().begin();
	for (it++; it != TaxiCenter::GetCabs().end() && toContinue; it++)
    {
    	if( (*it)->GetID() == vehicleId)
    	{
    		cab = *it;
    		toContinue = false;
    	}
    }
    	
	newDriver->SetCab(cab);
	
	TaxiCenter::GetDrivers() << newDriver;
}

/******************************************************************

*    function Name: InsertVehicle

*    Function Arguments: void

*    Function Output: void

*    Function Operation: receives input from the user about
        a certain vehicle, creat this vehicle and add it to the
        vehicles list
        
**********************************************************************/
void MainFlow::InsertVehicle()
{
	char temp ; // will get the extra ',' in the input
	int id;
	int Type;
	char manufactor;
	char color;
	Cab::Color c;
	Cab::Manufactor m;
	Cab* newCab = new Cab();
	
	cin >> id >>  temp;
	cin >> Type >>  temp;
	cin >> manufactor >>  temp;
	cin >> color;

	switch(color)
	{
	case 'R': 
	    c = Cab::RED;
		break;
	case 'B': 
	    c = Cab::BLUE;
		break;
	case 'G': 
	    c = Cab::GREEN;
		break;
	case 'P':
	    c = Cab::PINK;
		break;
	case 'W':
	    c = Cab::WHITE;
		break;
	default:
	    cout << "bad input color of cab" <<endl;
	    break;
	}
	
	switch(manufactor)
	{
	case 'H':
	    m = Cab::HONDA;
		break;
	case 'S':
	    m = Cab::SUBARO;
		break;
	case 'T':
	    m = Cab::TESLA;
		break;
	case 'F':
	    m = Cab::FIAT;
		break;
	default:
	    cout << "bad input manufactor of cab"<<endl;	
	    break;
	}

	if(Type == STANDARD_CAB)
		newCab = new StandardCab();
	else if(Type == LUXURY_CAB)
		newCab = new LuxuryCab();
	
	newCab->SetKMP(0);
	newCab->SetID(id);
	newCab->SetManufactor(m);
	newCab->SetColor(c);
	//inserts the new cab to the cabs list
	TaxiCenter::GetCabs() << newCab;
}
