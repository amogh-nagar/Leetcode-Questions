class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int c=0;
        vector<vector<int>> v(m,vector<int>(n,0));
        for(int i=0;i<walls.size();i++){
            v[walls[i][0]][walls[i][1]]=-1;
        }
        for(int i=0;i<guards.size();i++){
           
            v[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<guards.size();i++){
            for(int j=guards[i][0]+1;j<m;j++){
                if(v[j][guards[i][1]]==-1||v[j][guards[i][1]]==2){
                    break;
                }else{
                    v[j][guards[i][1]]=1;
                }
            }
            for(int j=guards[i][1]+1;j<n;j++){
                if(v[guards[i][0]][j]==-1||v[guards[i][0]][j]==2){
                    break;
                }else{
                    v[guards[i][0]][j]=1;
                }
            }
            for(int j=guards[i][0]-1;j>=0;j--){
                if(v[j][guards[i][1]]==-1||v[j][guards[i][1]]==2){
                    break;
                }else{
                    v[j][guards[i][1]]=1;
                }
            }
            
            for(int j=guards[i][1]-1;j>=0;j--){
                if(v[guards[i][0]][j]==-1||v[guards[i][0]][j]==2){
                    break;
                }else{
                    v[guards[i][0]][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==0){
                    c++;
                }
            }
        }
        return c;
    }
};