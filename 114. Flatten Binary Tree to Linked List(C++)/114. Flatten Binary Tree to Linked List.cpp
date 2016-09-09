/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        flatten_recursive(root);
    }
    
    TreeNode* flatten_recursive(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return root;
        }
        auto tail_left = flatten_recursive(root->left);
        auto tail_right = flatten_recursive(root->right);
        if(root->left == nullptr) {
            return tail_right;
        } else if (root->right == nullptr) {
            root->right = root->left;
            root->left = nullptr;
            return tail_left;
        }
        tail_left->right = root->right;
        tail_left->left = nullptr;
        root->right = root->left;
        root->left = nullptr;

        return tail_right;
    }
};