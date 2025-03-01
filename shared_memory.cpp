#include <iostream>
#include <fcntl.h>    // For O_CREAT, O_RDWR
#include <sys/mman.h> // For shared memory
#include <unistd.h>   // For fork()
#include <cstring>    // For strcpy, strlen

#define SHM_NAME "/mySharedMemory"  // Shared memory object name
#define SHM_SIZE 1024               // Size of shared memory

int main() {
    // Create shared memory
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        std::cerr << "Failed to create shared memory!" << std::endl;
        return 1;
    }

    // Set the shared memory size
    ftruncate(shm_fd, SHM_SIZE);

    // Map shared memory into process address space
    void* ptr = mmap(0, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        std::cerr << "Failed to map shared memory!" << std::endl;
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    if (pid > 0) {  // Parent Process
        std::cout << "Parent: Writing to shared memory..." << std::endl;
        const char* message = "Hello from parent process!";
        strcpy((char*)ptr, message);
        
        // Wait for child process to read
        sleep(2);

        // Unlink shared memory after child reads it
        shm_unlink(SHM_NAME);
    } else {  // Child Process
        sleep(1);  // Ensure parent writes first
        std::cout << "Child: Reading from shared memory: " << (char*)ptr << std::endl;
    }

    return 0;
}
