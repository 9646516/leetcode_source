// id:376061402
// runtime:308 ms
// memory:293.8 MB
// title:Minimum Number of Operations to Make Arrays Similar
// translatedTitle:使数组相似的最少操作次数
// questionId:2539
// time:2022-10-24 18:29:50

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<long long>cnt(1000005);
        for(int i:nums)cnt[i]++;
        for(int i:target)cnt[i]--;
        long long ans=0;
        for(int i=0;i<=1000000;i++){
            if(cnt[i]!=0){
                ans+=abs(cnt[i]);
                cnt[i+2]+=cnt[i];
            }
        }
        return ans/2;
    }
};