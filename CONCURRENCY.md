1. Why concurrency is used ?
In this project, concurrency is used to demonstrate multithreading in C++. Multiple check-in counters operate concurrently instead of processing passengers sequentially. The project also demonstrates synchronization mechanisms used to safely coordinate these threads.

2. Threads
Four threads are used here std::thread counter 1,std::thread counter 2,std::thread counter 3 and std::thread counter 4 for demonstrating the multithreading .
To avoid the use of many threads std::vector<std::thread>counters could have been used too. 

3. Mutex:
The operations like  std::mutex queueMUtex and std::mutex coutMutex to avoid the possibilty of the race conditions associated with the four thread counters .
they are used to protect shared resources. queueMutex protects access to the shared passenger queue, while coutMutex prevents multiple threads from writing to std::cout simultaneously and producing interleaved output.

4. lock_guard
The operation std::lock_guard is used to avoid the complexity and errors due to using the standard locking and unlocking functions with the mutexes .
for eg: queueMutex.lock() and queueMutex.unlock()

5. unique_lock

The operation std::unique_lock is used to give more flexibilty to get more control over the manual locking and unlocking of the mutexes and especially cv.wait function.
The condition variable temporarily unlocks the mutex while the thread is waiting and reacquires it before continuing.

6. Conditon variables
The operation of std::condition variable cv is used for passing the conditions like waiting and and notfiying the passangers.

7. Waiting and Notifying 
The waiting is for the passangers so that cv.wait the lambda function according to the condition remains in the waiting condition until notified via cv.notify_one()/cv.notify_all().

8.  Race condtions 
A race condition could occur if multiple counter threads accessed or modified shared data simultaneously without synchronization. For example, two threads modifying the passenger queue at the same time could produce incorrect or unpredictable results. std::mutex, together with RAII locking mechanisms such as std::lock_guard and std::unique_lock, is used to synchronize access to these shared resources.

9. How the Airport System uses these concepts

The Airport class simulates four airport check-in counters operating concurrently.

# Starting the counters

`startCounters()` creates four `std::thread` objects:

- `counter1`
- `counter2`
- `counter3`
- `counter4`

Each thread executes the same `counterWorker()` function but receives a different counter ID.

```cpp
counter1 = std::thread(&Airport::counterWorker, this, 1);
counter2 = std::thread(&Airport::counterWorker, this, 2);
counter3 = std::thread(&Airport::counterWorker, this, 3);
counter4 = std::thread(&Airport::counterWorker, this, 4);

10. Use of std::atomic
To manage the shared variable processedPassangers amongst the four counters the std::atomic is used to avoid hassles due to the manual locking and unlocking of mutexes .

# Why did i use std::atomic ?
--> DeadLock prevention: Since the atomics do not acquire locks ,the code using them is free from deadlocks .
--> Lock Free execution: since we do not have to use manual locking/unlocking our code remains Lock free . 


