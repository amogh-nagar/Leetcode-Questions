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
    ListNode* reverse(ListNode *head){
        
        ListNode *prev=NULL,*curr=head,*t=NULL;
        
        while(curr){
            t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1=reverse(l1);
        ListNode *t2=reverse(l2);
        int carry=0,x=t1->val+t2->val;
        ListNode *h=new ListNode(x%10);
        carry=x/10;
        t1=t1->next;t2=t2->next;
        ListNode *temp=h;
        while(t1!=NULL && t2!=NULL){
           x=t1->val+t2->val+carry;
           temp->next=new ListNode(x%10);
            temp=temp->next;
           carry=x/10;
            t1=t1->next;t2=t2->next;
        }
        while(t1!=NULL){
            x=t1->val+carry;
            temp->next=new ListNode(x%10);
            temp=temp->next;
           carry=x/10;
            t1=t1->next;
        }
        while(t2!=NULL){
            x=t2->val+carry;
            temp->next=new ListNode(x%10);
            temp=temp->next;
           carry=x/10;
            t2=t2->next;
        }
        if(carry!=0){
            temp->next=new ListNode(carry);
            temp=temp->next;
            carry/=10;
        }
        return reverse(h);
    }
};