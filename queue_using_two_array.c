#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int stack1[MAX];
int stack2[MAX];
int top1 = -1, top2 = -1;
int count = 0;

void push1(int data) {
    if (top1 == MAX - 1) {
        printf("Overflow in Stack1\n");
        return;
    }
    stack1[++top1] = data;
}

void push2(int data) {
    if (top2 == MAX - 1) {
        printf("Overflow in Stack2\n");
        return;
    }
    stack2[++top2] = data;
}

int pop1() {
    if (top1 == -1) {
        printf("Underflow in Stack1\n");
        return -1;
    }
    return stack1[top1--];
}
int pop2() {
    if (top2 == -1) {
        printf("Underflow in Stack2\n");
        return -1;
    }
    return stack2[top2--];
}

void enqueue(int data) {
    push1(data); 
    count++;
    printf("Enqueued %d into the queue\n", data);
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }
    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    int dequeued = pop2(); 
    count--;
    printf("Dequeued %d from the queue\n", dequeued);
}

void peek() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (top2 == -1) {
        while (top1 != -1) {
            push2(pop1());
        }
    }

    printf("Front element is %d\n", stack2[top2]);
}

int size() {
    return count;
}

int isEmpty() {
    return count == 0;
}
void displayQueue() {
    if (top1 == -1 && top2 == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements :\n");
    for (int i = top2; i >= 0; i--) {
        printf("%d ", stack2[i]);
    }

    for (int i = 0; i <= top1; i++) {
        printf("%d ", stack1[i]);
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
        printf("5. Size of Queue\n");
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
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    printf("Yes, the queue is empty\n");
                } else {
                    printf("No, the queue is not empty\n");
                }
                break;
            case 5:
                printf("Queue size is %d\n", size());
                break;
            case 6:
                displayQueue();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
