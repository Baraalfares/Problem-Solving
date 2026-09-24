class MyStack {
public:
    queue<int>q;
    queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int sz = q.size();
        int i = 0;
        while(i < sz - 1){
            q.push(q.front());
            q.pop();
            i++;
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */