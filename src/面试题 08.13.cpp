// id:374616816
// runtime:376 ms
// memory:39.8 MB
// title:Pile Box LCCI
// translatedTitle:堆箱子
// questionId:100202
// time:2022-10-19 20:54:41

vector<int>V[3003];
vector<int>V2[3003];
int deg[3003];
int dp[3003];

class Solution {
public:
    int pileBox(vector<vector<int>>& box) {
        for(int i=0;i<box.size();i++){
            dp[i]=deg[i]=0;
            V[i].clear();
            V2[i].clear();
        }
        for(int i=0;i<box.size();i++){
            for(int j=0;j<box.size();j++){
                if(i==j)continue;
                if(box[i][0]>box[j][0]&&box[i][1]>box[j][1]&&box[i][2]>box[j][2]){
                    deg[i]++;
                    V[j].push_back(i);
                    V2[i].push_back(j);
                }
            }
        }
        queue<int>q;
        for(int i=0;i<box.size();i++){
            if(deg[i]==0)q.push(i);
        }
        vector<int>order;
        while(!q.empty()){
            int now=q.front();
            q.pop();
            order.push_back(now);
            for(int i:V[now]){
                deg[i]--;
                if(deg[i]==0){
                    q.push(i);
                }
            }
        }

        for(int i:order){
            dp[i]=max(dp[i],box[i][2]);
            for(int j:V2[i]){
                dp[i]=max(dp[i],dp[j]+box[i][2]);
            }
        }
        return *max_element(dp,dp+box.size());
    }
};