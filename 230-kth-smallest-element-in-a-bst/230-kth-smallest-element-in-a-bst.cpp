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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> elems;
        int elem;
        
        // inorder(root, elems);
        Inorder(root, k, 0, elem);
        return elem;
    }
    
    void inorder(TreeNode* root, vector<int>& elems){
        if(!root)
            return;
        
        inorder(root->left, elems);
        elems.push_back(root->val);
        inorder(root->right, elems);
    }
    
    int Inorder(TreeNode* root, int k, int p, int& elem){
        if(!root)
            return p;
        
        p = Inorder(root->left, k, p, elem) + 1;
        if(p == k){
            elem = root->val;
            return p;
        }
        p = Inorder(root->right, k, p, elem);
        
        return p;
    }
};