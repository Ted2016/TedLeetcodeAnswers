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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>{};
        }
        vector<int> lhs = preorderTraversal(root->left);
        vector<int> rhs = preorderTraversal(root->right);
        lhs.insert(lhs.cbegin(), root->val);
        lhs.insert(lhs.end(), rhs.cbegin(), rhs.cend());
        return lhs;
    }
};