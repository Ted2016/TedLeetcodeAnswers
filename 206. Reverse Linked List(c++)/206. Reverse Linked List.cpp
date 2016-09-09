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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* curr = head;
        ListNode* next = curr->next;
        curr->next = nullptr;
        while(next != nullptr) {
            ListNode* tmp = next->next;
            next->next = curr;
            curr = next;
            next = tmp;
        }
        return curr;
    }
};