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
    vector<int> findMode(TreeNode* root) {
        queue<TreeNode*> q;
        unordered_map<int,int> m;
        q.push(root);
        while(!q.empty()){
            TreeNode*t=q.front();
            q.pop();
            m[t->val]++;
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
        vector<int> v;
        int z=0;
        for (auto it = m.begin(); it != m.end(); it++){
             z=max(z,it->second);
         }
        for (auto it = m.begin(); it != m.end(); it++){
             if(it->second==z){
                 v.push_back(it->first);
             }
         }
        return v;
    }
};