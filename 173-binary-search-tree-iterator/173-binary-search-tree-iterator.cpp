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
class BSTIterator {
public:
    vector<TreeNode*> v;
    int x;
    void solve(TreeNode* root){
        if(!root)
            return;
        solve(root->left);
        v.push_back(root);
        solve(root->right);
    }
    BSTIterator(TreeNode* root) {
        solve(root);
        x=-1;
    }
    
    int next() {
        x++;
        return v[x]->val;
    }
    
    bool hasNext() {
        return x==-1 && v.size()>0||x<v.size()-1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */