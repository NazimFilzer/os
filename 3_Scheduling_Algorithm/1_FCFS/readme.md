# First Come First Serve(FCFS)
==========================

This program demonstrates the First Come First Serve (FCFS) scheduling algorithm. It calculates the completion time, waiting time, and turnaround time for a set of processes based on their arrival time and burst time. The program then displays the process details and calculates the total and average turnaround time and waiting time.

## Algorithm
1. Read the number of processes from the user.
2. Create a structure to represent each process with attributes: pid (process ID), at (arrival time), bt (burst time), ct (completion time), wt (waiting time), and tat (turnaround time).
3. Prompt the user to enter the arrival time and burst time for each process.
4. Sort the processes based on arrival time in ascending order (FCFS).
5. Initialize waiting time (wt) and completion time (ct) to 0 for each process.
6. Iterate through each process:
   - If the current time is less than the arrival time of the next process, update the current time to the arrival time.
   - Calculate the completion time, turnaround time, and waiting time for the current process.
   - Update the total waiting time and total turnaround time.
   - Update the current time to the completion time of the current process.
7. Calculate the average waiting time and average turnaround time by dividing the total waiting time and total turnaround time by the number of processes.
8. Display the process details, including process ID, arrival time, burst time, completion time, waiting time, and turnaround time.
9. Display the total and average turnaround time and waiting time.

## Program Explanation
The provided C program implements the FCFS scheduling algorithm. It starts by reading the number of processes from the user. It then creates a process structure array to store the details of each process.

The user is prompted to enter the arrival time and burst time for each process. The program initializes the waiting time and completion time of each process to 0.

The program then sorts the processes based on their arrival time in ascending order using the FCFS algorithm.

Next, the program calculates the completion time, turnaround time, and waiting time for each process by iterating through the process array. It takes into account if the next process arrives after a delay, updating the current time accordingly. The total waiting time and total turnaround time are also updated.

After the calculations, the program calculates the average turnaround time and average waiting time by dividing the total values by the number of processes.

Finally, the program displays the details of each process, including process ID, arrival time, burst time, completion time, waiting time, and turnaround time. It also shows the total and average turnaround time and waiting time.

Note: The program assumes valid input from the user and does not include error handling for invalid inputs.

---
