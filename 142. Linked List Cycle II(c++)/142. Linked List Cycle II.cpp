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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        ListNode* step1 = head->next;
        ListNode* step2 = head->next->next;
        while(step2 != nullptr && step2->next != nullptr) {
            if(step1 == step2) {
                break;
            }
            step1 = step1->next;
            step2 = step2->next->next;
        }
        if(step2 == nullptr || step2->next == nullptr) {
            return nullptr;
        }
        step1 = head;
        while(step1 != step2) {
            step1 = step1->next;
            step2 = step2->next;
        }
        return step1;
    }
};

