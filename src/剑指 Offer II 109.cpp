// id:374245526
// runtime:104 ms
// memory:21 MB
// title:开密码锁
// translatedTitle:开密码锁
// questionId:1000302
// time:2022-10-18 19:01:19

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int bad[10][10][10][10];
        memset(bad,0,sizeof(bad));
        for(auto&i:deadends){
            int A=i[0]-'0';
            int B=i[1]-'0';
            int C=i[2]-'0';
            int D=i[3]-'0';
            bad[A][B][C][D]=1;
        }
        if(bad[0][0][0][0])return -1;
        
        queue<tuple<int,int,int,int,int>>q;
        q.push({0,0,0,0,0});
        int dp[10][10][10][10];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0][0][0]=0;
        
        while(!q.empty()){
            auto [_cost,a,b,c,d]=q.front();
            int cost=_cost;
            q.pop();
            auto solve=[&](int a2,int b2,int c2,int d2){
                if(bad[a2][b2][c2][d2])return;
                if(dp[a2][b2][c2][d2]>cost+1){
                    dp[a2][b2][c2][d2]=cost+1;
                    q.push({cost+1,a2,b2,c2,d2});
                }
            };
            solve((a+1)%10,b,c,d);
            solve((a+9)%10,b,c,d);
            solve(a,(b+1)%10,c,d);
            solve(a,(b+9)%10,c,d);
            solve(a,b,(c+1)%10,d);
            solve(a,b,(c+9)%10,d);
            solve(a,b,c,(d+1)%10);
            solve(a,b,c,(d+9)%10);
        }
        {
            int A=target[0]-'0';
            int B=target[1]-'0';
            int C=target[2]-'0';
            int D=target[3]-'0';
            int ans=dp[A][B][C][D];
            if(ans==0x3f3f3f3f)ans=-1;
            return ans;
        }
    }
};