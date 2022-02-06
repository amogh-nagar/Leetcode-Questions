class CustomStack {
public:
    int y;
    stack<int> st;
    CustomStack(int maxSize) {
        y=maxSize;
    }
    
    void push(int x) {
        if(st.size()==y){
            return;
        }
        st.push(x);
    }
    
    int pop() {
        if(st.empty()){
            return -1;
        }
        int x=st.top();
        st.pop();
        return x;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(k>0 && !temp.empty()){
            int x=temp.top();
            x+=val;
            st.push(x);
            temp.pop();
            k--;
        }
        while(!temp.empty()){
            st.push(temp.top());
            temp.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */