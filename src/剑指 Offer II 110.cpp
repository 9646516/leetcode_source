// id:374246887
// runtime:8 ms
// memory:11.6 MB
// title:所有路径
// translatedTitle:所有路径
// questionId:1000303
// time:2022-10-18 19:06:35

class Solution {
public:
    vector<vector<int>>V;
    vector<int>now;
    vector<vector<int>>ans;
    int vis[20];
    int dst;
    void dfs(int x){
        if(x==dst){
            ans.push_back(now);
            return;
        }
        for(int i:V[x]){
            if(!vis[i]){
                vis[i]=1;
                now.push_back(i);
                dfs(i);
                vis[i]=0;
                now.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        V=graph;
        dst=graph.size()-1;
        memset(vis,0,sizeof(vis));
        vis[0]=1;
        now.push_back(0);
        dfs(0);
        return ans;
    }
};