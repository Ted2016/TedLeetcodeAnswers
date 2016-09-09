/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        struct ListNode* lhs = head, *rhs = head;
        for(int i = 0; i < n; i++) {
            rhs = rhs->next;
        }
        if(rhs == NULL) {
            return head->next;
        }
        while(rhs->next != NULL) {
            lhs = lhs->next;
            rhs = rhs->next;
        }
        lhs->next = lhs->next->next;
        return head;
    }
