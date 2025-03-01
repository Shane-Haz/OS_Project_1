# README.md for CS 3502 Project 1
Date: February 28, 2025
Author: Shane Hazeur
Course: CS 3502 Operating Systems

Project Overview

This project focuses on implementing multi-threading and inter-process communication (IPC) using pipes in a Linux-based environment.

The project consists of two main parts:

• Project A: Multi-Threading Implementation
• Project B: Inter-Process Communication (IPC) using Pipes (|)

I developed these components by conducting online research, watching YouTube tutorials, reading blogs, and referencing class materials.


Development & Problem-Solving Process

1. Research & Learning
I started by researching multi-threading and IPC concepts through:

• YouTube tutorials on C++ threading and pipes.
• Blog posts on Linux-based multi-threading and process communication.
• Class materials & lecture slides to ensure alignment with course requirements.

2. Environment Setup
Since the project required a Linux-based environment, I set up:

• Windows Subsystem for Linux (WSL) with Ubuntu.
• Installed GCC, G++, and Git for compilation and version control.
• Configured VS Code for development.

3. Multi-Threading Implementation (Project A)
Key Features Implemented:

• Created multiple threads using std::thread in C++.
• Used mutexes (std::mutex) to prevent race conditions.
• Simulated deadlocks and implemented deadlock prevention techniques.

Challenges & Solutions:

• Issue: Threads competing for shared resources.
• Solution: Implemented mutex locks to synchronize access.

• Issue: Deadlock when multiple threads tried to acquire locks in different orders.
• Solution: Introduced timeout mechanisms to prevent indefinite blocking.

4. Inter-Process Communication (Project B)
Key Features Implemented:

• Used Linux pipes (|) for communication between parent and child processes.
• Implemented custom C++ IPC with pipe() and fork().
• Used named pipes (mkfifo) for process-to-process communication.

Challenges & Solutions:

• Issue: Understanding how pipe() works in a parent-child process.
• Solution: Watched YouTube tutorials and read Linux documentation.

• Issue: Pipes getting blocked when one process writes but the other doesn’t read.
• Solution: Ensured both producer (echo) and consumer (cat) processes execute correctly.

5. Testing & Debugging
Threading Tests:

• Verified multiple threads executed concurrently.
• Checked for race conditions using stress tests.

IPC Tests:

• Used strace to trace pipe() system calls.
• Verified data integrity using echo | wc -c



How to Run the Code

1. Clone the Repository
In ubuntu run:

git clone https://github.com/your-username/CS3502-Project-1.git
cd CS3502-MultiThreading

2. Compile and Run Multi-Threading (Project A)

g++ -std=c++11 -pthread multi_threading.cpp -o multi_threading
./multi_threading

3. Compile and Run IPC using Pipes (Project B)

g++ -std=c++11 ipc_pipes.cpp -o ipc_pipes
./ipc_pipes

4. Run Producer-Consumer Using Named Pipes

mkfifo mypipe
./producer.sh &
./consumer.sh

Files in This Repository

File Name	                Description
multi_threading.cpp	        Implements multi-threading using C++ threads and mutexes.
ipc_pipes.cpp	            Implements IPC using pipe() in a parent-child process.
producer.sh	                Writes data to a named pipe (mypipe).
consumer.sh	                Reads data from a named pipe (mypipe).
README.md	                Project documentation.