// id:374826286
// runtime:0 ms
// memory:5.9 MB
// title:Factorial Zeros LCCI
// translatedTitle:阶乘尾数
// questionId:1000017
// time:2022-10-20 15:11:07

class Solution {
public:
    int trailingZeroes(int n) {
        int s2=0,s5=0;
        for(long long i=2;i<=n;i*=2){
            s2+=n/i;
        }
        for(long long i=5;i<=n;i*=5){
            s5+=n/i;
        }
        return min(s2,s5);
    }
};