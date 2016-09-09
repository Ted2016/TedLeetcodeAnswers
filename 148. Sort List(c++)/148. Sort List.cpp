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
    pair<ListNode*, ListNode*> sortList_help(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return make_pair(head, head);
        }
        ListNode* lhs = nullptr, *rhs = nullptr, *cur = head->next, *rhs_cur = nullptr
        , *lhs_cur = nullptr, *tail;
        while(cur != nullptr) {
            if(cur->val >= head->val) {
                if(rhs == nullptr) {
                    rhs = cur;
                    rhs_cur = rhs;
                } else {
                    rhs_cur->next = cur;
                    rhs_cur = rhs_cur->next;
                }
            } else {
                if(lhs == nullptr) {
                    lhs = cur;
                    lhs_cur = lhs;
                } else {
                    lhs_cur->next = cur;
                    lhs_cur = lhs_cur->next;
                }
            }
            cur = cur->next;
        }
        if(rhs_cur != nullptr) {
            rhs_cur->next = nullptr;
        }
        if(lhs_cur != nullptr) {
            lhs_cur->next = nullptr;
        }
        auto pair_1 = sortList_help(rhs);
        auto pair_2 = sortList_help(lhs);
        if(pair_1.first == nullptr) {
            tail = head;
        } else {
            tail = pair_1.second;
        }
        if(pair_2.first == nullptr) {
            head->next = pair_1.first;
        } else {
            pair_2.second->next = head;
            head->next = pair_1.first;
            head = pair_2.first;
        }
        
        return make_pair(head, tail);
    }
   ListNode* sortList(ListNode* head) {
       return sortList_help(head).first;
   }
};
