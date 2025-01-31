#include<stdio.h>
#define MAX_SIZE 100

typedef struct {
    int array[MAX_SIZE];
    int front;
    int rear;
} Queue;

void init(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isempty(Queue* queue) {
    return (queue->front == -1);
}

int isfull(Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue* queue, int data) {
    if (isfull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (queue->front == -1) {
        queue->front = 0;  
    }
    queue->array[++(queue->rear)] = data;
    printf("Enqueued %d into queue\n", data);
}
int dequeue(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int num = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1; 
    } else {
        queue->front++;  
    }
    return num;
}
int peek(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->front];
}

int size(Queue* queue) {
    if (isempty(queue)) {
        return 0;
    }
    return queue->rear - queue->front + 1;
}

void display_queue(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    Queue queue;
    init(&queue);
    
    while (1) {
        int ch, data;
        printf("\nQueue Operations Menu\n");
        printf("Choose 1 to enqueue element into queue\n");
        printf("Choose 2 to dequeue element from queue\n");
        printf("Choose 3 to peek front element\n");
        printf("Choose 4 to check if queue is empty\n");
        printf("Choose 5 to check if queue is full\n");
        printf("Choose 6 to get size of queue\n");
        printf("Choose 7 to display queue elements\n");
        printf("Choose 8 to exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;
            case 2:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued %d from queue\n", data);
                }
                break;
            case 3:
                data = peek(&queue);
                if (data != -1) {
                    printf("Front element is %d\n", data);
                }
                break;
            case 4:
                if (isempty(&queue)) {
                    printf("Yes, queue is empty\n");
                } else {
                    printf("No, queue is not empty\n");
                }
                break;
            case 5:
                if (isfull(&queue)) {
                    printf("Yes, queue is full\n");
                } else {
                    printf("No, queue is not full\n");
                }
                break;
            case 6:
                printf("Queue size: %d\n", size(&queue));
                break;
            case 7:
                display_queue(&queue);
                break;
            case 8:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
