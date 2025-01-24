#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int row;
    int col;
    int value;
    struct Node* next;
} Node;

Node* createNode(int row, int col, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
void insertNode(Node** head, int row, int col, int value) {
    Node* newNode = createNode(row, col, value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void printSparseMatrix(Node* matrix[], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        Node* current = matrix[i];
        int currentCol = 0;
        for (int j = 0; j < cols; j++) {
            if (current != NULL && current->col == j) {
                printf("%d ", current->value);
                current = current->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int rows = 4;
    int cols = 5;
    Node* matrix[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = NULL;
    }
 
    insertNode(&matrix[1], 1, 0, 1);
    insertNode(&matrix[1], 1, 3, 1);
    insertNode(&matrix[2], 2, 0, 3);
    insertNode(&matrix[2], 2, 2, 4);
    insertNode(&matrix[2], 2, 4, 5);
    printSparseMatrix(matrix, rows, cols);

    return 0;
}
