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
    ListNode* swapNodes(ListNode* head, int k) {
        int l=0;
        ListNode* t=head;
        while(t){
            l++;
            t=t->next;
        }
        ListNode*x=head,*y=head;
        int p=k-1;
        while(x && p--){
            x=x->next;
        }
        p=l-k;
        while(y && p--){
            y=y->next;
        }
        p=x->val;
        x->val=y->val;
        y->val=p;
        return head;
    }
};