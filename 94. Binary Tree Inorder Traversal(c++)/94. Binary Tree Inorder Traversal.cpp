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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) {
            return vector<int>{};
        }
        vector<int> lhs = inorderTraversal(root->left);
        lhs.push_back(root->val);
        vector<int> rhs = inorderTraversal(root->right);
        lhs.insert(lhs.end(), rhs.cbegin(), rhs.cend());
        return lhs;
    }
};