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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h=new ListNode(0);
        ListNode *t=h;
        while(head){
            if(head->next && head->next->val==head->val){
                int x=head->val;
                while(head && head->val==x){
                    cout<<head->val<<endl;
                    head=head->next;
                }
            }else{
                t->next=head;
                t=head;
                head=head->next;
            }
        }
        t->next=NULL;
        return h->next;
    }
};