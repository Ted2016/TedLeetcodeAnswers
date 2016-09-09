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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightside = vector<int>{};
        vector<int> leftside = vector<int>{};
        if (root != NULL) {
            rightside = rightSideView(root->right);
            leftside = rightSideView(root->left);
            if(rightside.size() < leftside.size()) {
                size_t n = leftside.size() - rightside.size();
                rightside.insert(rightside.end(), leftside.end()-n, leftside.end());
            }
            rightside.insert(rightside.begin(), root->val);
        }
        return rightside;
    }
};