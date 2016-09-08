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
private:
    TreeNode* treeCopyAddValue(TreeNode* root, int addVal) {
        if(root == nullptr) {
            return root;
        }
        auto newRoot = new TreeNode(root->val+addVal);
        newRoot->left = treeCopyAddValue(root->left, addVal);
        newRoot->right = treeCopyAddValue(root->right, addVal);
        return newRoot;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) {
            return vector<TreeNode*>();
        }
        vector<vector<TreeNode*>> dp(n+1);
        dp[0] = vector<TreeNode*>{nullptr};
        for(int i  = 1; i <= n; i++) {
            vector<TreeNode*> tmp;
            for(int j = 1; j <= i; j++) {
                auto lhs = dp[j-1];
                auto rhs = dp[i-j];
                for(auto leftP : lhs) {
                    for(auto rightP : rhs) {
                        TreeNode* root = new TreeNode(j);
                        root->left = leftP;
                        root->right = treeCopyAddValue(rightP, j); 
                        tmp.push_back(root);
                    }
                }
                
            }
            dp[i] = tmp;
        }
        return dp[n];
    }
};