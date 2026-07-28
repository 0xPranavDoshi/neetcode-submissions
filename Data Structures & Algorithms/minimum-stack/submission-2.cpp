class MinStack {
public:
    stack<int> s;
    stack<int> ms;

    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (ms.empty() || val <= ms.top()) {
            ms.push(val);
        }
    }
    
    void pop() {
        if (s.top() == ms.top()) {
            ms.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms.empty() ? 0 : ms.top();
    }
};
