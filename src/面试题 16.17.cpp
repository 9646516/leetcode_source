// id:374847192
// runtime:4 ms
// memory:12.7 MB
// title:Contiguous Sequence LCCI
// translatedTitle:连续数列
// questionId:1000003
// time:2022-10-20 16:00:24

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int now=0,ans=numeric_limits<int>::min();
        for(int i:nums){
            now=max(now,0)+i;
            ans=max(ans,now);
        }
        return ans;
    }
};