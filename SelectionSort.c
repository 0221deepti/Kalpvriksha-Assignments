// Selection Sort
#include<stdio.h>

void selection_sort(int array[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(array[j] < array[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
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

    selection_sort(array, n);

    printf("Sorted array: ");
    print_array(array, n);
    
    return 0;
}
