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
