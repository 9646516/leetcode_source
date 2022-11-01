// id:374590547
// runtime:4 ms
// memory:6.7 MB
// title:Power Set LCCI
// translatedTitle:幂集
// questionId:100198
// time:2022-10-19 19:44:22

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>V;
        const int N=nums.size();
        for(int i=0;i<1<<N;i++){
            vector<int>now;
            for(int j=0;j<N;j++){
                if((i>>j)&1){
                    now.push_back(nums[j]);
                }
            }
            V.emplace_back(move(now));
        }
        return V;
    }
};