#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void init(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isempty(Queue* queue) {
    return (queue->front == NULL);
}
void enqueue(Queue* queue, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if (isempty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Enqueued %d into queue\n", data);
}

int dequeue(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL; 
    }
    free(temp);
    return data;
}

int peek(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->front->data;
}

int size(Queue* queue) {
    int count = 0;
    Node* temp = queue->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void display_queue(Queue* queue) {
    if (isempty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
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
        printf("Choose 5 to get size of queue\n");
        printf("Choose 6 to display queue elements\n");
        printf("Choose 7 to exit\n");
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
                printf("Queue size: %d\n", size(&queue));
                break;
            case 6:
                display_queue(&queue);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
}
