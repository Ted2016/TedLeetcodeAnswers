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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        auto start = head, tail = start;
        if(m != 1) {
            for(int i = 2; i < m; i++) {
                start = start->next;
            }
            tail = start->next;
        }
        auto cur = tail;
        auto next = cur->next;
        for(int i = m; i < n; i++) {
            auto tmp = next->next;
            next->next = cur;
            cur = next;
            next = tmp;
        }
        tail->next = next;
        if(m == 1) {
            return cur;
        } else {
            start->next = cur;
            return head;
        }
    }
};