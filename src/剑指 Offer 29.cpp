// id:373298157
// runtime:8 ms
// memory:10.4 MB
// title:顺时针打印矩阵  LCOF
// translatedTitle:顺时针打印矩阵
// questionId:100293
// time:2022-10-15 20:48:49

class Solution {
public:
    vector<vector<int>>V;
    vector<int>ret;
    void solve(int x1,int y1,int x2,int y2){
        if(x1>x2||y1>y2)return;
        if(x1==x2){
            for(int i=y1;i<=y2;i++){
                ret.push_back(V[x1][i]);
            }
            return;
        }
        if(y1==y2){
            for(int i=x1;i<=x2;i++){
                ret.push_back(V[i][y1]);
            }
            return;
        }
        for(int i=y1;i<=y2;i++){
            ret.push_back(V[x1][i]);
        }
        for(int i=x1+1;i<=x2;i++){
            ret.push_back(V[i][y2]);
        }
        for(int i=y2-1;i>=y1;i--){
            ret.push_back(V[x2][i]);
        }
        for(int i=x2-1;i>x1;i--){
            ret.push_back(V[i][y1]);
        }
        solve(x1+1,y1+1,x2-1,y2-1);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())return ret;
        V=matrix;
        const int N=matrix.size();
        const int M=matrix.front().size();
        solve(0,0,N-1,M-1);
        return ret;
    }
};