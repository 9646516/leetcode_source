// id:374589110
// runtime:8 ms
// memory:9.3 MB
// title:Robot in a Grid LCCI
// translatedTitle:迷路的机器人
// questionId:1000011
// time:2022-10-19 19:40:23

pair<int,int> fa[111][111];
int dis[111][111];
class Solution {
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& V) {
        const int N=V.size();
        const int M=V.front().size();
        if(V[0][0])return {};
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++){
                fa[i][j]={-1,-1};
                dis[i][j]=1e9;
            }
        queue<tuple<int,int,int>>q;
        q.push({0,0,0});
        dis[0][0]=0;
        const int dx[]={1,0};
        const int dy[]={0,1};
        while(!q.empty()){
            auto [d,x,y]=q.front();
            q.pop();
            for(int i=0;i<2;i++){
                int x2=x+dx[i];
                int y2=y+dy[i];
                if(x2>=0&&x2<N&&y2>=0&&y2<M&&V[x2][y2]==0){
                    if(dis[x2][y2]>d+1){
                        dis[x2][y2]=d+1;
                        q.push({d+1,x2,y2});
                        fa[x2][y2]={x,y};
                    }
                }
            }
        }
        if(dis[N-1][M-1]>1e8)return {};
        vector<vector<int>>ret;
        int x=N-1,y=M-1;
        while(x!=-1){
            ret.push_back({x,y});
            auto [a,b]=fa[x][y];
            x=a;y=b;
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};