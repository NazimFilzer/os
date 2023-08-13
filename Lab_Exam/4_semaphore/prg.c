/*
Write a C program that simulates a traffic intersection with multiple lanes. 
The intersection consists of two perpendicular roads, each with multiple lanes. 
Each vehicle should approach the intersection, wait if it is not safe to proceed, 
and proceed once it is safe to cross the intersection without colliding with other vehicles.
 Ensure safe and efficient traffic flow.
*/

#include <stdio.h>
#include <stdlib.h>

// Function to perform a wait operation
int wait(int m) {
    m = m - 1;
    return m;
}

// Function to perform a signal operation
int signal(int k) {
    k = k + 1;
    return k;
}

int main() {
    int full = 0;   // Number of vehicles in the intersection
    int empty = 5;  // Maximum capacity of the intersection
    int mutex = 1;  // Mutex for synchronization
    int n;          // Number of vehicles approaching the intersection

    printf("Enter the number of vehicles\n");
    scanf("%d", &n);

    // Simulate each vehicle approaching the intersection
    for (int i = 1; i <= n; i++) {
        printf("Vehicle %d is approaching the intersection\n", i);

        // Critical section: Entering the intersection
        if (mutex == 1) {
            empty = wait(empty);
            mutex = wait(mutex);

            // Print a message indicating waiting vehicles
            if (i < n) {
                printf("Vehicles ");
                for (int j = i + 1; j <= n; j++) {
                    printf("%d", j);
                    if (j < n) {
                        printf(", ");
                    }
                }
                printf(" please wait.\n");
            }

            printf("Vehicle %d has crossed the intersection\n\n", i);

            mutex = signal(mutex);
            full = signal(full);
        }
    }

    return 0;
}
