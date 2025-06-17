#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mergeSort(int A[],int l,int r);
void merge(int A[],int l,int m,int r);

void merge(int A[],int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for(int i=0;i<n1;i++){
        L[i] = A[l+i];
    }
    for(int i =0;i<n2;i++){
        R[i] = A[m+1+i];
    }
    int i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
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

    while(j<n2){
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[],int l,int r){
    if (l<r){
        int m = (r + l )/2; //l+(r-l)/2;
        mergeSort(A,l,m);
        mergeSort(A,m+1,r);
        merge(A,l,m,r);
    }
}

int main(){
    srand(time(NULL));
    int nEle;
    printf("How many elements? : ");
    scanf("%d",&nEle);
    //Allocate memory
    int *A = (int *)malloc(nEle*sizeof(int));
    //Getting values
    for (int i=0;i<nEle;i++){
        A[i] = rand()%100;
    }
    //Print before sorting
    printf("Unsorted array\n");
    for (int i=0;i<nEle;i++){
        printf("%d ",A[i]);
    }
    //Sorting
    mergeSort(A,0,nEle-1);
    
    //print after sorting
    printf("\nSorted array\n");
    for(int i=0;i<nEle;i++){
        printf("%d ",A[i]);
    }
    return 0;
}