# Preemptive Priority Scheduling

This code implements preemptive priority scheduling, a CPU scheduling algorithm used in operating systems. The program takes input for a set of processes, including their arrival time, burst time, and priority. It then schedules the processes based on their priority, allowing the process with the highest priority (lowest priority number) to execute first. The code calculates various metrics such as completion time, turnaround time, waiting time, and provides an average of these metrics.

## Algorithm
1. Initialize the number of completed processes and current time to zero.
2. Repeat until all processes are completed:
   - Find the process with the highest priority (lowest priority number) among the processes that have arrived and have remaining burst time.
   - If no process is found at the current time, increment the current time and continue to the next iteration.
   - Otherwise, update the selected process's remaining burst time by decrementing it by one.
   - If the remaining burst time of the process becomes zero:
     - Set the completion time as the current time plus one.
     - Calculate the turnaround time by subtracting the arrival time from the completion time.
     - Calculate the waiting time by subtracting the burst time from the turnaround time.
     - Increment the completed process count.
   - Increment the current time by one.

## Explanation of the Program
The program begins by prompting the user to enter the number of processes. It then initializes an array of process structures based on the given number of processes.

Next, the program asks the user to input the arrival time, burst time, and priority for each process. The process ID is assigned based on the order of input. The program also initializes other attributes of each process, such as waiting time (wt), turnaround time (tat), completion time (ct), and remaining time (rt).

After obtaining the input, the program calls the `priorityScheduling` function, which implements the preemptive priority scheduling algorithm described above. This function iterates until all processes are completed. Within each iteration, it finds the process with the highest priority among the arrived processes with remaining burst time.

If a process is found, its remaining time is decremented. If the remaining time becomes zero, the completion time, turnaround time, and waiting time are calculated, and the completed process count is incremented.

Once the scheduling is complete, the program calculates the average waiting time and average turnaround time by summing up the respective values for all processes and dividing by the total number of processes.

Finally, the program displays the process details, including process ID, arrival time, burst time, completion time, turnaround time, waiting time, and priority. It also presents the average waiting time and average turnaround time.

