class MinStack {
    stack<long long int> st;
        long long int Min=0;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            Min = val;
        }
        else if(val>=Min){
            st.push(val);
        }
        else{
            st.push((long long)2*val-Min);
            Min = val;
        }
    }
    
    void pop() {
        if(st.top()>=Min){
            st.pop();
        }
        else{
            Min = 2*Min - st.top();
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<Min) return Min;
        else return st.top();
    }
    
    int getMin() {
        return Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */