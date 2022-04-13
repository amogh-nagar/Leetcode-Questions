class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int lt=0,rt=n-1,lb=n-1,rb=n-1;
        vector<vector<int>> res(n,vector<int>(n,0));
        int v=1;
        
        do{
           for(int i=lt;i<=rt;i++){
               res[lt][i]=v++;
               
           }    
           for(int i=lt+1;i<=rb;i++){
               res[i][rb]=v++;
           } 
           for(int i=rb-1;i>=lt;i--){
               res[rb][i]=v++;
           } 
            for(int i=lb-1;i>lt;i--){
                res[i][lt]=v++;
            }
            lt++;
            rt--;
            lb--;
            rb--;
        }while(lt<=rb);
        return res;
    }
};