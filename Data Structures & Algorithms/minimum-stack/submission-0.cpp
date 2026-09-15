class MinStack {
public:
    stack<int>st;
    vector<int>minis = {INT_MAX};
    MinStack() {
        
    }
    
    void push(int val) {
        if(val <= minis.back())
            minis.push_back(val);
        st.push(val);
    }
    
    void pop() {
        if(st.top() == minis.back()){
            minis.pop_back();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minis.back();
    }
};
