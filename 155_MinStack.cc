class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        ;
    }
    
    void push(int x) {
        Stack.push(x);
        
        if(Stack2.empty())
            Stack2.push(x);
        else
        {
            int nowMin = Stack2.top();
            if(x > nowMin)
                Stack2.push(Stack2.top());
            else
                Stack2.push(x);
        }
    }
    
    void pop() {
        Stack.pop();
        Stack2.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return Stack2.top();
    }

private:
    stack<int> Stack;
    stack<int> Stack2;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
