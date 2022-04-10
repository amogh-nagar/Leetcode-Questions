class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto i:ops){
            if(i=="C"){
                st.pop();
            }else if(i=="D"){
                int x=st.top();
                st.push(2*x);
            }else if(i=="+"){
                int x=st.top();st.pop();
                int y=st.top();
                st.push(x);
                st.push(x+y);
            }else{
                st.push(stoi(i));
            }
        }
        int a=0;
        while(!st.empty()){
            a+=st.top();st.pop();
        }
        return a;
    }
};