#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* table[TABLE_SIZE];
} HashMap;

Node* newNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

void initHashMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        map->table[i] = NULL;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}
void insert(HashMap* map, int key, int value) {
    int index = hash(key);
    Node* new_node = newNode(key, value);
    
    Node* current = map->table[index];
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            free(new_node);
            printf("Key %d new value updated %d\n", key, value);
            return;
        }
        current = current->next;
    }
    
    new_node->next = map->table[index];
    map->table[index] = new_node;
    printf("Key %d inserted and value is %d\n",key,value);
}

void search(HashMap* map, int key) {
    int index = hash(key);
    Node* current = map->table[index];
    
    while (current != NULL) {
        if (current->key == key) {
            printf("Value for key %d is %d\n", key, current->value);
            return;
        }
        current = current->next;
    }
    
    printf("Key %d not found\n", key);
}

void delete(HashMap* map, int key) {
    int index = hash(key);
    Node* current = map->table[index];
    Node* prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {  
                map->table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Key %d deleted\n", key);
            return;
        }
        prev = current;
        current = current->next;
    }
    
    printf("Key %d not found\n", key);
}


void display(HashMap* map) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = map->table[i];
        if (current != NULL) {
            printf("Index %d: ", i);
            while (current != NULL) {
                printf("(%d, %d) -> ", current->key, current->value);
                current = current->next;
            }
            printf("NULL\n");
        }
    }
}

int main() {
    HashMap map;
    initHashMap(&map);
    
    int choice, key, value;
    
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert (Put)\n");
        printf("2. Search (Get)\n");
        printf("3. Delete (Remove)\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:  
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(&map, key, value);
                break;
            case 2:  
                printf("Enter key: ");
                scanf("%d", &key);
                search(&map, key);
                break;
            case 3: 
                printf("Enter key: ");
                scanf("%d", &key);
                delete(&map, key);
                break;
            case 4: 
                display(&map);
                break;
            case 5:
                printf("Exit.......\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    
    return 0;
}
