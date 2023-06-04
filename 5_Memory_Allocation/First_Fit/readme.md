# First Fit Memory Allocation Algorithm
========================================
The code provided implements the First Fit memory allocation algorithm in the C programming language. This algorithm is used in operating systems to allocate memory blocks to processes based on the first available block that is large enough to accommodate the process. The code takes user input for the number and size of memory blocks and processes, and then allocates the processes to the memory blocks using the First Fit algorithm. Finally, it displays the allocation results.

## Algorithm
1. Declare the function `firstfit` that takes the `block` array representing memory blocks, the number of blocks `m`, the `process` array representing processes, and the number of processes `n` as parameters.
2. Create an `allocation` array to store the allocation information for each process. Initialize all elements of the array to -1, indicating that no allocation has been made.
3. Iterate over each process:
   - Iterate over each memory block:
     - Check if the current memory block has enough space to accommodate the process.
     - If the block has enough space, allocate the process to that block, update the `allocation` array with the block number, and reduce the available space in the block.
     - Break out of the inner loop to move to the next process.
4. Display the allocation results:
   - Print a table with columns for process number, process size, and allocated block number (or "Not Allocated" if the process couldn't be allocated to any block).

## Program Explanation
- The `main` function serves as the entry point of the program.
- It prompts the user to enter the number of memory blocks (`m`) and their respective sizes, followed by the number of processes (`n`) and their sizes.
- The user inputs are stored in the `block` and `process` arrays.
- The `firstfit` function is called with the `block`, `m`, `process`, and `n` values.
- Within the `firstfit` function:
  - An `allocation` array is created to store the allocation results, initially set to -1 for all elements.
  - Two nested loops are used to iterate over each process and each memory block, respectively.
  - The First Fit logic is implemented: if a block has enough space for a process, the allocation is made, and the block size is reduced accordingly. The loop then breaks to move to the next process.
  - After the allocation loop, the allocation results are printed in a formatted table, displaying the process number, process size, and the allocated block number (or "Not Allocated" if the process couldn't be allocated to any block).
- Finally, the program terminates.

This code provides a basic implementation of the First Fit memory allocation algorithm in C, demonstrating how processes are allocated to available memory blocks.