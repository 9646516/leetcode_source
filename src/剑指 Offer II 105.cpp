// id:374237560
// runtime:12 ms
// memory:22.7 MB
// title:岛屿的最大面积
// translatedTitle:岛屿的最大面积
// questionId:1000291
// time:2022-10-18 18:25:56

class Solution {
public:
    int fa[50*50+5];
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    #define IDX(x,y) ((x)*(M)+(y))
    int maxAreaOfIsland(vector<vector<int>>& V) {
        const int N=V.size();
        const int M=V.front().size();
        const int dx[]={1,0};
        const int dy[]={0,1};
        for(int i=0;i<N*M;i++)fa[i]=i;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(V[i][j]){
                    for(int k=0;k<2;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(x>=0&&x<N&&y>=0&&y<M&&V[x][y]){
                            int fa1=seek(IDX(i,j));
                            int fa2=seek(IDX(x,y));
                            fa[fa1]=fa2;
                        }
                    }
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(V[i][j]){
                    mp[seek(IDX(i,j))]++;
                }
            }
        }
        int ans=0;
        for(auto&i:mp)ans=max(ans,i.second);
        return ans;
    }
};