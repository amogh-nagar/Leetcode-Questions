class Solution {
public:
    int find(string s){
        int a[26]={0};
        for(int i=0;i<s.length();i++){
            a[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]!=0){
                return a[i];
            }
        }
        return 0;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> v;
        
        for(auto x:words){
           int c=find(x);
            v.push_back(c);
        }
        sort(v.begin(),v.end());
        vector<int> res;
        for(auto x:queries){
            int c=find(x);
            
            int l=0,h=v.size()-1;
            int ans=-1;
            while(l<=h){
                int m=(l+h)/2;
                if(v[m]<=c){
                    l=m+1;
                 
                }else{
                    ans=m;
                    h=m-1;
                }
            }
            res.push_back(ans==-1?0:v.size()-ans);
        }
            return res;
        
    }
};