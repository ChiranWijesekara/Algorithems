
//INTERPOLATION SEARCH


/*
> Interval between elements should be uniform
> Sorted elements
> Formula to find Pos = Lo + ((Hi - Lo)/(A[Hi] - A[Lo])) * (X - A[Lo])
        
                 (Hi - Lo)
pos  = Lo + ------------------- x (X - A[Lo])
              (A[Hi] - A[Lo])

> Time Complexity:
    O(log2(log2 n)) - for the average case
    O(n)            - for the worst case
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int iteration_counter = 0;
void interpolationSearch(int A[],int Hi, int Lo ,int target){
    int pos;
    if(Lo <= Hi && target >= A[Lo] && target <= A[Hi]){
        pos = Lo + (((double)(Hi - Lo) / (A[Hi] - A[Lo]))*(target - A[Lo]));
        if (A[pos] == target){
            iteration_counter++;
            printf("Targetd located at %d index\n",pos);
            printf("Iterations : %d\n",iteration_counter);
            return;
        }
        if (A[pos] < target){
            iteration_counter++;
            interpolationSearch(A,Hi,pos+1,target);
            return;
        }
        if (A[pos] > target){
            iteration_counter++;
            interpolationSearch(A,pos,Lo,target);
            return;
        }
    }
    printf("Not found!\n");
    printf("Iterations : %d\n",iteration_counter);
}

void merge(int A[],int L,int mid,int R){
    int n1 = (mid - L + 1); 
    int n2 = (R - mid);
    int *Left_A = (int*)malloc(n1 * sizeof(int));
    int *Right_A = (int*)malloc(n2 * sizeof(int));
    for (int i = 0;i<n1;i++){
        Left_A[i] = A[L + i];
    }
    for (int i = 0 ; i<n2 ;i++){
        Right_A[i] = A[mid + 1 + i];
    }
    int  i = 0, j = 0, k = L;
    while(i<n1 && j < n2){
        if (Left_A[i] < Right_A[j]){
            A[k] = Left_A[i];
            i++;
        }else{
            A[k] = Right_A[j];
            j++; 
        }
        k++;
    }
    while(i<n1){
        A[k] = Left_A[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k] = Right_A[j];
        j++;
        k++;
    }
    free(Left_A);
    free(Right_A);
}

void mergeSort(int A[],int L,int R){
    if(L<R){
        int mid = L + (R - L)/2;
        mergeSort(A,L,mid);
        mergeSort(A,mid+1,R);
        merge(A,L,mid,R);
    }
}

int main(){
    srand(time(NULL));
    int size;
    printf("Enter Size : ");
    scanf("%d",&size);
    int *A = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++){ A[i] = rand()%1000 + 1;}
    printf("Unsorted array : ");
    for (int i = 0; i < size;i++){printf("%d ",A[i]);};
    printf("\n");
    
    mergeSort(A,0,size-1);

    printf("Sorted array : ");
    for (int i = 0; i < size;i++){printf("%d ",A[i]);};
    printf("\n");
    int target;
    printf("Enter value to search : ");
    scanf("%d",&target);
    
    interpolationSearch(A,size-1,0,target);
    
    return 0;
}