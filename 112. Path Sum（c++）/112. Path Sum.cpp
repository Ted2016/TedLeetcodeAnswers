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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr) {
            return false;
        } else if (root->left == nullptr && root->right == nullptr){
            if(root->val == sum) {
                return true;
            } else {
                return false;
            }
        } else {
            int val = sum - root->val;
            return hasPathSum(root->left, val) || hasPathSum(root->right, val);
        }
    }
};