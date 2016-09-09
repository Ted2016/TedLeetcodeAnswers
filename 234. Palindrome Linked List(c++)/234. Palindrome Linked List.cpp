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
 bool isPalindrome (ListNode* head) {
        ListNode* temp = head;
        int size = 0;
        while(temp != NULL) {
            temp = temp->next;
            size++;
        }
        ListNode* next = head, *curr = NULL;
        for(int i = 0; i < size/2; i++) {
            ListNode* temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }
        bool ans = true;
        ListNode* rhs = next,*lhs = curr;
        if(size&1)
            rhs = next->next;
        while(lhs != NULL) {
            if(lhs->val != rhs->val) {
                ans = false;
                break;
            }
            rhs = rhs->next;
            lhs = lhs->next;
        }
        while(curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = next;
            next = curr;
            curr = temp;
        }
        return ans;
    }

};