// id:374220382
// runtime:520 ms
// memory:16.4 MB
// title:最长斐波那契数列
// translatedTitle:最长斐波那契数列
// questionId:1000271
// time:2022-10-18 17:23:33

class Solution {
public:
    unordered_map<int,int>mp;
    vector<int>V;
    int dp[1005][1005];
    int dfs(int A,int B){
        if(dp[A][B]!=-1)return dp[A][B];
        int C=V[A]+V[B];
        if(mp.count(C))return dp[A][B]=1+dfs(B,mp[C]);
        else return dp[A][B]=2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N=arr.size();
        V=arr;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        memset(dp,-1,sizeof(dp));
        // deque<int>V;
        // int ans=0;
        // for(int i=0;i<N;i++){
        //     for(int j=i+1;j<N;j++){
        //         int A=arr[i],B=arr[j],len=2;
        //         int pos=j;
        //         while(1){
        //             bool found=0;
        //             int need=A+B;
        //             if(mp.count(need)){
        //                 A=B;
        //                 B=need;
        //                 len++;
        //                 pos=mp[need];
        //                 found=1;
        //             }
        //             if(!found)break;
        //         }
        //         if(len>2)
        //             ans=max(ans,len);
        //     }
        // }
        int ans=0;
        for(int i=0;i<N;i++)
        for(int j=i+1;j<N;j++)ans=max(ans,dfs(i,j));
        if(ans<=2)ans=0;
        return ans;
    }
};