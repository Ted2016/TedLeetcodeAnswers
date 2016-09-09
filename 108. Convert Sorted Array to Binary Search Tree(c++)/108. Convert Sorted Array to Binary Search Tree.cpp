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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size());
    }
    TreeNode* help(vector<int>& nums,int lhs, int rhs) {
        if(lhs >= rhs) {
            return nullptr;
        }
        int mid = (lhs+rhs)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = help(nums, lhs, mid);
        root->right = help(nums, mid+1, rhs);
        return root;
    }
    
};