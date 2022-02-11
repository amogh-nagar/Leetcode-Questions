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
    vector<TreeNode*> res;
    unordered_map<string,int> us;
    string solve(TreeNode*root){
        if(!root){
            return "$";
        }
        
        string l=solve(root->left);
        string r=solve(root->right);
        
        string s=to_string(root->val)+" "+l+r;
    
        us[s]++;
        if(us[s]==2){
            res.push_back(root);
        }
        return s;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solve(root);
        return res;
    }
};