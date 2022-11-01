// id:374926254
// runtime:0 ms
// memory:8.1 MB
// title:Longest Word LCCI
// translatedTitle:最长单词
// questionId:1000022
// time:2022-10-20 20:05:41

class Solution {
public:
    vector<pair<int,uint64_t>>V;
    int dp[202];
    uint64_t H[222];
    uint64_t POW[222];
    int N;
    int ban;
    uint64_t get(int l,int r){
        uint64_t ret=H[r];
        if(l)ret-=H[l-1]*POW[r-l+1];
        return ret;
    }
    int dfs(int pos){
        if(pos==N)return 1;
        else if(dp[pos]!=-1)return dp[pos];
        for(int i=0;i<V.size();i++){
            if(i==ban)continue;
            auto[len,h]=V[i];
            if(pos+len-1<N){
                if(get(pos,pos+len-1)==h){
                    if(dfs(pos+len))return dp[pos]=1;
                }
            }
        }
        return dp[pos]=0;
    }
    bool solve(string&x){

        memset(dp,-1,sizeof(dp));
        H[0]=x[0];
        for(int i=1;i<x.size();i++)H[i]=H[i-1]*233+x[i];
        N=x.size();
        return dfs(0);
    }
    string longestWord(vector<string>& words) {
        POW[0]=1;
        for(int i=1;i<=200;i++)POW[i]=POW[i-1]*233;
        for(auto&i:words){
            uint64_t h=0;
            for(int j:i)h=h*233+j;
            V.push_back({i.size(),h});
        }
        string ret="";
        for(int i=0;i<words.size();i++){
            ban=i;
            if(solve(words[i])){
                if(ret.size()<words[i].size()||(ret.size()==words[i].size()&&words[i]<ret))ret=words[i];
            }
        }
        return ret;
    }
};