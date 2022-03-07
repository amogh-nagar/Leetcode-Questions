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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode*h=list1,*e=list1;
        if(list1->val>list2->val){
            h=e=list2;
            list2=list2->next;
        }else{
            list1=list1->next;
        }
        while(list1!=NULL || list2!=NULL){
            if(list1 && list2){
                
            if( list1->val<=list2->val){
                    e->next=list1;
                    e=list1;
                    list1=list1->next;
                }else{
                    e->next=list2;
                    e=list2;
                    list2=list2->next;
                }
            }else if(list1){
                e->next=list1;
                e=list1;
                list1=list1->next;
            }else{
                e->next=list2;
                e=list2;
                list2=list2->next;
            }
        }
        
        return h;
    }
};