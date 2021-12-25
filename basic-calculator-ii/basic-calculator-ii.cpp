class Solution
{
public:
    int calculate(string s)
    {
        string p;
        char x='+';
        int lastnumber=0,result=0;
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
                    result+=lastnumber;
                    lastnumber=r;
                }
                else if(x=='-'){
                    result+=lastnumber;
                    lastnumber=-1*r;
                }
                else if(x=='*'){
                    lastnumber=lastnumber*r;
                }
                else if(x=='/'){
                    
                    lastnumber=lastnumber/r;
                }
                x=s[i];
            }
            
        }
                int r=stoi(p);
                          if (x == '+')
        {
                                                result+=(lastnumber+r);
  
        }
        else if (x == '-')
        {
                  result+=(lastnumber-r);
          }
        else if (x == '*')
        {
                    result+=(lastnumber*r);
        }
        else if (x == '/')
        {
                              result+=(lastnumber/r);
  
        }
  
                
               return result;
    }
};