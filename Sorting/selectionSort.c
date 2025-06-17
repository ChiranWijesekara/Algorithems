//SELECTION SORT

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int A[],int min,int i){
    int temp = A[i];
    A[i] = A[min];
    A[min] = temp;
}

void selectionSort(int A[],int length){
    int i,j,min;
    for( i =0;i<length-1;i++){
        for ( j = i+1,min = i; j<length; j++ ){
            if (A[j]<A[min]){
                min = j;
            }
        }
        swap(A,min,i);
    }
}

/*
වමේ තියෙන එකෙන් පටන් ගන්නව , එ තෝරගන්න එකට දකුනෙන් තියෙන හැම 
element එකක්ම check කරල දකුනෙන් තියෙන පොඩිම එකත් එක්ක එක මාරූ කරනව
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
    
    selectionSort(arr,size);

    printf("\nSorted array:");
    for (int i=0;i<size;i++){printf("%d ",arr[i]);};
    return 0;
}



