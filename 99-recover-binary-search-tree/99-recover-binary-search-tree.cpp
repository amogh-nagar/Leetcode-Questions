/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> v;
    map<int,TreeNode*> m;
    void solve(TreeNode*root){
        if(!root)return;
        solve(root->left);
        m[root->val]=root;
        v.push_back(root->val);
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        
        solve(root);
        vector<int> t(v.begin(),v.end());
        sort(t.begin(),t.end());
        int x,y,f=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=t[i]){
                x=v[i],y=t[i];
                break;
            }
        }
        swap(m[x]->val,m[y]->val);
    }
};