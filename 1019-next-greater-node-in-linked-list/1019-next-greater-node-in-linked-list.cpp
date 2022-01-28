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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode*t=head;
        vector<int> v;
        while(t){
            ListNode*x=t->next;
            while(x && x->val<=t->val){
                x=x->next;
            }
            if(x){
                v.push_back(x->val);
            }else{
                v.push_back(0);
            }
            t=t->next;
        }
        return v;
    }
};