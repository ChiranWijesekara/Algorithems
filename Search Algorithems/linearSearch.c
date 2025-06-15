#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linearSearch(int A[],int length,int X){
    for(int i = 0;i<length;i++){
        if (A[i] == X){
            printf("Targeted value found at : A[%d]\n",i);
            return;
        }
    }
    printf("Not found!\n");
}

int main(){
    srand(time(NULL));
    int size;
    int target;
    printf("Enter the number of elements : ");
    scanf("%d",&size);
    int *arr = (int*)malloc(size*sizeof(int));

    for (int i=0;i<size;i++){
        arr[i] = rand()%100;
    }

    printf("Array : ");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};

    printf("\nEnter value to be search : ");
    scanf("%d",&target);
    linearSearch(arr,size,target);

    return 0;
}

/*Linear serach is speail one
its working one by one in array*/
