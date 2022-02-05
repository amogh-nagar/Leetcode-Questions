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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode *t=lists[i];
            while(t){
                pq.push(t->val);
                t=t->next;
            }
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode *h=new ListNode(pq.top());
        pq.pop();
        ListNode *t=h;
        while(!pq.empty()){
            t->next=new ListNode(pq.top());
            pq.pop();
            t=t->next;
        }
        return h;
    }
};