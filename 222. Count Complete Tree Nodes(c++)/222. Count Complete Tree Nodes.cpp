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
    int countNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        } 
        auto work = root;
        int lhs = 0, rhs = 0, count = 0;
        while(work != nullptr) {
            work = work->left;
            lhs++;
        }
        work = root->left;
        while(work != nullptr) {
            work = work->right;
            rhs++;
        }
        if(lhs == rhs+1) {
            return pow(2, rhs)+countNodes(root->right);
        } else {
            return pow(2, rhs)+countNodes(root->left);
        }
    }
};