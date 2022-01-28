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
        stack<pair<ListNode*,int>> st;
        vector<int> v;
        ListNode*t=head;
        int i=0;
        while(t){
            while(!st.empty() && st.top().first->val<t->val){
                v[st.top().second]=t->val;
                st.pop();
            }
            
            st.push({t,i++});
            v.push_back(0);
            t=t->next;
        }
        while(!st.empty()){
            v[st.top().second]=0;
            st.pop();
        }
        return v;
    }
};