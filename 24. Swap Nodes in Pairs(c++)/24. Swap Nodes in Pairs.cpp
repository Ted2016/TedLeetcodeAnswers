/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        } else {
            auto cur = head->next;
            auto next = cur->next;
            cur->next = head;
            head->next = swapPairs(next);
            return cur;
        }
    }
};