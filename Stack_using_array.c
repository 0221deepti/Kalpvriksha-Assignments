#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 10
typedef struct {
    int array[MAX_SIZE];
    int top;
}Stack;

void init(Stack *stack){
    stack->top=-1;
}
bool isFull(Stack *stack){
    return stack->top==MAX_SIZE-1;
}
bool isempty(Stack *stack){
    return stack->top==-1;
}
void push(Stack *stack,int data){
    if(isFull(stack)){
        printf("Stack is FULL (Stack Overflow)\n");
        return;
    }
    stack->array[++(stack->top)]=data;
    printf("Pushed successfully\n");
}

void pop(Stack *stack){
    if(isempty(stack)){
        printf("Stack is empty\n");
        return;
    }
    stack->top--;
    printf("popped sucessfully\n");
}

void peek(Stack *stack){
    if(isempty(stack)){
        printf("Stack is empty\n");
        return;
    }
    printf("peek element is %d\n",stack->array[stack->top]);
    return;
}

void sizeOf(Stack *stack){
    printf("Size of stack is %d\n",stack->top +1);
}
void display_stack(Stack *stack){
    if(isempty(stack)){
       printf("Stack is empty\n");
        return; 
    }
    for(int i=0;i<=stack->top;i++){
        printf("%d ",stack->array[i]);
    }
    printf("\n");
}
int main(){
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
        printf("Choose 5 to check stack is full\n");
        printf("Choose 6 to get size of stack\n");
        printf("Choose 7 to get elements of stack\n");
        printf("Choose 8 to exit\n");
        printf("Enter your choice:\n");
        scanf("%d",&ch);
        switch (ch)
        {
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
            if(isFull(&stack)){
                printf("Yes stack is full\n");
            }
            else{
                printf("No, stack is not full\n");
            }
            break;
        case 6:
            sizeOf(&stack);
            break;
        case 7:
            display_stack(&stack);
            break;
        case 8:
            return 0;
        default:
            printf("invalid choice\n");
            break;
        }
     }
}
