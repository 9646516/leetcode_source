// id:373804341
// runtime:148 ms
// memory:65.4 MB
// title:二维子矩阵的和
// translatedTitle:二维子矩阵的和
// questionId:1000249
// time:2022-10-17 14:29:13

class NumMatrix {
public:
    int N,M;
    vector<vector<int>>V;
    NumMatrix(vector<vector<int>>& matrix) {
        V=matrix;
        N=V.size();
        M=V.front().size();
        for(int i=0;i<N;i++){
            for(int j=1;j<M;j++){
                V[i][j]+=V[i][j-1];
            }
        }
        for(int i=1;i<N;i++){
            for(int j=0;j<M;j++){
                V[i][j]+=V[i-1][j];
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
        int ret=V[c][d];
        if(a)ret-=V[a-1][d];
        if(b)ret-=V[c][b-1];
        if(a&&b)ret+=V[a-1][b-1];
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */