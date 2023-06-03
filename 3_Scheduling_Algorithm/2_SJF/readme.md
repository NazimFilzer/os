# Shortest Job First (SJF)
==========================
This program simulates the Shortest Job First (SJF) scheduling algorithm. SJF is a non-preemptive CPU scheduling algorithm where the process with the shortest burst time is selected for execution first. The goal of this algorithm is to minimize the average waiting time and turnaround time of the processes.

## Algorithm:

1. Read the number of processes (n) from the user.
2. Create an array of `Process` structures to store the process details.
3. Read the arrival time and burst time for each process from the user and initialize the remaining variables (pid, completion time, turnaround time, waiting time, and remaining time).
4. Implement the `calculateTimes` function:
    a. Initialize the current time and completed variables to 0.
    b. Use a while loop to iterate until all processes are completed.
    c. Find the process with the shortest remaining burst time among the eligible processes that have arrived and have some burst time remaining.
    d. If no eligible process is found, increment the current time by 1 and continue to the next iteration.
    e. Update the completion time, turnaround time, waiting time, remaining time, and current time for the selected process.
    f. Increment the completed variable to track the number of completed processes.
5. Implement the `displayResults` function:
    a. Calculate the total turnaround time and total waiting time.
    b. Display the process details (PID, arrival time, burst time, completion time, turnaround time, and waiting time) for each process.
    c. Calculate and display the average turnaround time and average waiting time.
6. In the `main` function:
    a. Read the number of processes from the user.
    b. Read the arrival time and burst time for each process and initialize the process details.
    c. Call the `calculateTimes` function to calculate the completion time, turnaround time, and waiting time for each process.
    d. Call the `displayResults` function to display the process details and average times.
7. End the program.

## Program Explanation:

The program prompts the user to enter the number of processes and the arrival time and burst time for each process. It then calculates the completion time, turnaround time, and waiting time for each process using the SJF scheduling algorithm.

The `calculateTimes` function is responsible for scheduling the processes based on their burst time and updating the necessary variables. It uses a while loop to continue the scheduling until all processes are completed. Inside the loop, it finds the process with the shortest remaining burst time among the eligible processes. If no eligible process is found, it increments the current time by 1 and continues to the next iteration. Once a process is selected, it updates the completion time, turnaround time, waiting time, and remaining time, and increments the completed variable.

The `displayResults` function displays the process details (PID, arrival time, burst time, completion time, turnaround time, and waiting time) for each process. It also calculates and displays the average turnaround time and average waiting time.

The main function reads the user input, calls the `calculateTimes` function to schedule the processes, and calls the `displayResults` function to show the process details and average times.

