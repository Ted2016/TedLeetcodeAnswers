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
    int kthSmallest(TreeNode* root, int& k) {
    if (root) {
        int x = kthSmallest(root->left, k);
        return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
    } 
    return 0;
}
};