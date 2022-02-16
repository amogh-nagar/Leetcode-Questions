/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head){
            return NULL;
        }
        
        if(!head->next){
            return head;
        }
        
        ListNode*prev=head,*curr=NULL,*t=NULL,*x=head->next;
        while(prev!=NULL){
            curr=prev->next;
            if(curr){
            t=curr->next;
            curr->next=prev;
            if(t && t->next)
             prev->next=t->next;
            else{
                prev->next=t;
            }}else{
                break;   
                
            }
            prev=t;
        }
        
        return x;
    }
};