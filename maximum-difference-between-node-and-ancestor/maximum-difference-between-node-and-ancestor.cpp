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
    int maxdiff=0;
    pair<int,int> solve(TreeNode *root){
        if(!root){
            return {INT_MAX,INT_MIN};
        }
        if(!root->left && !root->right){
            return {root->val,root->val};
        }
        
        
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        
        int x=0;
            if(left.first!=INT_MAX && left.second!=INT_MIN)
                x=max(abs(root->val-left.first),abs(root->val-left.second));
        int y=0;
        if(right.first!=INT_MAX && right.second!=INT_MIN)
           y=max(abs(root->val-right.first),abs(root->val-right.second));
        
        maxdiff=max(maxdiff,max(x,y));
        return {min(left.first,min(right.first,root->val)),max(left.second,max(right.second,root->val))};
    }
    
    int maxAncestorDiff(TreeNode* root) {
        solve(root);
        return maxdiff;
        
        
        
    }
};