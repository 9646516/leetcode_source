// id:374915969
// runtime:4 ms
// memory:6.3 MB
// title:Get Kth Magic Number LCCI
// translatedTitle:第 k 个数
// questionId:1000037
// time:2022-10-20 19:35:33

class Solution {
public:
    int getKthMagicNumber(int k) {
        set<long long>s1;
        s1.insert(1);
        for(int i=1;i<k;i++){
            long long now=*s1.begin();
            s1.erase(s1.begin());
            s1.insert(now*3LL);
            s1.insert(now*5LL);
            s1.insert(now*7LL);
        }
        return *s1.begin();
    }
};