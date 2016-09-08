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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) {
            return true;
        } else {
            return help(root->left, root->right);
        }
    }
    bool help(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr) {
            return true;
        } else if (left != nullptr && right != nullptr) {
            return (left->val == right->val && help(left->right, right->left) && help(left->left, right->right));
        } else {
            return false;
        }
    }
};