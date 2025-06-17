//INSERTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int A[],int length){
    int temp;
    int j;
    for (int i = 1;i<length ; i++){
        temp = A[i];
        for (j = i ; j > 0 && temp < A[j-1] ; j--){
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
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

    printf("Unsorted array:");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};
    
    insertionSort(arr,size);

    printf("\nSorted array:");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};
}