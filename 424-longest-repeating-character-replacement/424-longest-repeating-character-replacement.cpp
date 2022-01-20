class Solution {
public:
    int maxi(vector<int> v){
        int m=0;
        for(int i=0;i<v.size();i++){
            m=max(m,v[i]);
        }
        return m;
    }
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int c=0,i=0;
        for(int j=0;j<s.length();j++){
            v[s[j]-'A']++;
            int l=maxi(v);
                
            if((j-i+1-l)>k){
                while(j-i+1-l>k){
                    v[s[i]-'A']--;
                    i++;
                    
                }
            }
                
                c=max(c,j-i+1);
        }
        return c;
    }
};