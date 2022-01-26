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
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root1)
          q.push(root1);
        while(!q.empty()){
            TreeNode *x=q.front();
            q.pop();
            res.push_back(x->val);
            if(x->left){
              q.push(x->left);  
            }
            if(x->right){
                q.push(x->right);
            }
        }
        if(root2)
          q.push(root2);
        while(!q.empty()){
            TreeNode *x=q.front();
            q.pop();
            res.push_back(x->val);
            if(x->left){
              q.push(x->left);  
            }
            if(x->right){
                q.push(x->right);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};