// id:373279399
// runtime:148 ms
// memory:6.1 MB
// title:矩阵中的路径  LCOF
// translatedTitle:矩阵中的路径
// questionId:100279
// time:2022-10-15 19:40:11

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
class Solution {
public:
    int N,M;
    string cmp;
    vector<vector<char>>V;
    int vis[7][7];
    bool dfs(int x,int y,int pos){
        if(pos==cmp.size()){
            return 1;
        }
        for(int i=0;i<4;i++){
            int x2=x+dx[i];
            int y2=y+dy[i];
            if(x2>=0&&x2<N&&y2>=0&&y2<M&&V[x2][y2]==cmp[pos]&&!vis[x2][y2]){
                vis[x2][y2]=1;
                if(dfs(x2,y2,pos+1)){
                    return 1;
                }
                vis[x2][y2]=0;
            }
        }
        return 0;
    }
    bool exist(vector<vector<char>>& board, string word) {
        cmp=word;
        V=board;
        N=V.size();
        M=V.front().size();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                if(V[i][j]==word[0]){
                        vis[i][j]=1;
                        if(dfs(i,j,1))
                            return 1;
                        vis[i][j]=0;
                    }
        return 0;
    }
};