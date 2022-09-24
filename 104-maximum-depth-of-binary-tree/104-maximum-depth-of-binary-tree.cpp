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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        
        maxLength(root, 0, max_depth);
        
        return max_depth;
    }
    
    void maxLength(TreeNode* root, int level, int& max_depth){
        if(!root){
            max_depth = max(max_depth, level);
            return;
        }
        
        maxLength(root->left, level+1, max_depth);
        maxLength(root->right, level+1, max_depth);
        
    }
};