#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node)); 
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* insert_to_LL(Node* head, int data) {
    Node* new_node = newNode(data);
    if (head == NULL) {
        return new_node;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

int isPresent(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = newNode(new_data);
    Node* temp = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

Node* findUnion(Node* list1, Node* list2) {
    Node* result = NULL;

    Node* current1 = list1;
    while (current1 != NULL) {
        if (!isPresent(result, current1->data)) {
            append(&result, current1->data); 
        }
        current1 = current1->next;
    }

    Node* current2 = list2;
    while (current2 != NULL) {
        if (!isPresent(result, current2->data)) {
            append(&result, current2->data); 
        }
        current2 = current2->next;
    }

    return result;
}

Node* findIntersection(Node* list1, Node* list2) {
    Node* result = NULL;

    Node* current1 = list1;
    while (current1 != NULL) {
        if (isPresent(list2, current1->data) && !isPresent(result, current1->data)) {
            append(&result, current1->data);
        }
        current1 = current1->next;
    }

    return result;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n1, n2;
    printf("Enter number of elements in list1: ");
    scanf("%d", &n1);
    int num = 0;
    Node* head1 = NULL;
    Node* head2 = NULL;
    printf("Enter elements of list1:\n");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &num);
        head1 = insert_to_LL(head1, num);
    }

    printf("Enter number of elements in list2: ");
    scanf("%d", &n2);
    printf("Enter elements of list2:\n");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &num);
        head2 = insert_to_LL(head2, num);
    }

    Node* unionList = findUnion(head1, head2);
    Node* intersectionList = findIntersection(head1, head2);

    printf("Union: ");
    printList(unionList);

    printf("Intersection: ");
    printList(intersectionList);

    return 0;
}
