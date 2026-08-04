#ifndef AIRPORT_H
#define AIRPORT_H

#include<iostream>
#include<chrono>
#include<thread>
#include<mutex>
#include<algorithm>
#include<queue>
#include<condition_variable>
#include<vector>

using namespace std::chrono;

struct Passenger{
    int id;
    double arrivalTime;
};
class Airport{
    private:
    std::queue<Passenger> waitingPassengers;
    std::mutex queueMutex;
    std::condition_variable cv;

    std::thread counter1;
    std::thread counter2;
    std::thread counter3;
    std::thread counter4;

    std::mutex coutMutex;

    bool airportClosed ;

    void counterWorker(int counterid);
public:
        
    Airport():airportClosed(false){};
    void startCounters();
    void closeAirport();
    void waitforCompletion();
    void addPassenger(const Passenger& p);

};
#endif


