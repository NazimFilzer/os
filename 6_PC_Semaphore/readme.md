# Producer-Consumer Problem
===========================

This program demonstrates the solution to the classic Producer-Consumer problem using synchronization mechanisms such as semaphores. The producer-consumer problem involves two processes, a producer and a consumer, that share a common buffer. The producer produces items and places them into the buffer, while the consumer consumes items from the buffer.

## Introduction
The producer-consumer problem is a classic synchronization problem in computer science. It highlights the challenges of coordinating access to a shared resource between multiple processes. In this problem, the producer produces data items and adds them to a buffer, while the consumer consumes items from the buffer. The goal is to ensure that the producer and consumer processes do not interfere with each other and that the buffer remains in a consistent state.

## Algorithm
1. Start by initializing the semaphore variables: mutex = 1 (to control access to the buffer), empty = 2 (to track the number of empty slots in the buffer), and full = 0 (to track the number of filled slots in the buffer).
2. Define the wait(S) function, which waits until the semaphore S becomes positive and then decrements its value by 1. This function ensures that a process waits when the required condition is not satisfied.
3. Define the signal(S) function, which increments the value of semaphore S by 1. This function releases the waiting process and allows it to proceed.
4. Implement the producer() function, which represents the behavior of the producer process. It first acquires the mutex using the wait(mutex) operation. Then, it signals that an item has been produced by incrementing the value of full and releases a slot in the buffer by performing wait(empty). Finally, it updates the count and releases the mutex using signal(mutex).
5. Implement the consumer() function, which represents the behavior of the consumer process. It acquires the mutex using the wait(mutex) operation. Then, it waits for a filled slot in the buffer by performing wait(full) and consumes an item. After that, it signals that an empty slot is available by incrementing the value of empty. Finally, it releases the mutex using signal(mutex).
6. In the main function, display a menu with options for the user to choose from: producer, consumer, or exit.
7. Inside an infinite loop, read the user's choice and execute the corresponding functionality based on the selected option.
8. If the user selects the producer option and the buffer is not full (mutex == 1 and empty != 0), call the producer() function.
9. If the user selects the consumer option and the buffer is not empty (mutex == 1 and full != 0), call the consumer() function.
10. If the user selects the exit option, terminate the program.
11. Repeat the loop to allow the user to perform multiple operations.
12. End the program.

## Program Explanation
1. The program starts by initializing the semaphore variables: mutex, empty, and full.
2. It defines the wait(S) and signal(S) functions, which are used for synchronization.
3. The producer() function represents the behavior of the producer process. It acquires the mutex, signals that an item has been produced, and releases an empty slot in the buffer.
4. The consumer() function represents the behavior of the consumer process. It acquires the mutex, waits for a filled slot in the buffer, consumes an item, and signals an empty slot in the buffer.
5. In the main function, a menu is displayed for the user to choose the producer or consumer option, or to exit the program.
6. Based on the user's choice, the corresponding function is called if the buffer has available slots or items.
7. The program continues to display the menu and execute the selected

 option until the user chooses to exit.

The program implements the producer-consumer problem using semaphores to control access to the shared buffer. It ensures that the producer and consumer processes do not interfere with each other and that the buffer remains in a consistent state.