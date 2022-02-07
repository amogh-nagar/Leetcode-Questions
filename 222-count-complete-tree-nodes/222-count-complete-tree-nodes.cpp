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
    bool check(int m,TreeNode*root,int height){
        height-=2;
        while(height>=0 && root!=NULL){
            bool left=(m & (1<<height))==0;
            root=(left)?root->left:root->right;
            height--;
        }
        return root!=NULL;
    }
    int countNodes(TreeNode* root) {
        TreeNode *t=root;
        int height=0;
        while(t){
            height++;
            t=t->left;
        }
        int l=0,leaves=0,h=pow(2,height-1)-1;
        while(l<=h){
            int m=(l+h)/2;
            if(check(m,root,height)){
                l=m+1;
                leaves=m+1;
            }else{
                h=m-1;
            }
        }
        leaves+=((pow(2,height-1))-1);
        return leaves;
    }
};