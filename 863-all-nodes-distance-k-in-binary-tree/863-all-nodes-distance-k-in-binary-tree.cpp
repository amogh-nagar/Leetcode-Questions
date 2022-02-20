/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*> m;
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        getparent(root);
        map<TreeNode*,int> vis;
        queue<TreeNode*> q;
        q.push(target);
        vis[target]=1;
        int t=0;
        while(!q.empty()){
            
            int l=q.size();
            if(t==k){
            for(int i=0;i<l;i++){
             res.push_back(q.front()->val);
                q.pop();
            }
                break;
            }
            
            for(int i=0;i<l;i++){
             
            TreeNode*x=q.front();
            q.pop();
            vis[x]=1;
                
            if(x!=root && vis[m[x]]!=1){
                q.push(m[x]);
            }
            if(x->left && vis[x->left]!=1){
                q.push(x->left);
            }
            if(x->right && vis[x->right]!=1){
                q.push(x->right);
            }   
            }
            t++;
        }
        
        return res;
    }
    
    void getparent(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            if(x->left){
                m[x->left]=x;
                q.push(x->left);
            }
            if(x->right){
                m[x->right]=x;
                q.push(x->right);
            }
        }
    }
    
};