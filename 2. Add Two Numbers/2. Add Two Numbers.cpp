int add(int a, int b, int* c){
    int sum = a + b + *c;
    *c = sum/10;
    return sum%10;
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int extra = 0;
    struct ListNode* head = l1;
    struct ListNode* prev = l1;
    struct ListNode* backup = l2;
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;

    while(l1->next&&l2->next) { 
        l1->val = add(l1->val, l2->val, &extra);
        l1 = l1->next;
        l2 = l2->next;
    }   
    l1->val = add(l1->val, l2->val, &extra);
    prev = l1; 
    l1 = l1->next;
    l2 = l2->next;
        
    if(l1 == NULL) {
        prev->next = l2; 
    }
    while(extra) {
        if(prev->next == NULL) {
            prev->next = backup;
            prev->next->val = add(0, 0,&extra);
            prev->next->next = NULL;
            
        }
        else {
            prev->next->val = add(0, prev->next->val, &extra);
            prev = prev->next;
        }
    }

    return head;
}
