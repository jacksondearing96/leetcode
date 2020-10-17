constexpr int ERROR_VAL = 99999;
​
class MinStack {
public:
    struct Node {
        int value;
        Node* next = nullptr;
    };
    
    Node* topNode = nullptr;
    int minValue;
    std::stack<int> minimumValues;
    
    /** initialize your data structure here. */
    MinStack() {
        minValue = ERROR_VAL;
    }
    
    void push(int x) {
​
        if (minimumValues.empty() || x < minimumValues.top()) {
            minimumValues.push(x);
        } else {
            minimumValues.push(minimumValues.top());
        }
        
        Node* newTop = new Node();
        newTop->value = x;
        newTop->next = topNode;
        topNode = newTop;
    }
    
    void pop() {
        if (topNode == nullptr) return;
        Node* nodeToPop = topNode;
        topNode = topNode->next;
        delete nodeToPop;
        minimumValues.pop();
    }
    
    int top() {
        if (topNode == nullptr) return ERROR_VAL;
        return topNode->value;
    }
    
    int getMin() {
