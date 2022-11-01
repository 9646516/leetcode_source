// id:374285584
// runtime:52 ms
// memory:34.7 MB
// title:重建序列
// translatedTitle:重建序列
// questionId:1000314
// time:2022-10-18 20:52:48

vector<int>V[10005];
int deg[10005];
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        const int N=nums.size();
        for(int i=1;i<=N;i++){
            deg[i]=0;
            V[i].clear();
        }
        for(auto&i:sequences){
            for(int j=1;j<i.size();j++){
                int a=i[j-1];
                int b=i[j];
                V[a].push_back(b);
                deg[b]++;
            }
        }
        queue<int>q;
        for(int i=1;i<=N;i++){
            if(!deg[i])q.push(i);
        }
        while(!q.empty()){
            if(q.size()>1)return 0;
            int now=q.front();
            q.pop();
            for(int i:V[now]){
                deg[i]--;
                if(deg[i]==0){
                    q.push(i);
                }
            }
        }
        return 1;
    }
};