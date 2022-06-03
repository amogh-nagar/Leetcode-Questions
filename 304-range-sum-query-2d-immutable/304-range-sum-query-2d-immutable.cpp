class NumMatrix {
public:
    vector<vector<int>> matrix;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(j-1>=0){
                    matrix[i][j]+=matrix[i][j-1];
                }
                if(i-1>=0){
                    matrix[i][j]+=matrix[i-1][j];
                }
                if(i-1>=0 && j-1>=0){
                    matrix[i][j]-=matrix[i-1][j-1];
                }
            }
        }
        this->matrix=matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int x=matrix[row2][col2];
        if(row1-1>=0){
            x-=matrix[row1-1][col2];
        }
        if(col1-1>=0){
            x-=matrix[row2][col1-1];
        }
        if(row1-1>=0 && col1-1>=0){
            x+=matrix[row1-1][col1-1];
        }
        return x;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */