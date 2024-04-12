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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderTraversalHelp(root, result);
        return result;
    }

private:
    void inorderTraversalHelp(TreeNode* root, vector<int>& result) {
        if (root != nullptr) {
            inorderTraversalHelp(root->left, result); 
            result.push_back(root->val);           
            inorderTraversalHelp(root->right, result); 
        }
    }
};