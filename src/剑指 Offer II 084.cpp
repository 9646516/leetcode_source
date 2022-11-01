// id:374194916
// runtime:8 ms
// memory:8 MB
// title:含有重复元素集合的全排列 
// translatedTitle:含有重复元素集合的全排列 
// questionId:1000235
// time:2022-10-18 16:22:49

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& V) {
        sort(V.begin(),V.end());
        vector<vector<int>>ret;
        do{
            ret.push_back(V);
        }while(next_permutation(V.begin(),V.end()));
        return ret;
    }
};