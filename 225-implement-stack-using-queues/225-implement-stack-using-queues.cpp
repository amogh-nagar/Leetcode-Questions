class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n=q1.size()-1;
        while(n-->0){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();q1.pop();
        while(q2.size()>0){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
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