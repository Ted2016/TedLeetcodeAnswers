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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* workA = headA, *workB = headB;
        while(workA != nullptr && workB != nullptr) {
            workA = workA->next;
            workB = workB->next;
        }
        ListNode* work1, *work2;
        if(workA == nullptr) {
            work1 = headB;
            work2 = headA;
            while(workB != nullptr) {
                workB = workB->next;
                work1 = work1->next;
            }
        } else if (workB == nullptr) {
            work1 = headA;
            work2 = headB;
            while(workA != nullptr) {
                workA = workA->next;
                work1 = work1->next;
            }
        }
         while(work1 != nullptr  && work1 != work2) {
            work1 = work1->next;
            work2 = work2->next;
        }
        return work1 == work2 ? work1 : nullptr;
    }
};



