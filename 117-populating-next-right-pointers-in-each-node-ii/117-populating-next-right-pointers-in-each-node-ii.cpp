/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        Node *h=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int x=q.size();
            Node *p=NULL;
            for(int i=0;i<x;i++){
                auto c=q.front();q.pop();
                if(p){
                    p->next=c;
                    p=c;
                }else{
                    p=c;
                }
                if(c->left){
                    q.push(c->left);
                    
                }
                if(c->right){
                    q.push(c->right);
                }
            }
        }
        return h;
    }
};