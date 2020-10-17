class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    void fillOutputStackIfRequired() {
        if (output_stack.empty()) {
            while (input_stack.empty() == false) {
                output_stack.push(input_stack.top());
                input_stack.pop();
            }
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input_stack.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        fillOutputStackIfRequired();
        int top = output_stack.top();
        output_stack.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        fillOutputStackIfRequired();
        return output_stack.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input_stack.empty() && output_stack.empty();
    }
    
    std::stack<int> input_stack;
    std::stack<int> output_stack;
};
​
/**
 * Your MyQueue object will be instantiated and called as such:
