#include <stdio.h> 
void printArray(int arr[], int n) { 
    for (int i=0; i<n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
void readArray(int arr[], int n) { 
    for (int i=0; i<n; i++) 
        scanf("%d", &arr[i]); 
     
} 
 
void swap(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
int partition(int arr[], int low, int high) { 
    int pivot = arr[low];  
    int i = low + 1; 
    int j = high; 
 
    while (1) { 
        
        while (i <= high && arr[i] <= pivot) { 
            i++; 
        } 
        
        while (j >= low && arr[j] > pivot) { 
            j--; 
        } 
 
        if (i < j) { 
            swap(&arr[i], &arr[j]); 
        } else { 
            break; 
        } 
    } 
     
    swap(&arr[low], &arr[j]); 
     
    return j;   
} 
 
void quicksort(int arr[], int low, int high) { 
    if (low < high) { 
        int pivotIndex = partition(arr, low, high); 
        quicksort(arr, low, pivotIndex - 1); 
        quicksort(arr, pivotIndex + 1, high); 
    } 
} 
 
int main() { 
    int arr[50] ; 
    int n; 
printf("Enter the number of elements \n"); 
scanf("%d",&n); 
printf("Enter the array elements\n"); 
readArray(arr,n); 
printf("Original array: "); 
printArray(arr, n); 
quicksort(arr,0,n-1); 
printf("Sorted array: "); 
printArray(arr, n); 
return 0; 
}