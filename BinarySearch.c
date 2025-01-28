// Binary Search
#include<stdio.h>

int binary_search(int array[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (array[mid] == key) {
            return mid; 
        }
        if (array[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1; 
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("array is empty\n");
        return 0;
    }
    
    int array[10000];
    printf("Enter array sorted elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = binary_search(array, n, key);
    if (result != -1) {
        printf("%d found at index: %d\n", key, result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
