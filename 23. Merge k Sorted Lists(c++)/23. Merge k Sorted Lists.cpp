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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists_help(lists.begin(), lists.end());
    }
    
    ListNode* mergeKLists_help(vector<ListNode*>::iterator lhs, vector<ListNode*>::iterator rhs) {
        if(lhs >= rhs) {
            return nullptr;
        } else if (lhs+1 == rhs) {
            return *lhs;
        }
        int mid = (rhs-lhs)>>1;
        return mergeTwoLists(mergeKLists_help(lhs, lhs+mid), mergeKLists_help(lhs+mid, rhs));
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } 
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};