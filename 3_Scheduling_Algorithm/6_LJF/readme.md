# Round Robin Scheduling
========================

Round Robin scheduling is a CPU scheduling algorithm that is widely used in operating systems. It is a preemptive scheduling algorithm in which each process is executed for a fixed time quantum, and then it is moved to the end of the ready queue. This algorithm ensures fairness by providing equal opportunities for all processes to execute.

This program implements the Round Robin scheduling algorithm in C. It takes the arrival time and burst time for each process as input, calculates the completion time, turnaround time, and waiting time for each process, and displays the results. Finally, it calculates the average turnaround time and average waiting time for all the processes.

## Algorithm
1. Start by taking input for the number of processes (n).
2. Create a structure named Process with attributes pid (process ID), at (arrival time), bt (burst time), rt (remaining time), ct (completion time), tat (turnaround time), and wt (waiting time).
3. Define a function named calculateTimes that takes the process array and the number of processes as parameters.
4. Initialize variables currentTime = 0 and completed = 0 to keep track of the current time and the number of completed processes.
5. Use a while loop that runs until all processes are completed (completed < n).
6. Inside the while loop, initialize longestJobIndex = -1 and longestBT = 0. These variables will store the index of the process with the longest burst time that can be executed at the current time.
7. Iterate through the process array and check if the process is in the ready state (arrival time <= currentTime) and has remaining burst time (rt > 0).
8. If a process is found that satisfies the above conditions, check if it has a longer burst time than the previously found longestJobIndex. If yes, update the longestJobIndex and longestBT accordingly.
9. If no process is found that satisfies the conditions, increment the currentTime and continue to the next iteration of the while loop.
10. If a process is found, update its completion time (ct) by adding the burst time (bt) to the currentTime. Calculate the turnaround time (tat) by subtracting the arrival time (at) from the completion time (ct). Calculate the waiting time (wt) by subtracting the burst time (bt) from the turnaround time (tat). Set the remaining time (rt) to 0 to mark the process as completed.
11. Update the currentTime with the value of the completion time of the executed process and increment the completed count.
12. After the completion of the while loop, define a function named displayResults that takes the process array and the number of processes as parameters.
13. Inside the displayResults function, initialize totalTAT = 0 and totalWT = 0 to store the sum of the turnaround times and waiting times.
14. Iterate through the process array and display the process details (PID, Arrival, Burst, Completion, Turnaround, Waiting) for each process. Also, calculate the total turnaround time and total waiting time.
15. Calculate the average turnaround time (avgTAT) and average waiting time (avgWT) by dividing the total turnaround time and total waiting time by the number of processes.
16. Display the average turnaround time and average waiting time.
17. In the main function, take input for the number of processes (n).
18. Create an array of Process structures with size n.
19. Take input for the arrival time and burst time of each process and initialize the process attributes.
20. Call the calculateTimes function to calculate the completion time, turnaround time, and waiting time for

 each process.
21. Call the displayResults function to display the process details and the average turnaround time and average waiting time.
22. End the program.

## Program Explanation
1. The program starts by taking input for the number of processes (n) from the user.
2. It defines a Process structure with attributes pid, at, bt, rt, ct, tat, and wt.
3. The calculateTimes function is defined to calculate the completion time, turnaround time, and waiting time for each process.
4. Inside the calculateTimes function, the currentTime and completed variables are initialized.
5. A while loop is used to iterate until all processes are completed.
6. Inside the while loop, the longestJobIndex and longestBT variables are initialized to find the process with the longest burst time.
7. The process array is iterated to find a process that is ready and has remaining burst time.
8. If a suitable process is found, its burst time is compared with the previously found longest burst time, and the longestJobIndex and longestBT are updated accordingly.
9. If no suitable process is found, the currentTime is incremented, and the loop continues.
10. If a suitable process is found, its completion time, turnaround time, waiting time, and remaining time are updated, and the currentTime and completed count are incremented.
11. After the completion of the while loop, the displayResults function is called to display the process details and the average turnaround time and average waiting time.
12. Inside the displayResults function, the total turnaround time and total waiting time are calculated by iterating through the process array.
13. The process details and the calculated average turnaround time and average waiting time are displayed.
14. In the main function, the number of processes is taken as input, and an array of Process structures is created.
15. The arrival time and burst time for each process are taken as input, and the process attributes are initialized.
16. The calculateTimes function is called to calculate the completion time, turnaround time, and waiting time for each process.
17. The displayResults function is called to display the process details and the average turnaround time and average waiting time.
18. The program ends.