class Solution {
public:
    int sumRootToLeaf(TreeNode* root, int val = 0) {
        if (!root) return 0;//base condition
        //val = val << 1 | root->val; //Both are same it's just the bit manipulation way  
        val = (val * 2 + root->val); //using Normal math
        return (root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));//dfs call
    }
};