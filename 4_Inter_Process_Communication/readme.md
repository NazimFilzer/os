# IPC Readme

## Introduction
This repository contains two C programs that demonstrate Inter-Process Communication (IPC) using shared memory. The programs, `Writer.c` and `Reader.c`, showcase how processes can share and communicate data through a shared memory segment.

## Algorithm
The programs follow the following algorithm:

1. Obtain a key using the `ftok()` function to uniquely identify the shared memory segment.
2. Create a shared memory segment using `shmget()` with the obtained key, specifying the size and permissions.
3. Attach the shared memory segment to the process's address space using `shmat()`.
4. Read or write data to the shared memory segment as needed.
5. Detach the shared memory segment using `shmdt()` when finished.
6. Optionally, remove the shared memory segment using `shmctl()` with the `IPC_RMID` flag.

## Explanation of Header Files and Functions Used
The programs utilize the following header files and functions:

- `stdio.h`: Provides input/output functions like `printf()` and `puts()`.
- `stdlib.h`: Includes functions such as `exit()` for program termination and `ftok()` for generating a key.
- `sys/ipc.h`: Defines the `ftok()` function and the `key_t` type for key generation.
- `sys/shm.h`: Contains functions and structures for shared memory management, including `shmget()` and `shmat()`.

Functions used in the programs:
- `ftok()`: Generates a unique key based on a file path and an identifier.
- `shmget()`: Creates a new shared memory segment or accesses an existing one.
- `shmat()`: Attaches the shared memory segment to the process's address space.
- `printf()`: Prints formatted output to the console.
- `puts()`: Writes a string to the standard output.
- `exit()`: Terminates the program execution.

## Conclusion
The provided programs demonstrate the basic usage of shared memory for IPC. They showcase how processes can share data through a shared memory segment, allowing efficient communication and synchronization between them. By following the algorithm and understanding the functions used, developers can build more complex IPC systems using shared memory.