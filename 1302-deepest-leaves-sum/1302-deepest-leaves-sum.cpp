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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int s=0;
        while(!q.empty()){
            auto x=q.size();
            int t=0;
            for(int i=0;i<x;i++){
                auto y=q.front();
                q.pop();
                t+=y->val;
                if(y->left){
                    q.push(y->left);
                }
                if(y->right){
                    q.push(y->right);
                }
            }
            s=t;
        }
        return s;
            
    }
};