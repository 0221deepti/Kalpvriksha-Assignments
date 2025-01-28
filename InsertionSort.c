// Insertion Sort
#include<stdio.h>
void insertion_sort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}
void print_array(int array[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    
    int array[10000];
    printf("Enter array elements\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    
    printf("Unsorted array: ");
    print_array(array, n);

    insertion_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);
    
    return 0;
}
