# Airport Check-in System ✈️

A multithreaded C++ simulation of an airport check-in system where multiple passengers are processed concurrently using synchronization primitives.

## Features

- Multiple passenger threads
- Airport check-in counters
- Thread synchronization using `std::mutex`
- Coordination using `std::condition_variable`
- Clean Object-Oriented Design

## Technologies

- C++17
- STL
- Multithreading
- Mutex
- Condition Variables
- Atomics
- lock_guard
- unique_lock

## Project Structure

```
Airport checking system/
├── Airport.cpp
├── Airport.h
├── main.cpp
└── .gitignore
```

## Build

```bash
g++ main.cpp Airport.cpp -pthread -o airport
```

## Run

```bash
./airport
```

## Concepts Demonstrated

- Object-Oriented Programming
- Multithreading
- Synchronization
- Thread Safety
- Deadlock safety
- Race condition prevention

- ## UML Class Diagram

classDiagram

class Airport {
    -waitingPassengers : std::queue~Passenger~
    -queueMutex : std::mutex
    -statsMutex : std::mutex
    -totalProcessingTime : int
    -cv : std::condition_variable
    -counter1 : std::thread
    -counter2 : std::thread
    -counter3 : std::thread
    -counter4 : std::thread
    -coutMutex : std::mutex
    -airportClosed : bool
    -processedPassengers : std::atomic~int~

    -counterWorker(int counterid) : void

    +Airport() : void
    +startCounters() : void
    +updateStatistics() : void
    +closeAirport() : void
    +waitforCompletion() : void
    +addPassenger(const Passenger& p) : void
}
