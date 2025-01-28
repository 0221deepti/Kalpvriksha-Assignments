// Bubble Sort
#include<stdio.h>

void bubble_sort(int array[], int n){
    for(int i = 0; i < n; i++){
        int swapped = 0;
        for(int j = 0; j < n - i - 1; j++){  
            if(array[j] > array[j + 1]){
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = 1;
            }
        }
        if(swapped == 0){
            break;
        }
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

    bubble_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);
    
    return 0;
}
