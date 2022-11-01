// id:373274949
// runtime:4 ms
// memory:5.9 MB
// title:斐波那契数列  LCOF
// translatedTitle:斐波那契数列
// questionId:100274
// time:2022-10-15 19:20:23

const int MOD=1e9+7;
int F[105];
class Solution {
public:
    int fib(int n) {
        F[0]=0;
        F[1]=1;
        for(int i=2;i<=n;i++)F[i]=(F[i-1]+F[i-2])%MOD;
        return F[n];
    }
};