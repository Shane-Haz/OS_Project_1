#include <iostream>
#include <unistd.h> // For pipe(), fork(), read(), write()
#include <cstring>  // For strlen()

int main() {
    int pipefd[2];  // File descriptors for the pipe
    pid_t pid;
    char buffer[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        std::cerr << "Pipe creation failed!" << std::endl;
        return 1;
    }

    // Fork a new process
    pid = fork();

    if (pid < 0) {
        std::cerr << "Fork failed!" << std::endl;
        return 1;
    }

    if (pid > 0) {  // Parent process
        close(pipefd[0]);  // Close unused read end
        const char* message = "Hello from parent!";
        write(pipefd[1], message, strlen(message) + 1);
        close(pipefd[1]);  // Close write end
    } else {  // Child process
        close(pipefd[1]);  // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        std::cout << "Child received: " << buffer << std::endl;
        close(pipefd[0]);  // Close read end
    }

    return 0;
}
