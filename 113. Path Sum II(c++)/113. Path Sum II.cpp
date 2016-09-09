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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr) {
            return vector<vector<int>>{};
        } else if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum) {
                return vector<vector<int>>{vector<int>{sum}};
            } else {
                return vector<vector<int>>{};
            }
        }
        int val = sum - root->val;
        vector<vector<int>> lhs = pathSum(root->left, val);
        vector<vector<int>> rhs = pathSum(root->right, val);
        lhs.insert(lhs.begin(), rhs.begin(), rhs.end());
        for(auto &ints : lhs) {
            ints.insert(ints.begin(), root->val);
        }
        return lhs;
    }
};