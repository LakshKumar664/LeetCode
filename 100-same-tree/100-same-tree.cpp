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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> root1;
        queue<TreeNode*> root2;
        bool same = true;
        
        
        if(p)
        root1.push(p);
        if(q)
        root2.push(q);
        
        while(root1.size() && root2.size() && same){
            TreeNode* node1 = root1.front();
            TreeNode* node2 = root2.front();
            
            if(node1->val != node2->val)
                same = false;
            
            if(node1->left && !node2->left)
                same = false;
            
            if(node1->right && !node2->right)
                same = false;

            if(node2->left && !node1->left)
                same = false;
            
            if(node2->right && !node1->right)
                same = false;
            
            if(node1->left){
                root1.push(node1->left);
                root2.push(node2->left);
            }
            
            if(node1->right){
                root1.push(node1->right);
                root2.push(node2->right);
            }
            
            root1.pop();
            root2.pop();
        }
        
        if(root1.size() || root2.size()){
            same = false;
        }
        
        return same;
    }
};