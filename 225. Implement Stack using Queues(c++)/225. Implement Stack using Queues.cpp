class Stack {
private:
    queue<int> q1;
    queue<int> q2;
    bool isfirst = true;
    int size = 0;
public:
    // Push element x onto stack.
    void push(int x) {
        isfirst ? q1.push(x) : q2.push(x);
        size++;
    }

    // Removes the element on top of the stack.
    void pop() {
        if(isfirst) {
            for(int i = 0; i < size-1; i++) {
                q2.push(q1.front());
                q1.pop();
            }
            isfirst = false;
        } else {
            for(int i = 0; i < size-1; i++) {
                q1.push(q2.front());
                q2.pop();
            }
            isfirst = true;
        }
        size--;
    }

    // Get the top element.
    int top() {
        return isfirst ? q1.back() : q2.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return size == 0;
    }
};