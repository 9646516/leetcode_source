// id:374984139
// runtime:268 ms
// memory:12.4 MB
// title:Max Submatrix LCCI
// translatedTitle:最大子矩阵
// questionId:1000046
// time:2022-10-20 22:46:44

class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        const int N=matrix.size();
        const int M=matrix.front().size();
        for(int i=0;i<N;i++){
            for(int j=1;j<M;j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans=-2e9;
        vector<int>ret;
        vector<int>V;
        for(int i=0;i<M;i++){
            for(int j=i;j<M;j++){
                V.clear();
                for(int k=0;k<N;k++){
                    int val=matrix[k][j];
                    if(i)val-=matrix[k][i-1];
                    V.push_back(val);
                }
                int mx=-1e9,pos;
                int now=0;
                for(int i=0;i<N;i++){
                    now=max(now,0)+V[i];
                    if(now>mx){
                        mx=now;
                        pos=i;
                    }
                }
                int s;
                now=mx;
                for(int i=pos;i>=0;i--){
                    now-=V[i];
                    if(now==0){
                        s=i;
                        break;
                    }
                }
                if(mx>ans){
                    ans=mx;
                    ret={s,i,pos,j};
                }
            }
        }
        return ret;
    }
};