class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    int popping(queue<int>& q1, queue<int>& q2, int top){
        int val;
        while(q1.size()!=1){
            int el = q1.front();
            q1.pop();
            q2.push(el);
        }
        val = q1.front();
        q1.pop();
        if(top==1) q2.push(val);
        return val;
    }

    void push(int x) {
        if(q2.empty()) q1.push(x);
        else q2.push(x);
    }
    
    int pop() {
        if(q2.empty()) return popping(q1,q2,0);
        else return popping(q2,q1,0);
    }
    
    int top() {
        if(q2.empty()) return popping(q1,q2,1);
        else return popping(q2,q1,1);
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
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