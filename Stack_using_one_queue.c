#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* arr;
    int front, rear, size, capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->size = 0;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(Queue* queue) {
    return queue->size == 0;
}

int isFull(Queue* queue) {
    return queue->size == queue->capacity;
}

void enqueue(Queue* queue, int data) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {  
        queue->front = 0;
    }
    queue->arr[++(queue->rear)] = data;
    queue->size++;
}

int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    for (int i = queue->front; i < queue->rear; i++) {
        queue->arr[i] = queue->arr[i + 1];
    }
    queue->rear--;
    queue->size--;
    return data;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->arr[queue->front];
}

int size(Queue* queue) {
    return queue->size;
}

typedef struct Stack {
    Queue* queue;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->queue = createQueue(capacity);
    return stack;
}

void push(Stack* stack, int data) {
    enqueue(stack->queue, data);
    int n = size(stack->queue);
    for (int i = 0; i < n - 1; i++) {
        int temp = dequeue(stack->queue);
        enqueue(stack->queue, temp);
    }
    printf("Pushed %d onto the stack\n", data);
}

int pop(Stack* stack) {
    if (isEmpty(stack->queue)) {
        printf("Stack is empty\n");
        return -1;
    }
    return dequeue(stack->queue);
}

int peek(Stack* stack) {
    if (isEmpty(stack->queue)) {
        printf("Stack is empty\n");
        return -1;
    }
    return front(stack->queue);
}

int stackSize(Stack* stack) {
    return size(stack->queue);
}

void displayStack(Stack* stack) {
    if (isEmpty(stack->queue)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack (top to bottom):\n");
    for (int i = stack->queue->front; i <= stack->queue->rear; i++) {
        printf("%d ", stack->queue->arr[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 20;
    Stack* stack = createStack(capacity);

    while (1) {
        int ch, data;
        printf("\nStack Operations Menu\n");
        printf("Choose 1 to push element into stack\n");
        printf("Choose 2 to pop element from stack\n");
        printf("Choose 3 to peek top element\n");
        printf("Choose 4 to check if stack is empty\n");
        printf("Choose 5 to get size of stack\n");
        printf("Choose 6 to display stack elements\n");
        printf("Choose 7 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Popped element is %d\n", data);
                }
                break;
            case 3:
                data = peek(stack);
                if (data != -1) {
                    printf("Top element is %d\n", data);
                }
                break;
            case 4:
                if (isEmpty(stack->queue)) {
                    printf("Yes, stack is empty\n");
                } else {
                    printf("No, stack is not empty\n");
                }
                break;
            case 5:
                printf("Stack size is %d\n", stackSize(stack));
                break;
            case 6:
                displayStack(stack);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}
