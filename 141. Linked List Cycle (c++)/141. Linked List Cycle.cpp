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
    bool hasCycle(ListNode *head) {
        if(head == nullptr) {
            return false;
        }
        auto step1 = head, step2 = head;
        while(step1->next != nullptr && step2->next != nullptr && step2->next->next != nullptr) {
            step1 = step1->next;
            step2 = step2->next->next;
            if(step1 == step2) {
                return true;
            }
        }
        return false;
    }
};


