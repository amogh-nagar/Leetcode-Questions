
class Solution {
public:
    TreeNode* solve(TreeNode*root){
        if(!root){
            return NULL;
        }
        if(!root->left && !root->right){
            return root;
        }
        
        TreeNode*l=solve(root->left);
        TreeNode*r=solve(root->right);
        if(l!=NULL){
        if(l->right!=NULL){
            TreeNode*temp=l;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=r;
        }  else{
            
        l->right=r;
        }    
        root->right=l;   
        
        }
        root->left=NULL;
        return root;
    }
    void flatten(TreeNode* root) {
        root=solve(root);
    }
};