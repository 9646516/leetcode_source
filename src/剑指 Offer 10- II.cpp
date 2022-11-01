// id:373275596
// runtime:0 ms
// memory:6.1 MB
// title:青蛙跳台阶问题  LCOF
// translatedTitle:青蛙跳台阶问题
// questionId:100277
// time:2022-10-15 19:23:23

const int MOD=1e9+7;
class Solution {
public:
    int numWays(int n) {
        vector<int>F(n+5);
        F[0]=1;
        for(int i=0;i<=n;i++){
            F[i+1]+=F[i];
            F[i+1]%=MOD;
            F[i+2]+=F[i];
            F[i+2]%=MOD;
        }
        return F[n];
    }
};