// id:374011298
// runtime:4 ms
// memory:10.7 MB
// title:排序数组中只出现一次的数字
// translatedTitle:排序数组中只出现一次的数字
// questionId:1000334
// time:2022-10-17 23:41:32

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int L=0,R=nums.size()-1,ans=-1;
        while(L<=R){
            int mid=(L+R)/2;
            int rp;
            if(mid&1)rp=mid-1;
            else rp=mid+1;
            if(nums[mid]==nums[rp]){
                ans=max(mid,rp);
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        return nums[ans+1];
    }
};