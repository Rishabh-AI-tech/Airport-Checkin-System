#include<iostream>
#include "Airport.h"


int main(int argc , char* agrv[]){
	Airport airport;

	airport.startCounters();

	Passenger p1;
	p1.id = 1;
	p1.arrivalTime = 0.0;
	Passenger p2;
	p2.id = 2;
	p2.arrivalTime = 0.0;
	Passenger p3;
	p3.id = 3;
	p3.arrivalTime = 0.0;
	Passenger p4;
	p4.id = 4;
	p4.arrivalTime = 0.0;
	Passenger p5;
	p5.id = 5;
	p5.arrivalTime = 0.0;

	airport.addPassenger(p1);
	std::this_thread::sleep_for(std::chrono::seconds(2));
	airport.addPassenger(p2);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	airport.addPassenger(p3);
	std::this_thread::sleep_for(std::chrono::seconds(1));
	airport.addPassenger(p4);
	std::this_thread::sleep_for(std::chrono::seconds(5));
	airport.addPassenger(p5);


    airport.closeAirport();
	airport.waitforCompletion();

	return 0;
}