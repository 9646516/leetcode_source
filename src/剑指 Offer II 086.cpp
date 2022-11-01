// id:374200849
// runtime:216 ms
// memory:185.9 MB
// title:分割回文子字符串
// translatedTitle:分割回文子字符串
// questionId:1000240
// time:2022-10-18 16:37:19

class Solution {
public:
    int dp[20][20];
    vector<vector<string>> dp2[20];
    vector<vector<string>> partition(string s) {
        memset(dp,0,sizeof(dp));
        const int N=s.size();
        for(int i=0;i<N;i++)dp[i][i]=1;
        for(int i=0;i+1<N;i++)if(s[i]==s[i+1])dp[i][i+1]=1;
        for(int i=3;i<=N;i++){
            for(int j=0;i+j-1<N;j++){
                int l=j,r=i+j-1;
                if(s[l]==s[r])dp[l][r]|=dp[l+1][r-1];
            }
        }
        dp2[N].push_back({""});
        for(int i=N-1;i>=0;i--){
            for(int j=i;j<N;j++){
                if(dp[i][j]){
                    for(vector<string> k:dp2[j+1]){
                        k.emplace_back(s.substr(i,j-i+1));
                        dp2[i].emplace_back(move(k));
                    }
                }
            }
        }
        auto ret=dp2[0];
        for(auto &i:ret){
            reverse(i.begin(),i.end());
            i.pop_back();
        }
        return ret;
    }
};