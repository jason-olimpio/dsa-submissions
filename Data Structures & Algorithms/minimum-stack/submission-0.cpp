class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;

    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
