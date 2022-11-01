// id:374986926
// runtime:4 ms
// memory:6.1 MB
// title:机器人的运动范围  LCOF
// translatedTitle:机器人的运动范围
// questionId:100281
// time:2022-10-20 22:55:35

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
class Solution {
public:
    int calc(int x){
        int ret=0;
        while(x){
            ret+=x%10;
            x/=10;
        }
        return ret;
    }
    int movingCount(int m, int n, int k) {
        int vis[111][111];
        memset(vis,0,sizeof(vis));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty()){
            auto [a,b]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int x=a+dx[i];
                int y=b+dy[i];
                if(x>=0&&x<n&&y>=0&&y<m&&!vis[x][y]&&calc(x)+calc(y)<=k){
                    q.push({x,y});
                    vis[x][y]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)ans+=vis[i][j];
        return ans;
    }
};