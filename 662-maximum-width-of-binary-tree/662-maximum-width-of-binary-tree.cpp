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
    
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<pair<TreeNode*,long long >> q;
        q.push({root,0});
        long long res=INT_MIN;
        while(!q.empty()){
            long long start=q.front().second;
            long long end=q.back().second;
            res=max(res,end-start+1);
            int l=q.size();
            for(int i=0;i<l;i++){
                auto x=q.front();
                q.pop();
                x.second-=start;
                if(x.first->left){
                    q.push({x.first->left,(long long)x.second*2+1});
                }
                
                if(x.first->right){
                    q.push({x.first->right,(long long)x.second*2+2});
                }
            }
        }
        return res;
    }
};