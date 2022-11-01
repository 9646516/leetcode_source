// id:373282772
// runtime:0 ms
// memory:5.9 MB
// title:二进制中1的个数 LCOF
// translatedTitle:二进制中1的个数
// questionId:100292
// time:2022-10-15 19:52:59

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret=0;
        for(int i=0;i<=31;i++)ret+=((n>>i)&1);
        return ret;
    }
};