#include <stdio.h>

typedef struct {
    int pid;
    int bt;
    int at;
    int rt;
    int priority;
    int wt;
    int tat;
    int ct;
} process;

void priorityScheduling(process proc[], int n) {
    int completed = 0;
    int current_time = 0;

    while (completed < n) {

        int highest_priority = 9999;
        int highest_priority_index = -1;

        //finding the index of the process with the highest priority (Lower Priority Number)
        for (int i = 0; i < n; i++) {
            if (proc[i].at <= current_time && proc[i].priority < highest_priority && proc[i].rt > 0) {
                highest_priority = proc[i].priority;
                highest_priority_index = i;
            }
        }

        // No Process Found at this Time
        if (highest_priority_index == -1) {
            current_time++;
            continue;
        }

        // pointer pointing to the Process with highest priority
        process *job = &proc[highest_priority_index];
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

    printf("Enter Arrival Time, Burst Time & Priority for each process:\n");
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        scanf("%d %d %d", &proc[i].at, &proc[i].bt, &proc[i].priority);

        //initilizing 
        proc[i].wt = 0;
        proc[i].tat = 0;
        proc[i].ct = 0;
        proc[i].rt=proc[i].bt;
    }

    priorityScheduling(proc, n);

    float avg_wt = 0, avg_tat = 0;

    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWait\tPriority\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].ct, proc[i].tat, proc[i].wt, proc[i].priority);
        avg_wt += proc[i].wt;
        avg_tat += proc[i].tat;
    }

    avg_wt /= n;
    avg_tat /= n;

    printf("Average Waiting Time: %.2f\n", avg_wt);
    printf("Average Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
