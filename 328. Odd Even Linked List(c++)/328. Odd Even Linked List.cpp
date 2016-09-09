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
        ListNode* oddEvenList(ListNode* head) {
            ListNode* odd = head;
            ListNode* even;
            ListNode*  even_first;
            if(head == NULL) {
                return head;
            }  else {
                even_first = head->next;
                even = even_first;
            }
            while (even != NULL && even->next != NULL) {
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            odd->next = even_first;
            return head;
        }
   };