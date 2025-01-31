#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int stack[MAX];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX - 1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void enqueue(int data) {
    push(data); 
    printf("Enqueued %d into the queue\n", data);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int temp = pop(); 
    if (top == -1) {
        return temp;
    }
    int dequeuedValue = dequeue();
    push(temp);

    return dequeuedValue;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return -1;
    }

    int temp = pop();
    if (top == -1) {
        push(temp); 
        return temp;
    }
    
    int front = peek(); 
    push(temp); 
    
    return front;
}

int size() {
    return top + 1;
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements (front to rear): ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\nSelect your choice\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek Front Element\n");
        printf("4. Check if Queue is Empty\n");
        printf("5. Get Size of Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Front element: %d\n", data);
                }
                break;
            case 4:
                if (isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
            case 5:
                printf("Queue size: %d\n", size());
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
