# Algorithm



1. Start by defining the maximum number of processes and resources using the constants `MAX_PROCESS` and `MAX_RESOURCE`.

2. Define a function `calculateNeed` that takes the `need` matrix, `maxDemand` matrix, `allocation` matrix, the number of processes `n`, and the number of resources `m` as parameters.

3. Inside the `calculateNeed` function, use nested loops to iterate over each process and resource. Calculate the `need` matrix by subtracting the corresponding values of the `allocation` matrix from the `maxDemand` matrix.

4. Define a function `isSafe` that takes the `available` array, `maxDemand` matrix, `allocation` matrix, `need` matrix, the number of processes `n`, and the number of resources `m` as parameters. The function returns an integer value indicating if the system is in a safe state (1) or an unsafe state (0).

5. Inside the `isSafe` function, declare and initialize an array `finish` to keep track of whether a process has finished or not. Initialize another array `work` to store the available resources.

6. Copy the values from the `available` array to the `work` array.

7. Use a `while` loop to iterate until all processes have finished.

8. Inside the loop, initialize a variable `found` to 0. This variable will be used to check if any process can be allocated resources.

9. Use a `for` loop to iterate over each process.

10. Check if the process is not finished (`finish[i] == 0`).

11. Inside the loop, initialize a variable `canBeAllocated` to 1. This variable will be used to check if the current process can be allocated resources.

12. Use another `for` loop to iterate over each resource.

13. Check if the `need` of the process for a particular resource is greater than the `work` for that resource. If so, set `canBeAllocated` to 0 and break out of the loop.

14. If `canBeAllocated` is still 1 after the inner loop, it means the current process can be allocated resources. Update the `work` array by adding the `allocation` of the current process.

15. Set `finish[i]` to 1 to mark the current process as finished.

16. Set `found` to 1 to indicate that a process was found and allocated resources.

17. Increment the `count` variable to keep track of the number of finished processes.

18. If `found` is still 0 after the `for` loop, it means no process can be allocated resources. Break out of the `while` loop.

19. Check if the `count` is less than the total number of processes `n`. If so, return 0 to indicate that the system is in an unsafe state (deadlock occurred).

20. If all processes have finished (`count == n`), return 1 to indicate that the system is in a safe state (no deadlock).

21. In the `main` function, declare the necessary variables, including the `allocation` matrix, `maxDemand` matrix, and `available` array.

22. Prompt the user to input the number of processes and resources.

23. Prompt the user to enter the allocation matrix values, the maximum demand matrix values, and the available resources.

24. Call the `calculateNeed` function to calculate the `need` matrix.

25. Call the `isSafe` function to check if the system is in a safe or unsafe state.

26. Print a message indicating

 whether the system is in a safe state or an unsafe state (possible deadlock).

27. End the program.

