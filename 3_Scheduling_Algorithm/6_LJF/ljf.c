#include <stdio.h>

typedef struct {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
} Process;

void calculateTimes(Process p[], int n) {
    int currentTime = 0;  
    int completed = 0;      //no. of processes completed

    while (completed < n) {
        int longestJobIndex = -1;     // currently no logest job found
        int longestBT = 0;            // longest BT

        for (int i = 0; i < n; i++) {
            if (p[i].at <= currentTime && p[i].rt > 0) {
                if (longestJobIndex == -1 || p[i].bt > longestBT) {
                    longestJobIndex = i;
                    longestBT = p[i].bt;
                }
            }
        }
        
        //if we dont find longest job continue
        if (longestJobIndex == -1) {
            currentTime++;
            continue;
        }

        p[longestJobIndex].ct = currentTime + p[longestJobIndex].bt;
        p[longestJobIndex].tat = p[longestJobIndex].ct - p[longestJobIndex].at;
        p[longestJobIndex].wt = p[longestJobIndex].tat - p[longestJobIndex].bt;
        p[longestJobIndex].rt = 0;
        currentTime = p[longestJobIndex].ct;
        completed++;
    }
}


//Function to display result
void displayResults(Process p[], int n) {
    int totalTAT = 0;
    int totalWT = 0;

    printf("PID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
        p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totalTAT += p[i].tat;
        totalWT += p[i].wt;
    }

    float avgTAT = (float)totalTAT / n;
    float avgWT = (float)totalWT / n;

    printf("Average Turnaround Time: %.2f\n", avgTAT);
    printf("Average Waiting Time: %.2f\n", avgWT);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process p[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        
        scanf("%d %d", &p[i].at,&p[i].bt);
        
        p[i].pid = i + 1;
        p[i].ct = 0;
        p[i].tat = 0;
        p[i].wt = 0;
        p[i].rt=p[i].bt;
    }

    calculateTimes(p, n);
    displayResults(p, n);

    return 0;
}