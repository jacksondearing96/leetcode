class MyStack {
public:
    
    static constexpr int ERROR = -1;
    
    queue<int> q1;
    queue<int> q2;
    bool is_using_q1 = true;
    
    queue<int>& CurrentQueue() {
        return is_using_q1 ? q1 : q2;
    }
    
    queue<int>& CurrentAuxillary() {
        return is_using_q1 ? q2 : q1;
    }
    
    void SwitchCurrentQueue() {
        is_using_q1 = !is_using_q1;
    }
    
    int TransferContentsExceptLast(queue<int>& q, queue<int>& auxillary) {
        if (q.empty()) return ERROR;
        
        // Transfer every element except for the last element.
        while (q.size() > 1) {
            auxillary.push(q.front());
            q.pop();
        }
        
        int last = q.front();
        q.pop();
        
        return last;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        CurrentQueue().push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int last = TransferContentsExceptLast(CurrentQueue(), CurrentAuxillary());
        SwitchCurrentQueue();
        return last;
    }
    
    /** Get the top element. */
    int top() {
        int last = TransferContentsExceptLast(CurrentQueue(), CurrentAuxillary());
        CurrentAuxillary().push(last);
        SwitchCurrentQueue();
        return last;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return CurrentQueue().empty(); 
    }
};
​
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
