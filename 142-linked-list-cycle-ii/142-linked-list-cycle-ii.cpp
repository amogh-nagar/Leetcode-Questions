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
    ListNode *detectCycle(ListNode *head) {
        if(!head){
            return NULL;
        }
        
        ListNode*f=head,*s=head;
        do{
            s=s->next;
            if(f->next && f->next->next)
               f=f->next->next;
            
        }while(f &&s && f->next&&f->next->next && f!=s);
            // cout<<f->val<<s->val<<endl;
        
    if(f && s && f==s){
        
        f=head;
        while(f!=s){
            // cout<<f->val<<s->val<<endl;
            f=f->next;
            s=s->next;
        }
        return f;
    }
        return NULL;
    }
};