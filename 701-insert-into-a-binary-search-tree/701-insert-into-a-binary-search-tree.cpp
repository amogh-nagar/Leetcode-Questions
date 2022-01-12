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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *t=root,*p=NULL;
        while(t!=NULL){
            if(t->val>val){
                p=t;
                t=t->left;
            }else{
                p=t;
                t=t->right;
            }
        }
        if(p==NULL){
            return new TreeNode(val);
        }
        if(p->val>val){
            p->left=new TreeNode(val);
        }else{
            p->right=new TreeNode(val);
        }
        return root;
    }
};