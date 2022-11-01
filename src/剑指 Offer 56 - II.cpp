// id:373640582
// runtime:20 ms
// memory:15.6 MB
// title:数组中数字出现的次数 II LCOF
// translatedTitle:数组中数字出现的次数 II
// questionId:100321
// time:2022-10-16 22:02:22

class Solution {
public:
    int B[32];
    int singleNumber(vector<int>& nums) {
        for(int i:nums)for(int j=0;j<=31;j++)B[j]+=(i>>j)&1;
        int ans=0;
        for(int i=0;i<=31;i++){
            if(B[i]%3)ans|=1<<i;
        }
        return ans;
    }
};