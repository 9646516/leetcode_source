// id:374305573
// runtime:4 ms
// memory:6.8 MB
// title:Rotate Matrix LCCI
// translatedTitle:旋转矩阵
// questionId:100185
// time:2022-10-18 21:41:44

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int N=matrix.size();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i+j>=N)break;
                swap(matrix[i][j],matrix[N-1-j][N-1-i]);
            }
        }
        for(int i=0;i<N;i++){
            int D=N-1-i;
            if(i>=D)break;
            for(int j=0;j<N;j++){
                swap(matrix[i][j],matrix[D][j]);
            }
        }
    }
};