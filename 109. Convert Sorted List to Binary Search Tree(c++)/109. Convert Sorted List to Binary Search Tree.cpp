/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) {
            return nullptr;
        } else if(head->next == nullptr) {
            TreeNode* node = new TreeNode(head->val);
            return node;
        }
        int size = 0;
        auto cur = head;
        while(cur != nullptr) {
            size++;
            cur = cur->next;
        }
        int mid = size>>1;
        cur = head;
        for(int i = 0; i < mid-1; i++) {
            cur = cur->next;
        }
        auto rhs = cur->next->next;
        TreeNode* node = new TreeNode(cur->next->val);
        cur->next = nullptr;
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(rhs);
        return node;
    }
};
