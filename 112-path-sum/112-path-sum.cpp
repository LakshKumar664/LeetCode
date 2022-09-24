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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;

        return sum(root, targetSum, root->val);
    }
    
    bool sum(TreeNode* root, int targetSum, int Sum){
        if(!root->left && !root->right){
            return targetSum == Sum;
        }
        bool left = false;
        if(root->left){
            left = sum(root->left, targetSum, Sum+root->left->val);
        }
        bool right = false;
        if(root->right){
            right = sum(root->right, targetSum, Sum+root->right->val);
        }

        return  left || right;
    }
};