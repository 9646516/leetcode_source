// id:373615894
// runtime:108 ms
// memory:28.7 MB
// title:丑数 LCOF
// translatedTitle:丑数
// questionId:100334
// time:2022-10-16 20:47:30

class Solution {
public:
    using ll=long long;
    int nthUglyNumber(int n) {
        set<ll>s;
        s.insert(1);
        for(int i=1;i<n;i++){
            int now=*s.begin();
            s.erase(s.begin());
            s.insert(now*2LL);
            s.insert(now*3LL);
            s.insert(now*5LL);
        }
        return *s.begin();
    }
};