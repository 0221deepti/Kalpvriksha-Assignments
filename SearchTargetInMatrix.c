/*
SEARCH IN 2D MATRIX
You are given an m x n integer matrix matrix with the following two properties:
Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.
You must write a solution in O(log(m * n)) time complexity.
*/
//Solution
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool binary_search(int* matrix,int matrixSize,int target){
    int s=0;
    int e=matrixSize-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(matrix[mid]==target) return 1;
        else if(matrix[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }

return 0;
}
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
   int row=-1;
    for(int i=0;i<matrixSize;i++){
            if(matrix[i][0]<=target && target<=matrix[i][*matrixColSize-1]){
                row=i;
                break;
            }
    }
    if(row==-1) return 0;
   return binary_search(matrix[row],*matrixColSize,target);
}
int main() {
    int rows, cols, target;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Enter the target value: ");
    scanf("%d", &target);

    if (searchMatrix(matrix, rows, &cols, target)) {
        printf("Target %d found in the matrix.\n", target);
    } else {
        printf("Target %d not found in the matrix.\n", target);
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
