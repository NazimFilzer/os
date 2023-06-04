

# Round Robin Scheduling
========================
Round Robin scheduling is a CPU scheduling algorithm that is widely used in operating systems. It is a preemptive scheduling algorithm in which each process is executed for a fixed time quantum, and then it is moved to the end of the ready queue. This algorithm ensures fairness by providing equal opportunities for all processes to execute.

This program implements the Round Robin scheduling algorithm in C. It takes the arrival time, burst time, and time quantum as input for a set of processes and calculates the completion time, turnaround time, and waiting time for each process. Finally, it calculates the average turnaround time and average waiting time for all the processes.

## Algorithm
1. Take input for the total number of processes (n) and the time quantum.
2. Create an array to store the process details (Process processes[MAX_PROCESSES]) and initialize the queue (int queue[MAX_QUEUE_SIZE]).
3. Take input for the arrival time and burst time of each process and store them in the process array. Initialize the remaining attributes of each process such as ct, tat, wt, rt, and status.
4. Call the roundRobinScheduling() function with the process array, the number of processes (n), and the time quantum as parameters.
5. Inside the roundRobinScheduling() function, initialize variables current_time = 0, completed = 0, dequeuedItem = -1, and quantumExpire = 0.
6. Wait for the first process to arrive by incrementing the current_time until it matches the arrival time of the first process (p[0].at).
7. Push the index of the first process into the queue using the enqueue() function and mark its status as 1.
8. Start a while loop that runs until all processes are completed (completed < n).
9. If there is no process currently running (dequeuedItem == -1), dequeue an item from the queue using the dequeue() function.
10. Increment the current_time by 1.
11. Check for any new process arrivals by iterating through the process array. If a process is in the ready state (status = 0) and its arrival time (at) is less than or equal to the current_time, enqueue its index and mark its status as 1.
12. If there is a process running (dequeuedItem != -1), execute the following steps:
    a. If the quantumExpire is less than the time quantum and the remaining time (rt) of the process is greater than 0, decrement the remaining time by 1 and increment the quantumExpire by 1.
    b. If the remaining time (rt) of the process becomes 0, update its completion time (ct), turnaround time (tat), waiting time (wt), mark it as completed, reset dequeuedItem to -1, and reset quantumExpire to 0.
    c. If the quantumExpire becomes equal to the time quantum, move the process from the running state to the ready state by enqueueing its index, set dequeuedItem to -1, and reset quantumExpire to 0.
13. After the completion of the while loop, calculate the average waiting time and average turnaround time by calling the calculateAverageWaitingTime() and calculateAverageTurnaroundTime() functions, respectively, and store the results.
14. Finally, print the process details (ID, AT, BT, CT, TAT, WT) and the calculated average turnaround time and average waiting time.

## Program Explanation
1. The program starts by taking input for the total number of processes (n) and the time quantum.
2