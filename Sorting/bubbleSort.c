#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *A, int x, int y) {
    int temp = A[x];
    A[x] = A[y];
    A[y] = temp;
}

/*
//Type 1
void bubbleSort(int A[], int length) {
    for (int i = length - 1; i > 0 ; i--) {
        for (int j = 0; j < i; j++) {
            if (A[j] > A[j+1]) {
                swap(A, j, j+1);
            }
        }
    }
}
*/

//Base model
void bubbleSort(int A[],int length){
    int temp;
    for (int i = 0;i<length; i++){
        for (int j = 0; j < length; j++){
            if (A[j] > A[j + 1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

//Type 2
/*
void bubbleSort(int A[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = length - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                swap(A, j, j-1);
            }
        }
    }
}
*/

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
    
    bubbleSort(arr,size);

    printf("\nSorted array:");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};
}