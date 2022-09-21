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
    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> level_sum;
        queue<pair<TreeNode*, int>> nodes;
        
        nodes.push(make_pair(root, 0));
        int max_level = 0;
        
        while(nodes.size()){
            int level = nodes.front().second;
            TreeNode* node = nodes.front().first;
            max_level = max(level, max_level);
            
            if(level_sum.count(level)){
                level_sum[level] += node->val;
            }
            else{
                level_sum[level] = node->val;
            }
            
            nodes.pop();
            
            if(node->left){
                nodes.push(make_pair(node->left, level + 1));
            }
            if(node->right){
                nodes.push(make_pair(node->right, level + 1));
            }
        }
        
        return level_sum[max_level];
    }
};