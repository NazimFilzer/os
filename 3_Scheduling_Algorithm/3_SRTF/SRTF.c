#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tat;
} process;

// Function to find the index of shortest job
int findShortestJob(process proc[], int n, int current_time) {

    int shortest_job = -1;  //Index of Shortest job in proc[]
    int shortest_rt = 9999; // Assuming a maximum remaining time of 9999

    for (int i = 0; i < n; i++) {

        //proc[i].at <= current_time Ensures that the process has arrived 
        //Checks if the remaining time (rt) of the process is less than the current shortest burst time found so far.
        //Verifies that the process still has some remaining time left to execute.
        if (proc[i].at <= current_time && proc[i].rt < shortest_rt && proc[i].rt > 0) {
            shortest_rt = proc[i].rt;
            shortest_job = i;
        }
    }
    return shortest_job;
}


void srtf(process proc[], int n) {
    
    int current_time = 0;  // Represents the current time during scheduling
    int completed = 0;     // Indicates the number of processes completed.


    while (completed < n) {

        // find the index of the process with the shortest remaining time 
        // among the arrived processes at the current time 
        int shortest_job = findShortestJob(proc, n, current_time);

        
        if (shortest_job == -1) {
            //no valid job is available to execute at the current time
            current_time++;
            continue;
        }

        // job points to the process at index shortest_job.
        process *job = &proc[shortest_job];
        //reduces the (rt) of the current job by 1,
        job->rt--;


        if (job->rt == 0) {
            job->ct = current_time + 1;
            job->tat = job->ct - job->at;
            job->wt = job->tat - job->bt;
            completed++;
        }
        
        current_time++;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    process proc[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].rt = proc[i].bt;
    }

    srtf(proc, n);

    float avg_wt = 0, avg_tat = 0;

    printf("PID\tBurst\tArrival\tCompletion\tTurnaround\tWait\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].bt, proc[i].at, proc[i].ct, proc[i].tat, proc[i].wt);
        avg_wt += proc[i].wt;
        avg_tat += proc[i].tat;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
