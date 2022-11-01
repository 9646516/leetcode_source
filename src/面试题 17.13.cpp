// id:374922223
// runtime:48 ms
// memory:10.2 MB
// title:Re-Space LCCI
// translatedTitle:恢复空格
// questionId:1000020
// time:2022-10-20 19:54:11

uint64_t H[1005];
uint64_t POW[1005];
int dp[1005];

class Solution {
public:
    vector<pair<int,uint64_t>>V;
    int N;
    uint64_t get(int l,int r){
        uint64_t ret=H[r];
        if(l)ret-=H[l-1]*POW[r-l+1];
        return ret;
    }
    int dfs(int pos){
        if(pos==N)return 0;
        else if(dp[pos]!=-1)return dp[pos];
        int ans=dfs(pos+1)+1;
        for(auto [len,h]:V){
            if(pos+len-1<N){
                if(get(pos,pos+len-1)==h){
                    ans=min(ans,dfs(pos+len));
                }
            }
        }
        return dp[pos]=ans;
    }
    int respace(vector<string>& dictionary, string sentence) {
        POW[0]=1;
        for(int i=1;i<=sentence.size();i++)POW[i]=POW[i-1]*233;
        H[0]=sentence[0];
        for(int i=1;i<sentence.size();i++)H[i]=H[i-1]*233+sentence[i];
        for(auto&i:dictionary){
            if(i.size()<=sentence.size()){
                uint64_t h=0;
                for(auto j:i){
                    h=h*233+j;
                }
                V.push_back({i.size(),h});
            }
        }
        memset(dp,-1,sizeof(dp));
        N=sentence.size();
        return dfs(0);
    }
};