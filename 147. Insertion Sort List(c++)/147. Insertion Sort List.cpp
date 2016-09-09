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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        auto cur = head->next;
        head->next = nullptr;
        while(cur != nullptr) {
            auto tmp = cur->next;
            auto work = head;
            auto prev = work;
            while(work!= nullptr && cur->val > work->val) {
                prev = work;
                work = work->next;
            }
            if(work == nullptr) {
                prev->next = cur;
                cur->next = nullptr;
            } else if(prev == work) {
                cur->next = work;
                head = cur;
            } else {
                prev->next = cur;
                cur->next = work;
            }
            cur = tmp;
        }
        return head;
    }
};
