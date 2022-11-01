// id:373801299
// runtime:64 ms
// memory:36.2 MB
// title:和为 k 的子数组
// translatedTitle:和为 k 的子数组
// questionId:1000246
// time:2022-10-17 14:21:04

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>V=nums;
        for(int i=1;i<V.size();i++)V[i]+=V[i-1];
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]++;
        for(int i=0;i<V.size();i++){
            if(mp.count(V[i]-k)){
                ans+=mp[V[i]-k];
            }
            mp[V[i]]++;
        }
        return ans;
    }
};