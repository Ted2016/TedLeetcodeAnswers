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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_recursive(preorder, inorder, make_pair(0, preorder.size()-1),  make_pair(0, inorder.size()-1));
    }
    TreeNode* buildTree_recursive(vector<int>& preorder, vector<int>& inorder, pair<int, int> pre, pair<int, int> in) {
        if(pre.first > pre.second) {
            return nullptr;
        }
        auto iter1 = find(inorder.begin()+in.first, inorder.begin()+in.second+1, preorder[pre.first]);
        int n = iter1-inorder.begin()-in.first;
        TreeNode* root = new TreeNode(preorder[pre.first]);
        root->left = buildTree_recursive(preorder, inorder, make_pair(pre.first+1, n+pre.first), make_pair(in.first, in.first+n-1));
        root->right = buildTree_recursive(preorder, inorder, make_pair(pre.first+n+1, pre.second), make_pair(in.first+n+1, in.second));
        return root;
    }
};