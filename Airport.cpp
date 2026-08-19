#include "Airport.h"

//Airport::Airport(): airportClosed(false){};

void Airport::startCounters(){
	counter1 = std::thread(&Airport::counterWorker, this ,1);
	counter2 = std::thread(&Airport::counterWorker , this , 2);
	counter3 = std::thread(&Airport::counterWorker , this , 3);
	counter4 = std::thread(&Airport::counterWorker ,  this , 4);
	
}
void Airport::addPassenger(const Passenger& p){
	std::lock_guard<std::mutex> lock1(queueMutex);
	waitingPassengers.push(p);
    cv.notify_one();

}
void Airport::counterWorker(int counterid){
	while(true){
		std::unique_lock<std::mutex> lock2(queueMutex);

		cv.wait(lock2,[this]{
			return !waitingPassengers.empty() || airportClosed;
		});
		if(airportClosed && waitingPassengers.empty()){
			break;
		}
		Passenger currentPassenger = waitingPassengers.front();

		waitingPassengers.pop();


		lock2.unlock();

		auto startTime = high_resolution_clock::now();

		std::this_thread::sleep_for(std::chrono::seconds(2));

		auto stopTime =  high_resolution_clock::now();

		auto duration =  duration_cast<microseconds>(stopTime - startTime);

		processedPassangers++;
		
		std::lock_guard<std::mutex>printlock(coutMutex);
		std::cout<< "Counter ID : \t"<< counterid
		<< " || Passenger ID : \t " << currentPassenger.id
		<< " || Processing time in seconds : " << duration.count()/1000000.0 << std::endl;

// Basically wait and sleep { !waitingPassengers.empty() ==> false} until there are no passengers.
	}
}
void Airport::updateStatistics(){
	std::lock(queueMutex,statsMutex);

	std::lock_guard<std::mutex>LOCK1(queueMutex,std::adopt_lock);

	std::lock_guard<std::mutex>LOCK2(statsMutex,std::adopt_lock);
}
void Airport::closeAirport(){
	std::lock_guard<std::mutex>lock3(queueMutex);
    airportClosed = true;
	cv.notify_all();

}
void Airport::waitforCompletion(){
	if (counter1.joinable())
		counter1.join();

	if(counter2.joinable()) counter2.join();

	if(counter3.joinable()) counter3.join();

	if(counter4.joinable()) counter4.join();
	

}



