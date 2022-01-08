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
    vector<vector<TreeNode*>> dp;
    vector<TreeNode*> solve(int n) {
       if(n==1){
           return {new TreeNode(0)};
       }
        if(dp[n].size()){
            return dp[n];
        }
        
        vector<TreeNode*> ans;
        for(int i=1;i<n;i++){
            vector<TreeNode*> l=solve(i);
            vector<TreeNode*> r=solve(n-i-1);
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode* root=new TreeNode(0);
                    root->left=l[j];
                    root->right=r[k];
                    ans.push_back(root);
                }
            }
            
        }
        return dp[n]=ans;
    }
    vector<TreeNode*> allPossibleFBT(int n){
        dp=vector<vector<TreeNode*>>(n+1);
        return solve(n);
    }
};