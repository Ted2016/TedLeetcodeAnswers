/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL)
        return 0;
    int depth;
    int LeftDepth = maxDepth(root->left);
    int RightDepth = maxDepth(root->right);
    depth = (LeftDepth > RightDepth) ? LeftDepth+1 : RightDepth+1;
    return depth;
}
