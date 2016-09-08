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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0) {
            return head;
        }
        int size = 0;
        auto curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
            size++;
        }
        auto tail = curr;
        size++;
        k %= size;
        curr = head;
        if(k == 0) {
            return head;
        }
        int i = 1;
        while(curr != nullptr && i < size-k) {
            curr = curr->next;
            i++;
        }
        auto next = curr->next;
        tail->next = head;
        curr->next = nullptr;
        return next;
        

    }
};