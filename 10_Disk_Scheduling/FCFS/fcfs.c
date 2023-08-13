#include <stdio.h>
#include <math.h>

int main(){

    // Reading total number of processes
    int p = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &p);

    // Reading the disk request
    int disk_queue[p];
    printf("Enter the disk queue: ");
    for (int i = 0; i < p; i++)
        scanf("%d", &disk_queue[i]);

    // Reading the initial position of Disk Head
    int head = 0;
    printf("Enter the starting position of head: ");
    scanf("%d", &head);

    // Calculating Total head movement
    int total_head_movement = 0;
    for (int i = 0; i < p; i++)
    {
        total_head_movement += abs(head - disk_queue[i]);
        head = disk_queue[i];
        printf("%d ", head);
    }

    printf("\nTotal head movement: %d\n", total_head_movement);

    return 0;
}