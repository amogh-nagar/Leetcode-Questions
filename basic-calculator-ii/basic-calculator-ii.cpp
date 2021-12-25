class Solution
{
public:
    int calculate(string s)
    {
        string p;
        char x='+';
        stack<int> oped;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                p+=s[i];
            }
            else if (s[i] == ' ')
            {
                continue;
            }
            else{
                int r;
                if(p==""){
                    r=0;
                }
                r=stoi(p);
                p="";
                if(x=='+'){
                    oped.push(r);
                }
                else if(x=='-'){
                    oped.push(-1*r);
                }
                else if(x=='*'){
                    int y=oped.top();
                    oped.pop();
                    oped.push(y*r);
                }
                else if(x=='/'){
                    int y=oped.top();
                    oped.pop();
                    oped.push(y/r);
                }
                x=s[i];
            }
            
        }
                        int r=stoi(p);

        if(x=='+'){
                    oped.push(r);
                }
                else if(x=='-'){
                    oped.push(-1*r);
                }
                else if(x=='*'){
                    int y=oped.top();
                    oped.pop();
                    oped.push(y*r);
                }
                else if(x=='/'){
                    int y=oped.top();
                    oped.pop();
                    oped.push(y/r);
                }
        r = 0;
            while (!oped.empty())
                {
                r+=oped.top();
                    oped.pop();
                    
                }
               return r;
    }
};