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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr; // Base case: if root is null, return null
        
        // Swap the left and right subtree
        std::swap(root->left, root->right);

        // Recursively invert left and right subtree
        invertTree(root->left);
        invertTree(root->right);

        return root; // Return the inverted tree
    }
};
