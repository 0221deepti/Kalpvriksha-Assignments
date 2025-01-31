// stack implementation using linked list
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* newNode(int data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

typedef struct Stack{
    Node* head;
}Stack;

void init(Stack *stack){
    stack->head=NULL;
}

int isempty(Stack *stack){
    return stack->head==NULL;
}
void push(Stack *stack,int data){
    Node* new_node=newNode(data);
    if (!new_node) {
        printf("\nStack Overflow");
        return;
    }
    new_node->next=stack->head;
    stack->head=new_node;
    printf("Successfully pushed");
}

void pop(Stack* stack){
    if(isempty(stack)){
        printf("Stack is empty");
        return;
    }
    else{
        Node* temp=stack->head;
        stack->head=stack->head->next;
        free(temp);
    }
    printf("Successfully popped");
}
void peek(Stack* stack) {
    if(isempty(stack)){
        printf("Stack is empty\n");
        return;
    }
    printf("top element:%d\n",stack->head->data);
    return;
}
void display_stack(Stack* stack){
    if(isempty(stack)){
        printf("Stack is empty\n");
        return;
    }
    else{
        Node* temp=stack->head;
        while(temp){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
void sizeOf(Stack* stack){
    if(isempty(stack)){
        printf("Stack is empty\n");
        return;
    }
    Node* temp=stack->head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Size of stack: %d\n",count);

}
int main() {
    Stack stack;
    init(&stack);
    while(1){
        int ch;
        int data;
        printf("Operation Menu\n");
        printf("Choose 1 to push element into stack\n");
        printf("Choose 2 to pop element into stack\n");
        printf("Choose 3 for peek operation\n");
        printf("Choose 4 to check stack is empty\n");
        printf("Choose 5 to get size of stack\n");
        printf("Choose 6 to get elements of stack (Display)\n");
        printf("Choose 7 to exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch (ch){
            case 1:
            printf("Enter data to insert\n");
            scanf("%d",&data);
            push(&stack,data);
            break;
            
            case 2:
            pop(&stack);
            break;

            case 3:
            peek(&stack);
            break;

            case 4:
            if(isempty(&stack)){
                printf("Yes stack is empty\n");
            }
            else{
                printf("No stack is not empty\n");
            }
            break;

            case 5:
            sizeOf(&stack);
            break;

            case 6:
            display_stack(&stack);
            break;

            case 7:
            return 0;

            default:
            printf("invalid choice\n");
            break;
        }
    }
}
