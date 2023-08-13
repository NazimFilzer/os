#include <stdio.h>
#define MAX_PROCESS 10
#define MAX_RESOURCE 10


//Function to calculate need matrix
void calculateNeed(int need[MAX_PROCESS][MAX_RESOURCE], int maxDemand[MAX_PROCESS][MAX_RESOURCE], int allocation[MAX_PROCESS][MAX_RESOURCE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = maxDemand[i][j] - allocation[i][j];
        }
    }
}

int isSafe(int available[MAX_RESOURCE], int maxDemand[MAX_PROCESS][MAX_RESOURCE], int allocation[MAX_PROCESS][MAX_RESOURCE], int need[MAX_PROCESS][MAX_RESOURCE], int n, int m) {
    int finish[MAX_PROCESS] = {0};
    int work[MAX_RESOURCE];
    int i, j, count = 0;

    // Initialize work vector with available resources
    for (i = 0; i < m; i++) {
        work[i] = available[i];
    }

    // Check if there is an unfinished process whose needs can be satisfied
    while (count < n) {
        int found = 0;  // Flag to break out of while loop if resources cannot be allocated to any process
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int canBeAllocated = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canBeAllocated = 0;
                        break;
                    }
                }
                if (canBeAllocated) {
                    // Allocate resources of the current process
                    for (j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1;
                    found = 1;
                    count++;
                }
            }
        }
        if (found == 0) {
            break; // No process found that can be allocated resources
        }
    }

    // Check if all processes were finished
    if (count < n) {
        return 0; // Deadlock occurred
    } else {
        return 1; // No deadlock
    }
}

int main() {
    int n, m;
    int allocation[MAX_PROCESS][MAX_RESOURCE];
    int maxDemand[MAX_PROCESS][MAX_RESOURCE];
    int available[MAX_RESOURCE];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the maximum demand matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &maxDemand[i][j]);
        }
    }

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int need[MAX_PROCESS][MAX_RESOURCE];
    calculateNeed(need, maxDemand, allocation, n, m);

    int safe = isSafe(available, maxDemand, allocation, need, n, m);

    if (safe) {
        printf("System is in safe state.\n");
    } else {
        printf("System is in unsafe state. Deadlock may occur.\n");
    }

    return 0;
}
