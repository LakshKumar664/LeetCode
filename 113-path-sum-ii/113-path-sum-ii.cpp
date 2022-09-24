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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> all_nodes;
        if(!root)
            return all_nodes;
        
        vector<int> path;
        
        sum(root, targetSum, root->val, path, all_nodes);
        
        return all_nodes;
    }
    
    void sum(TreeNode* root, int targetSum, int Sum, vector<int> path, 
             vector<vector<int>>& all_nodes){
        path.push_back(root->val);

        if(!root->left && !root->right){
            if(targetSum == Sum){
                all_nodes.push_back(path);
            }
            
            return;
        }
        
        if(root->left){
            sum(root->left, targetSum, Sum+root->left->val, path, all_nodes);
        }
        
        if(root->right){
            sum(root->right, targetSum, Sum+root->right->val, path, all_nodes);
        }
    }
};