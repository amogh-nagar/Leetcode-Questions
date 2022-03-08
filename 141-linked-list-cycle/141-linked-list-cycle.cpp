/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head){
            return false;
        }
        ListNode*s=head,*f=head;
        do{
            s=s->next;
            if(f->next)
                f=f->next->next;
            else
                f=f->next;
        }while(s && f  && s!=f);
        return s && f && s==f;
    }
};