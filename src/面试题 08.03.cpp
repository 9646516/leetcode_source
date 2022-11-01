// id:374589635
// runtime:12 ms
// memory:12.3 MB
// title:Magic Index LCCI
// translatedTitle:魔术索引
// questionId:100240
// time:2022-10-19 19:41:48

class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        int ret=-1;
        for(int i=0;i<nums.size();i++)if(nums[i]==i){
            ret=i;break;
        }
        return ret;
    }
};