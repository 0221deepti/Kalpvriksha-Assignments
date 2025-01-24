#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;         
    struct Node* next; 
} Node;

typedef struct Stack {
    Node* top; 
} Stack;

void initStack(Stack* stack) {
    stack->top = NULL; 
}

void push(Stack* stack, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = stack->top; 
    stack->top = newNode;      
    printf("Pushed %d onto the stack.\n", data);
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return -1; 
    }

    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);                 
    printf("Popped %d from the stack.\n", poppedValue);
    return poppedValue;
}

int peek(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty. Cannot peek.\n");
        return -1; 
    }
    return stack->top->data; 
}

int isEmpty(Stack* stack) {
    return stack->top == NULL; 
}
int size(Stack* stack) {
    int count = 0;
    Node* current = stack->top;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

void printStack(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int main() {
    Stack stack;
    initStack(&stack); 
    int n;
    printf("enter number of operations:\n");
    scanf("%d",&n);
    printf("select valid choice from 1 to 4\n");
    printf("Select 1 for push operation\n");
    printf("Select 2 for pop operation\n");
    printf("Select 3 for peek operation\n");
    printf("Select 4 for to check stack is empty or not\n");
    int value;
    while(n--){
        int op;
        printf("select valid choice from 1 to 4\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            printf("Enter value to push\n");
            scanf("%d",&value);
            push(&stack,value);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            printf("Top element:%d\n",peek(&stack));
            break;
        case 4:
            if (isEmpty(&stack)) {
            printf("Stack is empty\n");
            } 
            else {
            printf("Stack is not empty\n");
            }
            break;
        default:
            printf("Select valid operation\n");
            break;
        }
        printStack(&stack);
    }
    return 0;
}
