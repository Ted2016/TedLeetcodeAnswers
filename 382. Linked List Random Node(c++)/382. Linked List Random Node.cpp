class Solution {
public:
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* cur = head;
        int result;
        int i = 1;
        while(cur != nullptr) {
            if(rand()%i == 0) {
                result = cur->val;
            }
            i++;
            cur = cur->next;
        }
        return result;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */