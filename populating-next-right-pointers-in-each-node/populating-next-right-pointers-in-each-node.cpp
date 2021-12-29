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

class Solution
{
public:
    Node *connect(Node *root)
    {
        if(!root){
            return NULL;
        }
        queue<Node *> q;
        root->next=NULL;
        if(root->left && root->right){
        q.push(root->left);
        q.push(root->right);}
        while (!q.empty())
        {
            Node *t = q.front();
            q.pop();
                queue<Node *> x;
                t->next=q.front();
            if(t->left && t->right){
                x.push(t->left);
                x.push(t->right);}
                while (!q.empty())
                {

                    Node *y = q.front();

                    q.pop();
                    if (q.empty())
                    {
                        y->next = NULL;
                    }
                    else
                    {
                        y->next = q.front();

                    }
                    if(y->left && y->right){
                        x.push(y->left);
                        x.push(y->right);}
                }
                while (!x.empty())
                {
                    q.push(x.front());
                    x.pop();
                }
            
        }
        return root;
    }
};