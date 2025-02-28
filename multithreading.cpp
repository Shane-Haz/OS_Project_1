#include <iostream>
#include <thread>

#define NUM_THREADS 5

void print_message(int thread_id) {
    std::cout << "Thread " << thread_id << ": Running" << std::endl;
}

int main() {
    std::thread threads[NUM_THREADS];

    // Create multiple threads
    for (int t = 0; t < NUM_THREADS; t++) {
        std::cout << "Main: Creating thread " << t << std::endl;
        threads[t] = std::thread(print_message, t);
    }

    // Join threads (wait for them to finish)
    for (int t = 0; t < NUM_THREADS; t++) {
        threads[t].join();
    }

    std::cout << "Main: All threads completed." << std::endl;
    return 0;
}
