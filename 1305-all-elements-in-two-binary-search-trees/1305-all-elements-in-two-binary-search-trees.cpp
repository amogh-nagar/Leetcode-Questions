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
    vector<int> v1,v2;
    void inorder(TreeNode*root,vector<int>&v){
        if(!root){
            return;
        }
        
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inorder(root1,v1);
        inorder(root2,v2);
        int n=v1.size(),m=v2.size(),k=0,i=0,j=0;
        vector<int> res(n+m,0);
        while(i<n && j<m){
            if(v1[i]<=v2[j]){
                res[k++]=v1[i++];
                
            }else{
                res[k++]=v2[j++];
            }
        }
        while(i<n){
            res[k++]=v1[i++];
        }
        while(j<m){
            res[k++]=v2[j++];
        }
        return res;
    }
};