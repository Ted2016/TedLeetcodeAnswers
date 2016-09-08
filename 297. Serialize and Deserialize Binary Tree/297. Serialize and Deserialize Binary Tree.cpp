/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            auto node = que.front();
            que.pop();
            if(node != nullptr) {
                str = str+to_string(node->val)+",";
                que.push(node->left);
                que.push(node->right);
            } else {
                str = str+"null,";
            }
        }
        str.pop_back();
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> strs;
        size_t begin = 0, pos = data.find_first_of(',', begin);
        while(pos != string::npos) {
            strs.push_back(data.substr(begin, pos-begin));
            begin = pos+1;
            pos = data.find_first_of(',', begin);
        }
        strs.push_back(data.substr(begin, data.size()-begin));
        if(strs.front() == "null") {
            return nullptr;
        }
        auto root = new TreeNode(atoi(strs.front().c_str()));
        queue<TreeNode*> que;
        que.push(root);
        int i = 1;
        while(!que.empty()) {
            auto node = que.front();
            que.pop();
                if(strs[i] == "null") {
                    node->left = nullptr;
                } else {
                    node->left = new TreeNode(atoi(strs[i].c_str()));
                    que.push(node->left);
                }
                i++;
                if(strs[i] == "null") {
                    node->right = nullptr;
                } else {
                    node->right = new TreeNode(atoi(strs[i].c_str()));
                    que.push(node->right);
                }
                i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));