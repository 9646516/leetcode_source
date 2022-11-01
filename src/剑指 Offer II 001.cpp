// id:373665716
// runtime:0 ms
// memory:5.8 MB
// title:整数除法
// translatedTitle:整数除法
// questionId:1000228
// time:2022-10-16 23:28:29

class Solution {
public:
    int divide(int a, int b) {
        long long res=1LL*a/b;
        res=max(res,1LL*numeric_limits<int>::min());
        res=min(res,1LL*numeric_limits<int>::max());
        return res;
    }
};