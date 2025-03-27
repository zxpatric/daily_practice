
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>

int sharedData = 0;
// std::mutex mutex;
std::shared_mutex sharedMutex;
std::atomic<int> atomicCounter(0);

void modifyData() {
    std::lock_guard<std::shared_mutex> lock(sharedMutex);
    sharedData++;
    std::cout << "Modified data: " << sharedData << std::endl;
}

void readData() {
    std::shared_lock<std::shared_mutex> lock(sharedMutex);
    std::cout << "Read data: " << sharedData << std::endl;
}

void incrementCounter() {
    atomicCounter++;
    std::cout << "Incremented counter: " << atomicCounter << std::endl;
}