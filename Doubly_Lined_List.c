#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    struct Node* prev;
    int data;
    struct Node* next;
}Node;

Node* newNode(int data){
    Node* new_node=(Node*)malloc(sizeof(Node));
    new_node->prev=NULL;
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

Node* insert_at_beginning(Node* head,int data){
    Node* new_node=newNode(data);
    if(head==NULL){
        return new_node;
    }
    new_node->next=head;
    head->prev=new_node;
    return new_node;
}

Node* insert_at_middle(Node* head,int data){
    Node* new_node=newNode(data);
    if(head==NULL){
        return new_node;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    new_node->next=slow;
    new_node->prev=slow->prev;
    slow->prev->next=new_node;
    slow->prev=new_node;
    return head;
}

Node* insert_at_end(Node* head,int data){
    Node* new_node=newNode(data);
    if(head==NULL){
       return new_node;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
    return head;

}

Node* delete_at_beginning(Node* head){
    if(head==NULL){
        printf("List is Empty\n");
    }
    Node* temp=head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return head;
    }
    head=temp->next;
    temp->next->prev=NULL;
    free(temp);
    return head;
    
}

Node* delete_at_end(Node* head){
    if(head==NULL){
        printf("List is Empty\n"); 
    }
    Node* temp=head;
    if(temp->next==NULL){
        head=NULL;
        free(temp);
        return head;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    return head;
}

Node* delete_at_middle(Node* head){
    if(head==NULL){
         printf("List is Empty\n");
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    slow->next->prev=slow->prev;
    slow->prev->next=slow->next;
    free(slow);
    return head;
}
void traverse_LR(Node* head){
    if(head==NULL){
        printf("Empty Lits\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
      printf("\n");
    return;
}

void traverse_RL(Node* head){
    if(head==NULL){
        printf("Empty Lits\n");
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
    return;
}

int count_nodes(Node* head){
    int count=0;
    Node* temp=head;
    if(head==NULL) return count;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    int n;
    printf("Enter number of operations you want to perform\n");
    scanf("%d",&n);
    if(n<=0){
        printf("No operations need to be performed\n");
        return 0;
    }
    Node* head=NULL;
    int data=0;
    int cnt=0;
    while(n--){
        int op;
        scanf("%d",&op);
        switch (op){
            case 1:
                printf("Enter data to insert at begenning\n");
                scanf("%d",&data);
                head= insert_at_beginning(head,data);
                break;

            case 2:
                printf("Enter data to insert at end\n");
                scanf("%d",&data);
                head= insert_at_end(head,data);
                break;

            case 3:
                printf("Enter data to insert at middle\n");
                scanf("%d",&data);
                head= insert_at_middle(head,data);
                break;
            
            case 4:
                head=delete_at_beginning(head);
                break;
            
            case 5:
                head=delete_at_end(head);
                break;
            
            case 6:
                head=delete_at_middle(head);
                break;
            
            case 7:
                cnt=count_nodes(head);
                printf("Number of Nodes are: %d\n",cnt);
                break;

            case 8:
                printf("List from left to right\n");
                traverse_LR(head);
                break;
            
            case 9:
                printf("List from right to left\n");
                traverse_RL(head);
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}
