a.out: BFS.o Cab.o Driver.o LuxuryCab.o Passenger.o Point.o StandardCab.o StatisticCenter.o TaxiCenter.o Trip.o MainFlow.o main.o
	g++ BFS.o Cab.o Driver.o LuxuryCab.o Passenger.o Point.o StandardCab.o StatisticCenter.o TaxiCenter.o Trip.o MainFlow.o main.o
BFS.o: BFS.cpp
	g++ -c BFS.cpp
MainFlow.o: MainFlow.cpp
	g++ -c MainFlow.cpp
Cab.o: Cab.cpp
	g++ -c Cab.cpp
Driver.o: Driver.cpp
	g++ -c Driver.cpp
LuxuryCab.o: LuxuryCab.cpp
	g++ -c LuxuryCab.cpp
Passenger.o: Passenger.cpp
	g++ -c Passenger.cpp
Point.o: Point.cpp
	g++ -c Point.cpp
StandardCab.o: StandardCab.cpp
	g++ -c StandardCab.cpp
StatisticCenter.o: StatisticCenter.cpp
	g++ -c StatisticCenter.cpp
TaxiCenter.o: TaxiCenter.cpp
	g++ -c TaxiCenter.cpp
main.o: main.cpp
	g++ -c main.cpp
Trip.o: Trip.cpp
	g++ -c Trip.cpp
functions.o: functions.cpp
	g++ -c functions.cpp
