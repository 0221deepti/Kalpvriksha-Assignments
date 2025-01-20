#include<stdio.h>
#include<stdlib.h>

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

Node* insertAtEnd(Node* head,int data){
    Node* new_node=newNode(data);
    if(head==NULL){
        return new_node;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    return head;
}

Node* insertAtBeginning(Node* head,int data){
    Node* new_node=newNode(data);
    new_node->next=head;
    return new_node;
}
Node* insertAtPosition(Node* head,int pos,int data){
    if(pos<1) {
        printf("Invalid position\n");
        return head;
    }
    if(pos==1){
        head=insertAtBeginning(head,data);
        return head;
    }
    int count=1;
    Node* temp=head;
    while(temp!=NULL && count<pos-1){
        temp=temp->next;  
        count++;
    }
    if(temp==NULL){
        printf("Invalid Position\n");
        return head;
    }
    Node* new_node=newNode(data);
    new_node->next=temp->next;
    temp->next=new_node;
    return head;
}

Node*  updateAtPosition(Node *head,int pos, int new_data){
    if(pos<1){
        printf("Invalid Position\n");
        return head;
    }
    if(head==NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp=head;
    int count=1;
    while(temp!=NULL && count<pos ){
        temp=temp->next;
          count++;
    }
    if(temp==NULL){
        printf("Invalid Position\n");
        return head;
    }
    temp->data=new_data;
    return head;
}

Node* deleteAtBeginning(Node* head){
    if(head==NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp=head;
    head=temp->next;
    free(temp);
    return head;

}
Node* deleteAtEnd(Node* head){
    if(head==NULL){
        printf("Empty List\n");
        return head;
    }
    Node* temp=head;
    Node* pre=NULL;
    while(temp->next!=NULL){
       pre=temp;
       temp=temp->next;
    }
   if(pre!=NULL){
     pre->next = NULL;  
   }
   else {
       head=NULL;
   }
   free(temp);
     return head;
    
}
Node* deleteAtPosition(Node* head,int pos){
    if(head==NULL){
        printf("Empty List\n");
        return head;
    }
    if(pos<1){
        printf("Invalid Position\n");
        return head;
    }
    Node* temp=head;
    Node* pre=NULL;
    if (pos == 1) {
        head = temp->next;
        free(temp);
        return head;
    }
    int count=1;
        while(temp!=NULL && count<pos){
          pre=temp;
          temp=temp->next;
          count++;
        }
        if(temp==NULL){
            printf("Invalid Position\n");
            return head;
        }
        pre->next=temp->next;
        free(temp);
        return head;
    }

void display(Node* head){
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n;
    scanf("%d",&n);
    Node* head=NULL;
    
    while(n--){
        int op;
        scanf("%d",&op);
        int num, pos;
        switch(op){
            case 1:
            scanf("%d",&num);
            head=insertAtEnd(head,num);
            break;

            case 2:
            scanf("%d",&num);
            head=insertAtBeginning(head,num);
            break;

            case 3:
            scanf("%d %d",&pos,&num);
            head= insertAtPosition(head,pos,num);
            break;

            case 4:
            display(head);
            break;

            case 5:
            scanf("%d %d",&pos,&num);
            head=updateAtPosition(head,pos,num);
            break;

            case 6:
            head=deleteAtBeginning(head);
            break;

            case 7:
            head=deleteAtEnd(head);
            break;

            case 8:
            scanf("%d",&pos);
            head=deleteAtPosition(head,pos);
            break;
            
            default:
            printf("Invalid choice\n");
            
        }

    }
    return 0;
}
