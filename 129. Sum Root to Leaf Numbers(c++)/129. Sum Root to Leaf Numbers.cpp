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
    int sumNumbers(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } else if(root->left == nullptr && root->right == nullptr) {
            return root->val;
        } else if(root->left == nullptr) {
            root->right->val = root->right->val + root->val*10;
            return sumNumbers(root->right);
        } else if(root->right == nullptr) {
            root->left->val = root->left->val + root->val*10;
            return sumNumbers(root->left);
        } else {
            root->right->val = root->right->val + root->val*10;
            root->left->val = root->left->val + root->val*10;
            return sumNumbers(root->right)+sumNumbers(root->left);
        }
    }
};