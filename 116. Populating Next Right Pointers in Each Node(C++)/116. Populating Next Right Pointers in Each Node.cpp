/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr || root->right == nullptr) {
            return;
        }
        connect(root->left);
        connect(root->right);
        auto lhs = root->left, rhs = root->right;
        while(lhs != nullptr) {
            lhs->next = rhs;
            lhs = lhs->right;
            rhs = rhs->left;
        }
    }
};