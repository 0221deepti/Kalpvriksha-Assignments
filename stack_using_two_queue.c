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

void enqueue(Queue* queue, int data) {
    if (queue->size == queue->capacity) {
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
    queue->front++;
    queue->size--;
    return data;
}

int front(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    return queue->arr[queue->front];
}

int size(Queue* queue) {
    return queue->size;
}

typedef struct Stack {
    Queue* q1; 
    Queue* q2; 
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->q1 = createQueue(capacity);
    stack->q2 = createQueue(capacity);
    return stack;
}

void push(Stack* stack, int data) {
    enqueue(stack->q1, data);
    printf("Pushed %d onto the stack\n", data);
}

int pop(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->q1->size > 1) {
        int temp = dequeue(stack->q1);
        enqueue(stack->q2, temp);
    }

    int poppedElement = dequeue(stack->q1);
    // printf("Popped element is %d\n", poppedElement);
    Queue* tempQueue = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = tempQueue;

    return poppedElement;
}

int peek(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty\n");
        return -1;
    }

    while (stack->q1->size > 1) {
        int temp = dequeue(stack->q1);
        enqueue(stack->q2, temp);
    }
    int topElement = front(stack->q1);
    enqueue(stack->q2, dequeue(stack->q1));
    Queue* tempQueue = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = tempQueue;

    return topElement;
}

int stackSize(Stack* stack) {
    return size(stack->q1);
}

void displayStack(Stack* stack) {
    if (isEmpty(stack->q1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Elements in the stack:\n");
    for (int i = stack->q1->front; i <= stack->q1->rear; i++) {
        printf("%d ", stack->q1->arr[i]);
    }
    printf("\n");
}
int main() {
    int capacity = 100;
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
                if (isEmpty(stack->q1)) {
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
