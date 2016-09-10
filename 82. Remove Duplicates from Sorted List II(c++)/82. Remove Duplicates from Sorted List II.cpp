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
        ListNode tmp(0);
        tmp.next = head;
        auto prev = &tmp, cur = tmp.next;
        int count = 0;
        while(cur != nullptr) {
            if(cur->next == nullptr || cur->next->val != cur->val) {
                if(count == 0) {
                    prev->next = cur;
                    prev = cur;
                } else {
                    prev->next = cur->next;
                }
                count = 0;
            } else {
                count++;
            }
            cur = cur->next;
        }
        return tmp.next;
    }
};