/*
1)

Imagine you are designing a system that is accessed by multiple users simultaneously 
(Every user should get equal priority). Implement the suitable CPU scheduling algorithm for 
this scenario. Find the average waiting time and turnaround time.

*/

#include <stdio.h>

#define MAX_PROCESSES 20
#define MAX_QUEUE_SIZE 100

// Structure of a Process
typedef struct {
  int id;
  int at;
  int bt;
  int ct;
  int tat;
  int wt;
  int rt;
  
  //used to check whether the process in ready(status=1)
  int status;
} Process;

// Global variables (Queue to store index of the Process in process array)
int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

// Function prototypes
void enqueue(int j);
int dequeue();
void roundRobinScheduling(Process processes[], int n, int quantum);
float calculateAverageWaitingTime(Process processes[], int n);
float calculateAverageTurnaroundTime(Process processes[], int n);

int main() {
  int n;          // Total Number of Processes
  int quantum;    // Time Quantum

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  //Process Array
  Process processes[MAX_PROCESSES];

  // Input process details
  printf("\nEnter the Arrival Time and Burst Time:\n");
  for (int i = 0; i < n; i++) {
    processes[i].id = i + 1;
    scanf("%d", &processes[i].at);
    scanf("%d", &processes[i].bt);
    processes[i].rt = processes[i].bt;

    //All process are in Ready Queue
    processes[i].status = 0;
  }

  printf("\nEnter the time quantum: ");
  scanf("%d", &quantum);

  

  roundRobinScheduling(processes, n, quantum);

  printf("\nID\tAT\tBT\tCT\tTAT\tWT\n\n");
  for (int i = 0; i < n; i++) {
    printf("%4d\t%2d\t%2d\t%2d\t%2d\t%2d\n", processes[i].id, processes[i].at,
           processes[i].bt, processes[i].ct,processes[i].tat,processes[i].wt);
  }
  printf("\nAverage Turnaround Time: %.2f\n", calculateAverageTurnaroundTime(processes, n));
  printf("\nAverage Waiting Time: %.2f", calculateAverageWaitingTime(processes, n));
  

  return 0;
}

// Function to insert into the queue
void enqueue(int j) {
    
    //If Queue is Empty
    if (front == -1 && rear == -1) {
        front=rear=0;
    }
    else{
        rear++;
    }    
    queue[rear] = j;
}

// Function to remove from the queue
int dequeue() {

    //Queue is Empty
    if (front == -1) {
        return -1;
    }

    int item = queue[front];

    //Single Item in Queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return item;
}

// Perform Round Robin scheduling
void roundRobinScheduling(Process p[], int n, int quantum) {
  int current_time = 0;         // Current current_time
  int completed = 0;            // No. of Processes Completed
  int dequeuedItem = -1;        // -1 indicates no Process Index is dequed from the Ready Queue
  int quantumExpire = 0;        // Indicates the time run within the Quanta

  // Waiting for the first process to arrive
  while (current_time != p[0].at){
    current_time++;
  }

  // Pushing the first process
  enqueue(0);
  p[0].status = 1;



  while (completed < n) {

    // Process moved into Running State 
    if (dequeuedItem == -1) {
      dequeuedItem = dequeue();
    }

    current_time++;

    // Check for new processes arrivals
    for (int i = 0; i < n; i++) {
      if (p[i].status == 0 && p[i].at <= current_time) {
        enqueue(i);
        p[i].status = 1;
      }
    }

    // if the ready Queue is Not Empty
    if (dequeuedItem != -1) {

        if (quantumExpire <= quantum && p[dequeuedItem].rt > 0) {
            p[dequeuedItem].rt--;
            quantumExpire++;
        }

        if (p[dequeuedItem].rt == 0) {
            p[dequeuedItem].ct = current_time;
            p[dequeuedItem].tat = p[dequeuedItem].ct -p[dequeuedItem].at;
            p[dequeuedItem].wt = p[dequeuedItem].tat - p[dequeuedItem].bt;
            completed++;
            dequeuedItem = -1;
            quantumExpire = 0;
        } else if (quantumExpire == quantum) {

            // Moving Process from Running State to Ready State
            enqueue(dequeuedItem);
            dequeuedItem = -1;     // No item in Running State
            quantumExpire = 0;     // reseting quantumExpire
        }
    }
  }
}

// Calculate the average waiting time
float calculateAverageWaitingTime(Process p[], int n) {
  float totalWaitingTime = 0;

  for (int i = 0; i < n; i++) {
    totalWaitingTime += p[i].wt;
  }

  return totalWaitingTime / n;
}

// Calculate the average turnaround time
float calculateAverageTurnaroundTime(Process p[], int n) {
  float totalTurnaroundTime = 0;

  for (int i = 0; i < n; i++) {
    totalTurnaroundTime += p[i].tat;
  }
  return totalTurnaroundTime / n;
}
