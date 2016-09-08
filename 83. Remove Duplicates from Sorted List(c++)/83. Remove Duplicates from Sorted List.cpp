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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        } 
        if(head->val == head->next->val) {
            return deleteDuplicates(head->next);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};