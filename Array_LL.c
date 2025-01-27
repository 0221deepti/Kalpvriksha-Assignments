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
Node* insert_into_ll(Node* head,int data){
    Node* new_node=newNode(data);
    if(head==NULL) return new_node;
    Node* temp=head;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    temp->next=new_node;
    return head;
}

void print_LL(Node* head){
    if(head==NULL){
        printf("List is empty\n");
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

Node* delete_node(Node* head,int pos){
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    else if(pos<1) {
        printf("Invalid position\n");
        return head;
    }
    Node* temp=head;
    if(pos==1){
      head=head->next;
      free(temp);
      return head;
    }
    Node* prev=NULL;
    int count=1;
    while(temp!=NULL && count<pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(temp==NULL){
        printf("Invalis position\n");
        return head;
    }
    prev->next=temp->next;
    free(temp);
    return head;
    
}
int main(){
    int array[]={2,3,4,5,6,78,1,2,3};
    Node* head=NULL;
    int n=sizeof(array)/sizeof(array[0]);
    for(int i=0;i<n;i++){
        head=insert_into_ll(head,array[i]);
    }
    print_LL(head);
    int pos;
    printf("enter position to be delete\n");
    scanf("%d",&pos);
    head=delete_node(head,pos);
    print_LL(head);
}
