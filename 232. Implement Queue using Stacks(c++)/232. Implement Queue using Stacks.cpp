class Queue {
private:
    stack<int> stk1;
    stack<int> stk2;
    int top;
public:
    // Push element x to the back of queue.
    void push(int x) {
        if(empty()) {
            top = x;
        }
        stk1.push(x);
        
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk2.pop();
        if(!stk2.empty()) {
            top = stk2.top();
        }
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        return top;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk1.empty();
    }
};