# Worst Fit Memory Allocation Algorithm
=======================================

The provided code implements the Worst Fit memory allocation algorithm in the C programming language. The Worst Fit algorithm is used in operating systems to allocate memory blocks to processes by selecting the largest block available that can accommodate a process. This program prompts the user to enter the number and sizes of memory blocks, as well as the number and sizes of processes. It then allocates the processes to the memory blocks using the Worst Fit algorithm and displays the allocation results.

## Algorithm
1. Declare the function `worstfit` that takes the `block` array representing memory blocks, the number of blocks `m`, the `process` array representing processes, and the number of processes `n` as parameters.
2. Create an `allocation` array to store the allocation information for each process. Initialize all elements of the array to -1, indicating that no allocation has been made.
3. Iterate over each process:
   - Initialize the variable `worstBlock` to -1, which will store the index of the worst fitting block for the current process.
   - Iterate over each memory block:
     - Check if the current memory block has enough space to accommodate the process.
     - If it does, check if `worstBlock` is still uninitialized (-1) or if the current block size is larger than the worst block found so far. If so, update `worstBlock` with the index of the current block.
   - If `worstBlock` is still uninitialized (-1), no block was found to fit the process. Skip allocation for this process.
   - Otherwise, allocate the process to the worst fitting block, update the `allocation` array, and reduce the available space in the block.
4. Display the allocation results:
   - Print a table with columns for process number, process size, and allocated block number (or "Not Allocated" if the process couldn't be allocated to any block).

## Program Explanation
- The `main` function serves as the entry point of the program.
- It prompts the user to enter the number of memory blocks (`m`) and their respective sizes, followed by the number of processes (`n`) and their sizes.
- The user inputs are stored in the `block` and `process` arrays.
- The `worstfit` function is called with the `block`, `m`, `process`, and `n` values.
- Within the `worstfit` function:
  - An `allocation` array is created to store the allocation results, initially set to -1 for all elements.
  - Two nested loops are used to iterate over each process and each memory block, respectively.
  - The Worst Fit logic is implemented: if a block has enough space for a process, it checks if it is the worst fit by comparing its size with the current worst block. If it is larger, it becomes the new worst block.
  - After the allocation loop, the allocation results are printed in a formatted table, displaying the process number, process size, and the allocated block number (or "Not Allocated" if the process couldn't be allocated to any block).
- Finally, the program terminates.

This code provides a basic implementation of the Worst Fit memory allocation algorithm in C, demonstrating how processes are allocated to available memory blocks by selecting the largest block available.