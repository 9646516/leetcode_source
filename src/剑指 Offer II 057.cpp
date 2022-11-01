// id:373959505
// runtime:44 ms
// memory:18.1 MB
// title:值和下标之差都在给定的范围内
// translatedTitle:值和下标之差都在给定的范围内
// questionId:1000321
// time:2022-10-17 21:27:44

class Solution {
public:
    using ll=long long;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<ll>st;
        for(int i=0;i<nums.size();i++){
            auto r=st.upper_bound(1LL*nums[i]+t);
            if(r!=st.begin()){
                r--;
                ll val=*r;
                if(abs(val-nums[i])<=t)return 1;
            }
            st.insert(nums[i]);
            if(i-k>=0){
                st.erase(st.lower_bound(nums[i-k]));
            }
        }
        return 0;
    }
};