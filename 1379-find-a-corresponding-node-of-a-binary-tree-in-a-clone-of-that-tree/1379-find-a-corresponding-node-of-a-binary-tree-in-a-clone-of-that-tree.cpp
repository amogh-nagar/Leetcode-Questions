/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!original){
            return NULL;
        }
        if(target==original){
            return cloned;
        }
        TreeNode* l=getTargetCopy(original->left,cloned->left,target);
        if(l){
            return l;
        }
        TreeNode* r=getTargetCopy(original->right,cloned->right,target);
        return r;
    }
};