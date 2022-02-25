class Solution {
public:
    int compareVersion(string v1, string v2) {
          
        int n=v1.length(),m=v2.length();
        int i=0,j=0;
        while(i<n && j<m){
            while(i<n && v1[i]=='0'){
                i++;
            }
            
            while(j<m && v2[j]=='0'){
                j++;
            }
            int x1=0,x2=0;
            while(i<n && v1[i]!='.'){
                x1=x1*10+v1[i]-'0';
                i++;
            }
            
            while(j<m && v2[j]!='.'){
                x2=x2*10+v2[j]-'0';
                j++;
            }
            if(x1<x2){
                return -1;
            }else if(x1>x2){
                return 1;
            }
            i++;
            j++;
        }
        while(i<n){
            while(i<n && v1[i]=='0'){
                i++;
            }
            int x1=0,x2=0;
            while(i<n && v1[i]!='.'){
                x1=x1*10+v1[i]-'0';
                i++;
            }
            if(x1<x2){
                return -1;
            }else if(x1>x2){
                return 1;
            }
            i++;
        }
        
        while(j<m){
            while(j<m && v2[j]=='0'){
                j++;
            }
            int x1=0,x2=0;
            while(j<m && v2[j]!='.'){
                x2=x2*10+v2[j]-'0';
                j++;
            }
            if(x1<x2){
                return -1;
            }else if(x1>x2){
                return 1;
            }
            j++;
        }
        return 0;
    }
};