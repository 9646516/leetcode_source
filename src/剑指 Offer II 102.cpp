// id:374233262
// runtime:36 ms
// memory:10.3 MB
// title:加减的目标值
// translatedTitle:加减的目标值
// questionId:1000288
// time:2022-10-18 18:05:33

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int N=nums.size();
        const int P=N/2;
        const int Q=N-P;
        unordered_map<int,int>mp;
        for(int i=0;i<1<<P;i++){
            int xs=0;
            for(int j=0;j<P;j++){
                if((i>>j)&1)xs+=nums[j];
                else xs-=nums[j];
            }
            mp[xs]++;
        }
        int ans=0;
        for(int i=0;i<1<<Q;i++){
            int xs=0;
            for(int j=0;j<Q;j++){
                if((i>>j)&1)xs+=nums[P+j];
                else xs-=nums[P+j];
            }
            if(mp.count(target-xs)){
                ans+=mp[target-xs];
            }
        }
        return ans;
    }
};