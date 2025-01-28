// Question on Linked List
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* NewNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = NewNode(data);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = NewNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = NewNode(data);
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Invalid Position \n");
        return head;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteNode(Node* head, int value) {
    Node* temp = head;
    Node* prev = NULL;
    
    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return head;
    }
    
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Element not found\n");
        return head;
    }
    
    prev->next = temp->next;
    free(temp);
    return head;
}

void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int linearSearch(Node* head, int key) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1; 
}

void bubbleSort(Node* head) {
    if (head == NULL) return;
    int swapped;
    Node* ptr1;
    Node* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}
void insertionSortDescending(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* sorted = NULL;
    Node* current = *head;
    
    while (current != NULL) {
        Node* next = current->next;
        
        if (sorted == NULL || sorted->data <= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data > current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    
    *head = sorted;
}

void insertionSort(Node** head) {
    if (*head == NULL || (*head)->next == NULL) return;

    Node* sorted = NULL;
    Node* current = *head;
    
    while (current != NULL) {
        Node* next = current->next;
        
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    
    *head = sorted; 
}

Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node* mergedHead = NULL;
    if (list1->data <= list2->data) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }

    Node* mergedTail = mergedHead;
    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            mergedTail->next = list1;
            list1 = list1->next;
        } else {
            mergedTail->next = list2;
            list2 = list2->next;
        }
        mergedTail = mergedTail->next;
    }
    if (list1 != NULL) {
        mergedTail->next = list1;
    } else {
        mergedTail->next = list2;
    }
    return mergedHead;
}

void mergeAndDisplay(Node* head) {
    Node* list2 = NULL;
    int n, data;
    printf("Enter the number of elements in the second list: ");
    scanf("%d", &n);
    printf("Enter the elements for the second list:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        list2 = insertAtEnd(list2, data);
    }
    head = mergeLists(head, list2);

    printf("The merged list is: ");
    displayList(head);
}

int main() {
    Node* head = NULL;
    int choice, data, position;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Element\n");
        printf("5. Display List\n");
        printf("6. Linear Search\n");
        printf("7. Bubble Sort\n");
        printf("8. Insertion Sort\n");
        printf("9. Merge Two Lists\n");
        printf("10. Sort in Descending order\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                head = deleteNode(head, data);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Enter element to search: ");
                scanf("%d", &data);
                int index = linearSearch(head, data);
                if (index != -1) {
                    printf("Element found at index %d\n", index);
                } else {
                    printf("Element not found\n");
                }
                break;
            case 7:
                bubbleSort(head);
                printf("List sorted using Bubble Sort\n");
                break;
            case 8:
                insertionSort(&head);
                printf("List sorted using Insertion Sort\n");
                break;
            case 9:
                mergeAndDisplay(head);
                break;
            case 10:
                insertionSortDescending(&head);
                printf("List sorted in Descending order\n");
                break;
            case 11:
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
