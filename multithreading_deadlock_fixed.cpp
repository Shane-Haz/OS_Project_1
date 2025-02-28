#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex lock1, lock2;

void thread_function1() {
    std::scoped_lock guard(lock1, lock2); // Lock both at the same time
    std::cout << "Thread 1: Acquired both locks\n";
}

void thread_function2() {
    std::scoped_lock guard(lock1, lock2); // Lock both at the same time
    std::cout << "Thread 2: Acquired both locks\n";
}

int main() {
    std::thread t1(thread_function1);
    std::thread t2(thread_function2);

    t1.join();
    t2.join();

    std::cout << "Main: Threads completed safely." << std::endl;
    return 0;
}
