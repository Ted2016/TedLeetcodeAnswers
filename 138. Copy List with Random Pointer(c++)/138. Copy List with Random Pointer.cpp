/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr) {
            return nullptr;
        }
        RandomListNode* work = head;
        unordered_map<RandomListNode*, RandomListNode*> hash;
        RandomListNode* prev = new RandomListNode(work->label);
        hash[work] = prev;
        work = work->next;
        while(work != nullptr) {
            RandomListNode* newNode = new RandomListNode(work->label);
            prev->next = newNode;
            prev = newNode;
            hash[work] = prev;
            work = work->next;
        }
        
        work = head;
        while(work != nullptr) {
            if(work->random != nullptr) {
                hash[work]->random = hash[work->random];
            }
            work = work->next;
        }
        return hash[head];
    }
};





