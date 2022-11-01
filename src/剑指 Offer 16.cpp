// id:373285816
// runtime:4 ms
// memory:5.9 MB
// title:数值的整数次方 LCOF
// translatedTitle:数值的整数次方
// questionId:100295
// time:2022-10-15 20:04:44

class Solution {
public:
    double myPow(double x, int _n) {
        long long n=_n;
        int pos=1;
        if(n<0){
            pos=0;
            n=-n;
        }
        double ret=1;
        while(n){
            if(n&1)ret=ret*x;
            x=x*x;
            n>>=1;
        }
        if(pos)
            return ret;
        else
            return 1/ret;
    }
};