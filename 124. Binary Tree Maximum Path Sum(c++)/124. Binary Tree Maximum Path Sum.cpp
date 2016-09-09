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
    int maxPathSum(TreeNode* root) {
        return maxPathSum_help(root).first;
    }
    pair<int, int> maxPathSum_help(TreeNode* root) {
        if(root == nullptr) {
            return make_pair(INT_MIN, 0);
        } 
        pair<int, int> lhs = maxPathSum_help(root->left);
        pair<int, int> rhs = maxPathSum_help(root->right);
        int first = max(root->val + lhs.second + rhs.second,
        max(lhs.first, rhs.first));
        int second = max(root->val, root->val + max(lhs.second, rhs.second));
        first = max(first, second);
        return make_pair(first, second);
    }
};
