#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
pivot එකක් තෝරගෙන එක්කට වඩා අඩු values වමට දානව, වැඩි ඒව දකුනට දානව. අතර මැදට pivot එක දානව.
*/

void swap(int A[],int left,int right){
    int temp = A[left];
    A[left] = A[right];
    A[right] = temp;
    return;
}


int partition(int A[],int left,int right,int pivot){
    printf("\n*");
    int pivotValue = A[pivot];
    swap(A,pivot,right);
    int storeIndex = left;
    for (int i = left;i < right; i++){
        if(A[i] < pivotValue){
            swap(A,storeIndex,i);
            storeIndex++;
        }
    }
    swap(A,storeIndex,right);
    return storeIndex;
}

void quickSort(int A[],int left,int right){
    printf("\n=");
    if (left < right){
        int pivot = (left + right)/2;
        int newpivot = partition(A,left,right,pivot);
        quickSort(A,left,newpivot-1);
        quickSort(A,newpivot+1,right);
    }
}

int main(){
    srand(time(NULL));
    int size;
    printf("Enter the number of elements : ");
    scanf("%d",&size);
    int *A = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++){A[i] = rand()%100+1;}
    
    printf("Unsorted array : ");
    for (int i = 0; i < size; i++){printf("%d ",A[i]);}
    
    quickSort(A,0,size-1);
    
    printf("\nSorted array : ");
    for (int i = 0; i < size; i++){printf("%d ",A[i]);}
    free(A);
    return 0;
}