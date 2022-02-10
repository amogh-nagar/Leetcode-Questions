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
    
    int c=0;
    void solve(TreeNode*root,int prefsum,int target,map<int,int> m){
        if(!root){
            return ;
        }
        prefsum+=root->val;
        
        if(m.find(prefsum-target)!=m.end()){
            c+=m[prefsum-target];
        }
        m[prefsum]++;
        solve(root->left,prefsum,target,m);
        solve(root->right,prefsum,target,m);
    }
    int pathSum(TreeNode* root, int target) {
        map<int,int> m;
        m[0]=1;
        solve(root,0,target,m);
        return c;
        
    }
};