class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0,j=0,n=pushed.size();
        for(;i<n && j<n;){
            if(!st.empty() && st.top()==popped[j]){
                st.pop();
                j++;
            }else{
                st.push(pushed[i]);
                i++;
            }
        }
        while(j<n){
            if(st.top()!=popped[j]){
                return false;
            }
            st.pop();
            j++;
        }
        return true;
    }
};