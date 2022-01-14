class Solution {
public:
    
    bool isdigit(char c)
    {
        return c >= '0' && c <= '9';
    }
    int myAtoi(string s)
    {
        int i = 0;
        while (i < s.length() && s[i] == ' ')
        {
            i++;
        }
        if (i == s.length())
            return 0;
        int sign = 1;
        if (s[i] == '-')
        {
            sign *= -1;
            i++;
        }
        else if(s[i]=='+'){
            sign=1;
            i++;
        }
        
        long long int res = 0;
        while (i < s.length())
        {
                if (!isdigit(s[i]))
                {
                    break;
                }
                res = res * 10 + sign *(s[i]-'0');
                if(res>INT_MAX){
                    return INT_MAX;
                }
                if (res<INT_MIN)
                {
                    return INT_MIN;
                }
                

            i++;
        }
        return res ;
    }
};