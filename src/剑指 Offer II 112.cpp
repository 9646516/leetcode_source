// id:374275950
// runtime:324 ms
// memory:46.5 MB
// title:最长递增路径
// translatedTitle:最长递增路径
// questionId:1000308
// time:2022-10-18 20:29:32

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int dp[202][202];
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const int N=matrix.size();
        const int M=matrix.front().size();
        queue<tuple<int,int,int>>q;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                q.push({1,i,j});
                dp[i][j]=1;
            }
        }
        while(!q.empty()){
            auto [d,x,y]=q.front();
            q.pop();
            if(dp[x][y]>d)continue;
            for(int i=0;i<4;i++){
                int x2=x+dx[i];
                int y2=y+dy[i];
                if(x2>=0&&x2<N&&y2>=0&&y2<M&&matrix[x2][y2]>matrix[x][y]&&dp[x2][y2]<d+1){
                    dp[x2][y2]=d+1;
                    q.push({d+1,x2,y2});
                }
            }
        }
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};