/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode* temp=head;
        for(int i = 0; i < k; i++){
            if(temp==NULL) return head;
            temp = temp->next;
        }
    struct ListNode* curr = head;
    struct ListNode* prev = NULL;
    struct ListNode* forward =NULL;
        for(int i = 0; i < k; i++){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
