class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxi=INT_MIN;
        int i=0,j=0,ct=0,cf=0;
        while(j<answerKey.length()){
            if(answerKey[j]=='T'){
                ct++;
            }
            else{
                cf++;
            }
            
            int x=min(ct,cf);
            if(x>k){
                while(x>k){
                    if(answerKey[i]=='T'){
                        ct--;
                    }else{
                        cf--;
                    }
                    i++;
                    x=min(ct,cf);
                }
            }
            else{
                maxi=max(maxi,j-i+1);
            }
            j++;
        }
        return maxi;
    }
};