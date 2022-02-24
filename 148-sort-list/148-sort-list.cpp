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
    
    ListNode* findmid(ListNode*head){
        if(!head->next){
            return head;
        }
        
        ListNode *fast=head,*slow=head;
        
        while(fast!=NULL||fast->next==NULL){
            fast=fast->next;
            if(!fast||!fast->next){
                break;
            }
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* head=head1,*end=head1;
        if(head1->val>head2->val){
            head=end=head2;
            head2=head2->next;
        
        }else{
          head1=head1->next;
          
        }
        while(head1 && head2){
         if(head1->val>head2->val){
            end->next=head2;
             end=head2;
              head2=head2->next;
       
        }   else{
             end->next=head1;
             end=head1;
              head1=head1->next;
         }
        }
        while(head1){
            
             end->next=head1;
             end=head1;
              head1=head1->next;
        }
        while(head2){
            
             end->next=head2;
             end=head2;
              head2=head2->next;
        }
        return head;
    }
    ListNode* solve(ListNode* head){
        
        if(head==NULL){
            return NULL;
        }
        if(!head->next){
            return head;
        }
        
        ListNode*mid=findmid(head);
        ListNode* midnext=mid->next;
        mid->next=NULL;
        ListNode* x=solve(head);
        ListNode* y=solve(midnext);
        return merge(x,y);
    }
    
    ListNode* sortList(ListNode* head) {
        return solve(head);
    }
};