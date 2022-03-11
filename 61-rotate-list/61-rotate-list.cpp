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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode*t=head,*prev=NULL;
        int len=0;
        while(t){
            prev=t;
            len++;
            t=t->next;
        }
        if(len==0){
            return NULL;
        }
        int x=len-(k%len);
        t=head;
        ListNode*m=NULL;
        while(x>0){
            m=t;
            t=t->next;
            x--;    
        }
        prev->next=head;
        head=m->next;
        m->next=NULL;
        return head;
    }
};