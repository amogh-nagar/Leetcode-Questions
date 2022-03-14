class Solution {
public:
string simplifyPath(string path)
{
    stack<string> st;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            i++;
            string temp;
            while (i < path.length() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }
            if (temp == "..")
            {
                if(!st.empty()){
                st.pop();
                }            
            }
            else if (temp != "" && temp!=".")
            {
                st.push(temp);
            }
            i--;
        }
    }
    string res;
    if(st.empty()){
        res+="/";
    }
    stack<string> t;
    while (!st.empty())
    {
        t.push(st.top());
        st.pop();
    }
    while(!t.empty()){
        res+="/";
        res+=t.top();
        t.pop();
    }
    return res;
}
};