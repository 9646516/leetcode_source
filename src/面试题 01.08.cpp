// id:374306455
// runtime:12 ms
// memory:11.8 MB
// title:Zero Matrix LCCI
// translatedTitle:零矩阵
// questionId:100186
// time:2022-10-18 21:43:51

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int N=matrix.size();
        const int M=matrix.front().size();
        vector<pair<int,int>>V;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(matrix[i][j]==0)V.push_back({i,j});
        for(auto [a,b]:V){
            for(int i=0;i<N;i++){
                matrix[i][b]=0;
            }
            for(int i=0;i<M;i++){
                matrix[a][i]=0;
            }
        }
    }
};