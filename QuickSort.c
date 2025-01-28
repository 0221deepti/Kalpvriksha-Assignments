// Quick Sort
#include<stdio.h>
int partition(int array[], int low, int high) {
    int pivot = array[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++; 
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quick_sort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort(array, low, pi - 1);
        quick_sort(array, pi + 1, high);
    }
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    int array[10000]; 
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("Unsorted array: ");
    print_array(array, n);
    
    quick_sort(array, 0, n - 1);

    printf("Sorted array: ");
    print_array(array, n);
    
    return 0;
}
