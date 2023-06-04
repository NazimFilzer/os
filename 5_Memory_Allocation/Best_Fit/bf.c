#include <stdio.h>

//Function to perform best fit
void bestfit(int block[], int m, int process[], int n){
    
    int bestBlock; //index of best memory block

    // array to store the allocation information for each process
    int allocation[n];  
    for(int i=0;i<n;i++){
        //initialize all elements of the array to -1, indicating that no allocation has been made.
        allocation[i]=-1;
    }

    //Iterate over each process and find the best memory block that can accomodate it
    for(int i=0;i<n;i++){

        bestBlock=-1; //initially no bestBlock found
        
        for(int j=0;j<m;j++){
            
            if(block[j]>=process[i]){

                if(bestBlock==-1){
                    bestBlock=j;
                }
                else if(block[j]<block[bestBlock]){
                    bestBlock=j;
                }
            }
        }
        
        //If bestBlock is still uninitialized (-1), no block was found to fit the process. 
        //Skip allocation for such process.

        //allocate the process to the best fitting block,
        if(bestBlock!=-1){
            allocation[i]=bestBlock;
            block[bestBlock]-=process[i];
        }
    }

    printf("\nPNo\tPSize\tBlockNo");
    
    for(int i=0;i<n;i++){
        printf("\n%d\t%d\t",i+1,process[i]);
        
        if(allocation[i]!=-1){
            printf("%d",allocation[i]+1);
        }
        else{
            printf("Not Allocated");
        }
    }
    printf("\n");
}

int main(){
    int m,n;
    printf("Enter the no of blocks: ");
    scanf("%d",&m);
    
    int block[m];
    printf("Enter size of %d blocks: ",m);
    for(int i=0;i<m;i++){
        scanf("%d",&block[i]);
    }

    printf("Enter the no of processes: ");
    scanf("%d",&n);
    int process[n];
    printf("Enter size of %d processes: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    bestfit(block,m,process,n);
}