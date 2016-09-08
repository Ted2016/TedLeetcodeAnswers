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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_recursive(inorder, postorder, make_pair(0, inorder.size()-1),  make_pair(0, postorder.size()-1));
    }
    TreeNode* buildTree_recursive(vector<int>& inorder, vector<int>& postorder, pair<int, int> in, pair<int, int> post) {
        if(in.first > in.second) {
            return nullptr;
        }
        auto iter1 = find(inorder.begin()+in.first, inorder.begin()+in.second+1, postorder[post.second]);
        int n = iter1-inorder.begin()-in.first;
        TreeNode* root = new TreeNode(postorder[post.second]);
        root->left = buildTree_recursive(inorder, postorder, make_pair(in.first, n+in.first-1), make_pair(post.first, post.first+n-1));
        root->right = buildTree_recursive(inorder, postorder, make_pair(in.first+n+1, in.second), make_pair(post.first+n, post.second-1));
        return root;
    }
};