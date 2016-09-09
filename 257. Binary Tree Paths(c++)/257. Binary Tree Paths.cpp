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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) {
            return vector<string>{};
        } 
        stringstream ss;
        ss << root->val;
        string str = ss.str();
        if (root->left == nullptr && root->right == nullptr ) {
            return vector<string>{str};
        } else {
            vector<string> lhs = binaryTreePaths(root->left);
            vector<string> rhs = binaryTreePaths(root->right);
            lhs.insert(lhs.end(), rhs.begin(), rhs.end());
            vector<string> ret;
            transform(lhs.begin(), lhs.end(), back_inserter(ret),
            [str](const string& s)->string{
                string new_str = str + "->" + s;
                return new_str;
            });
            return ret;
        }
        
    }
};