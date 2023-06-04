#include <stdio.h>

//Function to perform first fit allocation

void firstfit(int block[], int m, int process[], int n){
    //m=number of Memory Blocks
    //n=number of Processes
 
    // array to store the allocation information for each process
    int allocation[n];

    //initialize all elements of the array to -1, indicating that no allocation has been made.
    for (int i = 0; i < n; i++){
        allocation[i] = -1;
    }
    
    //Iterate over each process and find the first memory block that can accomodate it 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            //If the block has enough space
            if (block[j] >= process[i]){
                // allocate the process to that block
                allocation[i] = j;
                //reduce the available space in the block.
                block[j] -= process[i];
                //Break out of the inner loop to move to the next process.
                break;
            }
        }
    }
    
    printf("\nPNo\tPSize\tBlockNo");
    
    for (int i = 0; i < n; i++){
        
        printf("\n%d\t%d\t", i + 1, process[i]);
        
        if (allocation[i] != -1){
            printf("%d", allocation[i] + 1);
        }
        else{
            printf("Not Allocated");
        }
    }
    printf("\n");
}

int main(){
 
 int m, n;
 printf("Enter the no of blocks: ");
 scanf("%d", &m);
 
 int block[m];
 printf("Enter size of %d blocks: ",m);
 
 for (int i = 0; i < m; i++){
    scanf("%d ", &block[i]);
 }

 printf("Enter the no of processes: ");
 scanf("%d", &n);
 
 int process[n];
 printf("Enter size of %d processes: ",n);
 for (int i = 0; i < n; i++){
    scanf("%d ", &process[i]);
 }

 firstfit(block, m, process, n);
}