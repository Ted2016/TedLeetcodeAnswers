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
    void reorderList(ListNode* head) {
        if(head == nullptr) {
            return;
        }
        ListNode* mid = head;
        ListNode* last = head;
        while(last->next != nullptr && last->next->next != nullptr) {
            mid = mid->next;
            last = last->next->next;
        }
        ListNode* head_2 = revertList(mid->next);
        mid->next = nullptr;
        while(head != nullptr && head_2 != nullptr) {
            auto tmp1 = head->next, tmp2 = head_2->next;
            head->next = head_2;
            head_2->next = tmp1;
            head = tmp1;
            head_2 = tmp2;
        }
    }
    
    ListNode* revertList(ListNode* head) {
        if(head == nullptr) {
            return head;
        }
        ListNode* next = head->next;
        head->next = nullptr;
        while(next != nullptr) {
            ListNode* tmp = next->next;
            next->next = head;
            head = next;
            next = tmp;
        }
        return head;
    }
};