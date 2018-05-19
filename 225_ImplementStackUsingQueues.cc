class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        ;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        Queue1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(Queue1.size() != 1)
        {
            int tmp = Queue1.front();
            Queue1.pop();
            Queue2.push(tmp);
        }
        
        int res = Queue1.front();
        Queue1.pop();
        
        while(!Queue2.empty())
        {
            int tmp = Queue2.front();
            Queue2.pop();
            Queue1.push(tmp);
        }
        
        return res;
    }
    
    /** Get the top element. */
    int top() {
        
        while(Queue1.size() != 1)
        {
            int tmp = Queue1.front();
            Queue1.pop();
            Queue2.push(tmp);
        }
        
        int res = Queue1.front();
        Queue1.pop();
        Queue2.push(res);
        
        while(!Queue2.empty())
        {
            int tmp = Queue2.front();
            Queue2.pop();
            Queue1.push(tmp);
        }
        
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        
        return Queue1.empty();
    }
private:
    queue<int> Queue1;
    queue<int> Queue2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
