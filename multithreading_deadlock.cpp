#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex lock1, lock2;

void thread_function1() {
    std::cout << "Thread 1: Locking lock1\n";
    lock1.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::cout << "Thread 1: Waiting for lock2\n";
    lock2.lock();
    std::cout << "Thread 1: Acquired lock2\n";

    lock2.unlock();
    lock1.unlock();
}

void thread_function2() {
    std::cout << "Thread 2: Locking lock2\n";
    lock2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::cout << "Thread 2: Waiting for lock1\n";
    lock1.lock();
    std::cout << "Thread 2: Acquired lock1\n";

    lock1.unlock();
    lock2.unlock();
}

int main() {
    std::thread t1(thread_function1);
    std::thread t2(thread_function2);

    t1.join();
    t2.join();

    std::cout << "Main: Threads completed." << std::endl;
    return 0;
}
