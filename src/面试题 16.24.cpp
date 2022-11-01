// id:374872192
// runtime:100 ms
// memory:44.8 MB
// title:Pairs With Sum LCCI
// translatedTitle:数对和
// questionId:1000042
// time:2022-10-20 16:58:54

class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>>ret;
        // unordered_multiset<int>st;
        // for(int i:nums)st.insert(i);
        // for(int i:nums){
        //     if(!st.count(i))continue;
        //     st.erase(st.find(i));
        //     if(st.count(target-i)){
        //         st.erase(st.find(target-i));
        //         ret.push_back({i,target-i});
        //     }else{
        //         st.insert(i);
        //     }
        // }
        sort(nums.begin(),nums.end());
        int pos=nums.size()-1;
        for(int i=0;i<pos;i++){
            while(pos>i&&nums[i]+nums[pos]>target)pos--;
            if(pos>i&&nums[i]+nums[pos]==target){
                ret.push_back({nums[i],nums[pos]});
                pos--;
            }
        }
        return ret;

    }
};