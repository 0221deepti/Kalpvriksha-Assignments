// Two pointer search
#include <stdio.h>

int two_pointer_search(int array[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        if (array[left] == key) {
            return left; 
        }
        if (array[right] == key) {
            return right; 
        }
        left++;
        right--;
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
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    int key;
    printf("Enter the key element to search:");
    scanf("%d", &key);

    int result = two_pointer_search(array, n, key);
    if (result != -1) {
        printf("%d found at index:%d\n", key, result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
