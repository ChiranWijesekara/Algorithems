//How to working thiss going down for get instructions
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergeSort(int A[],int l,int r);
void merge(int A[],int l,int m,int r);
// Function to find the first occurrence of the target element
int findFirst(int A[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r) / 2;

        // Check if mid is the first occurrence of x
        if ((mid == 0 || A[mid - 1] < x) && A[mid] == x) {
            return mid;
        }
        // Search left half if the current element is greater or equal
        else if (A[mid] >= x) {
            return findFirst(A, l, mid - 1, x);
        }
        // Otherwise, search the right half
        else {
            return findFirst(A, mid + 1, r, x);
        }
    }
    return -1;  // Return -1 if not found
}

// Function to find the last occurrence of the target element
int findLast(int A[], int l, int r, int x) {
    if (r >= l) {
        int mid = (l + r) / 2;

        // Check if mid is the last occurrence of x
        if ((mid == r || A[mid + 1] > x) && A[mid] == x) {
            return mid;
        }
        // Search the right half if the current element is smaller or equal
        else if (A[mid] <= x) {
            return findLast(A, mid + 1, r, x);
        }
        // Otherwise, search the left half
        else {
            return findLast(A, l, mid - 1, x);
        }
    }
    return -1;  // Return -1 if not found
}

// Function to find all occurrences of the target element
void findAllOccurrences(int A[], int n, int x) {
    int first = findFirst(A, 0, n - 1, x);
    if (first == -1) {
        printf("No matches found for %d\n", x);
        return;
    }
}

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
    free(L);
    free(R);
}

void mergeSort(int A[],int l,int r){
    if (l<r){
        int m = l+(r-l)/2;
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

    int x;
    printf("\nEnter value to be searched : ");
    scanf("%d",&x);
    findAllOccurrences(A,nEle,x);

    return 0;
}

//UBIQUITOUS BINARY SEARCH
/*
> Make sure array is sorted
> Make sure that high and low are not consecutive (high - low)>1
> mid = (high - low) / 2
> if value[mid] <= target : low mid (select second half)
    else : low high(select first half)
> if high - low == 1: stop iteration
    check values[high] == target or values[low] == target
*/
