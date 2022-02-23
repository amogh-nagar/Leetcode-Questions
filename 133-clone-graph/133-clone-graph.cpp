/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        map<int,Node*> m;
        map<int,int> vis;
        queue<Node*> q;
        Node*h=new Node(node->val);
        q.push(node);
        m[h->val]=h;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            vis[x->val]=1;
            for(auto y:x->neighbors){
                if(!vis[y->val]){
                    q.push(y);
                }
                if(m[y->val]!=NULL){
                   m[x->val]->neighbors.push_back(m[y->val]);
                    
                }else{
                 
                auto t=new Node(y->val);
                 m[y->val]=t;
                    m[x->val]->neighbors.push_back(t);
                }
                vis[y->val]=1;
            }
        }
        return h;
    }
};