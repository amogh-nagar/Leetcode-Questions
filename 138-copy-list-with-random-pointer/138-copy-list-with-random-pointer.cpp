/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> m;
        if(!head){
            return NULL;
        }
        Node *nhead=new Node(head->val);
        m.insert({head,nhead});
        Node *nt=nhead;
        Node *t=head->next;
        while(t){
            Node *x=new Node(t->val);
            m.insert({t,x});
            nt->next=x;
            nt=x;
            t=t->next;
        }
        nt=nhead;
        t=head;
        while(t){
          if(t->random!=NULL){
                Node *y=m[t];
              y->random=m[t->random];
          }else{
              nt->random=NULL;
          }
            t=t->next;
            nt=nt->next;
        }
        return nhead;
    }
};