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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result{};
        if(root == nullptr) {
            return result;
        }
        bool dir = true;
        vector<TreeNode*> nodes{root};
        while(!nodes.empty()) {
            vector<int> ints;
            for(auto node : nodes) {
                ints.push_back(node->val);
            }
            result.push_back(ints);
            vector<TreeNode*> new_nodes;
            if(dir) {
                for(auto iter = nodes.rbegin(); iter != nodes.rend(); iter++) {
                    auto node = *iter;
                    if(node->right != nullptr) {
                        new_nodes.push_back(node->right);
                    }
                    if(node->left != nullptr) {
                        new_nodes.push_back(node->left);
                    }
                }
                    
            } else {
                for(auto iter = nodes.rbegin(); iter != nodes.rend(); iter++) {
                    auto node = *iter;
                    if(node->left != nullptr) {
                        new_nodes.push_back(node->left);
                    }
                    if(node->right != nullptr) {
                        new_nodes.push_back(node->right);
                    }
                }
            }
            dir = !dir;
            nodes = new_nodes;
        }
        return result;
    }
};