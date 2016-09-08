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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret{};
        if(root == nullptr) {
            return ret;
        }
        vector<TreeNode*> nodes {root};
        while(!nodes.empty()) {
            vector<int> vals;
            vector<TreeNode*> new_nodes;
            for(auto node : nodes) {
                vals.push_back(node->val);
                if(node->left != nullptr) {
                    new_nodes.push_back(node->left);
                } 
                if(node->right != nullptr) {
                    new_nodes.push_back(node->right);
                }
            }
            ret.push_back(vals);
            nodes = new_nodes;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};