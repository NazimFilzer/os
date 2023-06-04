#include <stdio.h> 

void worstfit(int block[], int m, int process[], int n) { 
 int worstBlock; 

 int allocation[n]; 

 for (int i = 0; i < n; i++) { 
    allocation[i] = -1; 
 } 


 for (int i = 0; i < n; i++) { 
    worstBlock = -1; 
    for (int j = 0; j < m; j++) { 
        if (block[j] >= process[i]) { 
            if (worstBlock == -1) { 
                worstBlock = j; 
            } 
            else if (block[j] > block[worstBlock]) { 
                worstBlock = j; 
            } 
        } 
    } 
    
    if (worstBlock != -1) { 
        allocation[i] = worstBlock; 
        block[worstBlock] -= process[i]; 
    } 
 } 

 printf("\nPNo\tPSize\tBlockNo"); 
 for (int i = 0; i < n; i++) { 
    printf("\n%d\t%d\t", i + 1, process[i]); 
    if (allocation[i] != -1) { 
        printf("%d", allocation[i] + 1); 
    } 
    else { 
        printf("Not Allocated"); 
    } 
 } 
 printf("\n"); 
}


int main() { 
 
 int m, n; 
 
 printf("Enter the no of blocks: "); 
 scanf("%d", &m); 
 int block[m]; 
 
 printf("Enter size of %d blocks: ",m); 
 for (int i = 0; i < m; i++) { 
    scanf("%d", &block[i]); 
 } 

 printf("Enter the no of processes: "); 
 scanf("%d", &n); 
 int process[n]; 

 printf("Enter size of %d processes: ",n); 
 for (int i = 0; i < n; i++) { 
    scanf("%d", &process[i]); 
 } 
 
 worstfit(block, m, process, n); 
} 
