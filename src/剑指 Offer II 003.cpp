// id:373666095
// runtime:4 ms
// memory:8.3 MB
// title:前 n 个数字二进制中 1 的个数
// translatedTitle:前 n 个数字二进制中 1 的个数
// questionId:1000230
// time:2022-10-16 23:29:57

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ret;
        for(int i=0;i<=n;i++)ret.push_back(__builtin_popcount(i));
        return ret;
    }
};