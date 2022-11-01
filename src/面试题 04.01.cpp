// id:374535897
// runtime:212 ms
// memory:76.1 MB
// title:Route Between Nodes LCCI
// translatedTitle:节点间通路
// questionId:100171
// time:2022-10-19 16:42:57

int vis[100005];
vector<int>V[100005];
class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& edge, int start, int target) {
        for(int i=0;i<n;i++){
            vis[i]=0;
            V[i].clear();
        }
        for(auto &i:edge){
            int a=i[0];
            int b=i[1];
            V[a].push_back(b);
        }
        queue<int>q;
        vis[start]=1;
        q.push(start);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(int i:V[x]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return vis[target];
    }
};