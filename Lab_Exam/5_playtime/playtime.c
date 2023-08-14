/*
Suppose you are the caretaker at a kindergarten that has received a unique toy, of which there is 
only one. In the kindergarten, there are n children (n>=2). In what way would you distribute this 
unique toy among the children so that each child is treated equally? 
*/

#include <stdio.h>
#include <stdlib.h>

struct Child {
    int id;      // Child's ID
    int playtime; // Remaining playtime for the toy
};

void roundRobin(int n, int quantum) {
    struct Child children[n];

    // Initialize the children
    for (int i = 0; i < n; ++i) {
        children[i].id = i + 1;
        children[i].playtime = quantum;
    }

    int remainingChildren = n;
    int currentPlayer = 0;

    printf("Distributing the unique toy using Round Robin scheduling...\n");

    while (remainingChildren > 0) {
        if (children[currentPlayer].playtime > 0) {
            printf("Child %d plays with the toy for %d minute(s).\n", children[currentPlayer].id, quantum);
            children[currentPlayer].playtime -= quantum;

            if (children[currentPlayer].playtime <= 0) {
                printf("Child %d has finished playing.\n", children[currentPlayer].id);
                remainingChildren--;
            }
        }

        currentPlayer = (currentPlayer + 1) % n; // Move to the next child
    }

    printf("Toy distribution complete!\n");
}

int main() {
    int n, quantum;

    // Input the number of children and the quantum (playtime per child)
    printf("Enter the number of children: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least 2 children are required.\n");
        return 1;
    }

    printf("Enter the playtime quantum (minutes per child): ");
    scanf("%d", &quantum);

    if (quantum <= 0) {
        printf("The playtime quantum must be positive.\n");
        return 1;
    }

    roundRobin(n, quantum);

    return 0;
}
