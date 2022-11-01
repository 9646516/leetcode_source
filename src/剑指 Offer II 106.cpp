// id:374238885
// runtime:24 ms
// memory:14.1 MB
// title:二分图
// translatedTitle:二分图
// questionId:1000294
// time:2022-10-18 18:32:15

class Solution {
public:
    bool ok;
    int color[105];
    vector<vector<int>>V;
    void dfs(int x){
        if(!ok)return;
        for(int i:V[x]){
            if(color[i]==-1){
                color[i]=color[x]^1;
                dfs(i);
            }else if(color[i]==color[x]){
                ok=0;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        const int N=graph.size();
        V=graph;
        memset(color,-1,sizeof(color));
        ok=1;
        for(int i=0;i<N;i++){
            if(color[i]==-1){
                color[i]=0;
                dfs(i);
            }
            if(!ok)break;
        }
        return ok;
    }
};