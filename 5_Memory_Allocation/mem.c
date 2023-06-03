#include <stdio.h>

#define MAX_BLOCKS 100
#define MAX_PROCESS 100

//Memory Block with its size and allocation status
typedef struct{
    int size;
    int allocated;
} mem_block;

//Process with its size and allocated memory block number.
typedef struct{
    int size;
    int block;
} process;

// Function implements the First Fit algorithm
void first_fit(mem_block mem_blocks[], int m, process p[], int n){
    
    //n=number of Memory Blocks
    //m=number of Processes
    int i, j;

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){       
            if (mem_blocks[j].allocated == 0 && mem_blocks[j].size >= p[i].size){
                mem_blocks[j].allocated = 1;
                p[i].block = j;
                break;
            }
        }
    }
}

//Function implements the Best Fit algorithm.
void best_fit(mem_block mem_blocks[], int m, process p[], int n){
    
    int i, j;
    int best_block; //Index of Best Memory Block

    for (i = 0; i < n; i++){

        // Initially the index of Best Block for a Process is -1
        best_block = -1;    

        for (j = 0; j < m; j++){
            
            if (mem_blocks[j].allocated == 0 && mem_blocks[j].size >= p[i].size){
                
                if (best_block == -1){
                    best_block = j;
                }
                else if (mem_blocks[best_block].size > mem_blocks[j].size){
                    best_block = j;
                }                 
            }
        }

        // if the process has a best block then it is allocated
        if (best_block != -1){
            mem_blocks[best_block].allocated = 1;
            p[i].block = best_block;
        }
    }
}

//Function implements the Worst Fit algorithm
void worst_fit(mem_block mem_blocks[], int m, process p[], int n){
    
    int i, j;
    int worst_block; //Index of Worst Memory Block

    for (i = 0; i < n; i++){

        //Initially the index of Worst Block for a Process is -1
        worst_block = -1;  

        for (j = 0; j < m; j++){

            if (mem_blocks[j].allocated == 0 && mem_blocks[j].size >= p[i].size){
                if (worst_block == -1){
                    worst_block = j;
                }            
                else if (mem_blocks[j].size > mem_blocks[worst_block].size){
                    worst_block = j;
                }            
            }
        }

        if (worst_block != -1){
            mem_blocks[worst_block].allocated = 1;
            p[i].block = worst_block;
        }
    }
}

//Function is used to print the allocation results
void print_allocation(mem_block mem_blocks[], int m, process p[], int n){

    printf("\nProc\tProc Size\tBlock\n");
    for (int i = 0; i < n; i++){

        printf("%d\t%d\t\t", i + 1, p[i].size);
        
        if (p[i].block != -1){
            printf("%d\n", p[i].block + 1);
        }        
        else{
            printf("Not Allocated\n");
        }       
    }
}

int main()
{
    int m, n;
    mem_block mem_blocks[MAX_BLOCKS];
    process p[MAX_PROCESS];

    printf("Enter the total number of Memory Blocks: ");
    scanf("%d", &m);

    printf("Enter the size of each block: \n");
    for (int i = 0; i < m; i++){
        printf("Memory Block %d: ",i+1);
        scanf("%d", &mem_blocks[i].size);
        mem_blocks[i].allocated = 0;
    }

    printf("Enter the total number of Processes: ");
    scanf("%d", &n);

    printf("Enter the size of each process: \n");
    for (int i = 0; i < n; i++){
        printf("Process %d: ",i+1);
        scanf("%d", &p[i].size);
        p[i].block = -1;
    }

    //options
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("Enter your choice: ");

    int choice;
    scanf("%d", &choice);

    switch (choice){
    case 1:
        first_fit(mem_blocks, m, p, n);
        break;
    case 2:
        best_fit(mem_blocks, m, p, n);
        break;
    case 3:
        worst_fit(mem_blocks, m, p, n);
        break;
    default:
        printf("Invalid choice\n");
        return 0;
    }

    print_allocation(mem_blocks, m, p, n);
    return 0;
}