class Solution {
public:
    int numSplits(string s) {
        int ans=0;
        vector<int> prefix(26,0),suffix(26,0);
        int left=0;
        for(int i=0;i<s.length();i++){
            if(prefix[s[i]-'a']==0){
                left++;
            }
            prefix[s[i]-'a']++;
        }
        
        int right=0;
        for(int i=s.length()-1;i>=0;i--){
            if(left==right){
                ans++;
            }
            
            
            if(suffix[s[i]-'a']==0){
                right++;
            }
            suffix[s[i]-'a']++;
            prefix[s[i]-'a']--;
            if(prefix[s[i]-'a']==0){
                left--;
            }
        }
        
        return ans;
    }
};