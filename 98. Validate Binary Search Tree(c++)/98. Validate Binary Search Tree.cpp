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
    bool isValidBST(TreeNode* root) {
        pair<int, int> p;
        return isValidBST_help(root, p);
    }
    bool isValidBST_help(TreeNode* root, pair<int, int>& p) {
        bool ret;
        if(root == nullptr) {
            p = make_pair(INT_MAX, INT_MIN);
            ret = true;
        } else if (root->left == nullptr && root->right == nullptr) {
            p = make_pair(root->val, root->val);
            ret = true;
        } else if (root->left == nullptr) {
             pair<int, int>  rhs;
             bool right = isValidBST_help(root->right, rhs);
             ret =  right && root-> val < rhs.first;
             p = make_pair(root->val, rhs.second);
        } else if(root->right == nullptr) {
             pair<int, int>  lhs;
             bool left = isValidBST_help(root->left, lhs);
             ret =  left && root-> val > lhs.second;
             p = make_pair(lhs.first, root->val);
        } else {
            pair<int, int> lhs, rhs;
            bool left = isValidBST_help(root->left, lhs);
            bool right = isValidBST_help(root->right, rhs);
            ret =  left && right && root->val > lhs.second && root-> val < rhs.first;
            p = make_pair(min(lhs.first, root->val), max(rhs.second, root->val));
        }
        return ret;
    }
};