// id:374981790
// runtime:376 ms
// memory:18.6 MB
// title:Max Black Square LCCI
// translatedTitle:最大黑方阵
// questionId:1000045
// time:2022-10-20 22:39:12

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        const int N=matrix.size();
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                matrix[i][j]^=1;
            }
        }
        vector<vector<int>>row=matrix;
        vector<vector<int>>col=matrix;
        auto get_row=[&](int i,int j1,int j2){
            int ret=row[i][j2];
            if(j1)ret-=row[i][j1-1];
            return ret;
        };
        auto get_col=[&](int j,int i1,int i2){
            int ret=col[i2][j];
            if(i1)ret-=col[i1-1][j];
            return ret;
        };
        for(int i=0;i<N;i++){
            for(int j=1;j<N;j++){
                row[i][j]+=row[i][j-1];
            }
        }
        for(int i=0;i<N;i++){
            for(int j=1;j<N;j++){
                col[j][i]+=col[j-1][i];
            }
        }
        int r,c,len=-1;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                for(int k=1;k<=N;k++){
                    if(i+k-1>=N||j+k-1>=N)break;
                    if(get_row(i,j,j+k-1)==k&&get_row(i+k-1,j,j+k-1)==k){
                        if(get_col(j,i,i+k-1)==k&&get_col(j+k-1,i,i+k-1)==k){
                            if(len<k){
                                len=k;
                                r=i;c=j;
                            }
                        }
                    }
                }
            }
        }
        if(len==-1)return {};
        return {r,c,len};
    }
};