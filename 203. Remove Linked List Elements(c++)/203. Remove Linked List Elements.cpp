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
    ListNode* removeElements(ListNode* head, int val) {
        auto cur = head;
        ListNode tmp = ListNode(0);
        ListNode* prev = &tmp;
        while(cur != nullptr) {
            while(cur != nullptr && cur->val == val) {
                cur = cur->next;
            }
            prev->next = cur;
            if(cur == nullptr) {
                break;
            }
            while(cur != nullptr && cur->val != val) {
                prev = cur;
                cur = cur->next;
            }
        }
        return tmp.next;
    }
};