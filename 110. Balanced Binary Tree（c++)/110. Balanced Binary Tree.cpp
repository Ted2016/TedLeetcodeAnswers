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
    bool isBalanced(TreeNode* root) {
        int h;
        return height(root, h);
    }
    
    bool height(TreeNode* root, int& h) {
        if(root == nullptr) {
            h = 0;
            return true;
        } else if(root->left == nullptr && root->right == nullptr) {
            h = 1;
            return true;
        }
        int left_h, right_h;
        if(!height(root->left, left_h) || !height(root->right, right_h)) {
            return false;
        } 
        h = max(left_h, right_h)+1;
        return abs(left_h-right_h) < 2;
    }
};