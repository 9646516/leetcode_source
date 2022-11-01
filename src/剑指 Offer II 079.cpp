// id:374184816
// runtime:4 ms
// memory:6.9 MB
// title:所有子集
// translatedTitle:所有子集
// questionId:1000343
// time:2022-10-18 15:58:09

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int N=nums.size();
        vector<vector<int>>ret;
        for(int i=0;i<1<<N;i++){
            vector<int>V;
            for(int j=0;j<N;j++){
                if((i>>j)&1){
                    V.push_back(nums[j]);
                }
            }
            ret.emplace_back(move(V));
        }
        return ret;
    }
};