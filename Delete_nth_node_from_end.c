/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int count_nodes(struct ListNode* head){
    if(head==NULL) return 0;
    int count=0;
   struct ListNode* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
struct ListNode* delete_node(struct ListNode* head,int pos){
  
    if(head==NULL) return head;
    struct ListNode* temp=head;
    if(pos==1){
        head=head->next;
        free(temp);
        return head;
    }
    int count=1;
    struct ListNode* prev=NULL;
    while(temp!=NULL && count<pos){
        count++;
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
    return head;   
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
   int length=count_nodes(head);
   int pos=length-n+1;
   return delete_node(head,pos); 
}
