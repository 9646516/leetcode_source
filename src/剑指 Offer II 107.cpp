// id:374239799
// runtime:68 ms
// memory:29.4 MB
// title:矩阵中的距离
// translatedTitle:矩阵中的距离
// questionId:1000296
// time:2022-10-18 18:36:26

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int N=mat.size();
        const int M=mat.front().size();
        vector<vector<int>>dis(N,vector<int>(M,1e9));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(mat[i][j]==0){
            dis[i][j]=0;
            q.push({0,i,j});
        }
        const int dx[]={1,-1,0,0};
        const int dy[]={0,0,1,-1};
        while(!q.empty()){
            auto [d,x,y]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x2=x+dx[i];
                int y2=y+dy[i];
                if(x2>=0&&x2<N&&y2>=0&&y2<M){
                    if(dis[x2][y2]>d+1){
                        dis[x2][y2]=d+1;
                        q.push({d+1,x2,y2});
                    }
                }
            }
        }
        return dis;
    }
};