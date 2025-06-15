#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void jumpSearch(int arr[],int size,int x);
void mergeSort(int A[],int left,int right);
void merge(int A[],int left,int mid,int right);

//CHAT GPT
void jumpSearch(int arr[], int size, int x) {
    int block, step;
    block = (int)sqrt(size);  // Block size
    step = 0;
    int prev = 0;
    // Jump phase
    while (step < size && arr[step] < x) {
        prev = step;
        step += block;
        if (step >= size) {
            step = size - 1;  // Avoid stepping out of bounds
        }
    }
    // Linear search within the block
    while (prev < size && arr[prev] < x) {
        prev++;
    }
    // Check if element is found
    if (prev < size && arr[prev] == x) {
        printf("Value %d found at arr[%d]\n", x, prev);
    } else {
        printf("Value %d not found!\n", x);
    }
}

void merge(int A[],int left,int mid,int right){
    int n1 = (mid - left + 1);
    int n2 = (right - mid);

    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for (int i=0;i<n1;i++){
        L[i] = A[left + i];
    }

    for (int i=0;i<n2;i++){
        R[i] = A[mid + 1 + i];
    }

    int i=0,j=0,k=left;
    while(i < n1 && j < n2){
        if (L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k] = L[i];
        i++;
        k++;
    }

    while (j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int A[],int left,int right){
    if (left < right){
        int mid = left + (right - left)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid+1,right);
    merge(A,left,mid,right);
    }
    return;
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
    mergeSort(arr,0,size-1);

    printf("\nSorted array:");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};

    printf("\nEnter value to be search : ");
    scanf("%d",&target);
    jumpSearch(arr,size,target);
    return 0;
}

/*Jump search algorithems:  firstly array going sorted 
and then work*/
