# Shortest Remaining Time First (SRTF) 
======================================
This C program demonstrates the Shortest Remaining Time First (SRTF) scheduling algorithm. It schedules processes based on their remaining time (burst time) and calculates the completion time, waiting time, and turnaround time for each process.

## Algorithm:

1. Start the program execution.
2. Define the "process" structure with attributes: pid, at, bt, ct, rt, wt, tat.
3. Define the "findShortestJob" function that takes an array of processes (proc[]), the number of processes (n), and the current time (current_time) as input.
4. Initialize shortest_job as -1 and shortest_rt as infinity.
5. Iterate over each process in proc[]:
     - Check if the process has arrived (proc[i].at <= current_time).
     - If true, check if the remaining time (proc[i].rt) is less than shortest_rt and greater than 0.
     - If true, update shortest_rt to proc[i].rt and shortest_job to i.
6. Return shortest_job.
7. Define the "srtf" function that takes an array of processes (proc[]) and the number of processes (n) as input.
8. Initialize current_time as 0 and completed as 0.
9. Enter a while loop until completed is less than n:
     - Call the "findShortestJob" function to get the index of the process with the shortest remaining time among the arrived processes at current_time.
     - If no valid job is available (index is -1), increment current_time by 1 and continue to the next iteration.
     - Get a pointer to the process at the index.
     - Reduce the remaining time (rt) of the current job by 1.
     - If the remaining time is 0, update completion time (ct), turnaround time (tat), and waiting time (wt) of the process. Increment completed by 1.
     - Increment current_time by 1.
10. In the main function:
     - Prompt the user to enter the number of processes (n).
     - Read the input and create an array of processes (proc[]) of size n.
     - Prompt the user to enter arrival time and burst time for each process.
     - Read the input and initialize the remaining time (rt) of each process as the burst time (bt).
     - Call the "srtf" function passing proc[] and n.
     - Calculate the average waiting time (avg_wt) and average turnaround time (avg_tat).
     - Display the process details and their respective completion, turnaround, and waiting times.
     - Display the average waiting time and average turnaround time.
11. End the program.

Note: This algorithm assumes that the input values for arrival time and burst time are valid and correctly entered by the user. Error handling and input validation are not included in this algorithm.

## Code Explanation:

1. The program starts by defining a structure named `process` to represent a process. It contains attributes such as `pid`, `at`, `bt`, `ct`, `rt`, `wt`, and `tat` to store the process information.

2. The `findShortestJob()` function is used to find the index of the process with the shortest remaining time among the arrived processes at the given current time (`current_time`). It iterates through the processes and checks the arrival time, remaining time, and validity of the process. It returns the index of the shortest job.

3. The `srtf()` function implements the SRTF scheduling algorithm. It initializes the `current_time` and `completed` variables. It continues scheduling until all processes are completed. In each iteration, it calls the `findShortestJob()` function to find the index of the process with the shortest remaining time. If no valid job is available, it increments the current time and continues. Otherwise, it reduces the remaining time of the current job by 1. If the remaining time becomes 0, it updates the completion time, turnaround time, and waiting time of the completed job. It increments the `completed` count.

4. The main function reads the number of processes from the user, creates an array of `process` structures, and prompts the user to enter the arrival time and burst time for each process. It initializes the remaining time of each process with the burst time.

5. The `srtf()` function is called to schedule the processes.

6. The program calculates the average waiting time and average turnaround time for all processes.

7. It prints the process details, including the process ID, burst time, arrival time, completion time, waiting time, and turnaround time.

By following this algorithm, the program schedules processes using the SRTF algorithm and provides the necessary details and metrics for analysis.

I hope this updated explanation provides a clearer understanding of the SRTF scheduling algorithm and the corresponding C program.