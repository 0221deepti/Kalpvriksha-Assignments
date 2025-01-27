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

Node* insert_into_LL(Node* head,int data){
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
int count_occurrences_of_42(Node* head){
    int count=0;
    Node* temp=head;
    if(temp==NULL){
        printf("List is empty\n");
        return 0;
    }
    while(temp!=NULL){
        if(temp->data==42)
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    printf("Enter number of element to be inserted\n");
    int n;
    scanf("%d",&n);
    if(n<=0){
        printf("Empty list\n");
        return 0;
    }
    int num=0;
    Node* head=NULL;
    printf("Insert data into LL:\n");
    for(int i=0;i<n;i++){
      scanf("%d",&num);
      head=insert_into_LL(head,num);
    }
    int count=count_occurrences_of_42(head);
    printf("Number of occurance of 42 is:%d",count);
    return 0;
}
