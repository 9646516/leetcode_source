// id:374194589
// runtime:0 ms
// memory:7.4 MB
// title:没有重复元素集合的全排列
// translatedTitle:没有重复元素集合的全排列
// questionId:1000234
// time:2022-10-18 16:22:00

class Solution {
public:
    vector<vector<int>> permute(vector<int>& V) {
        sort(V.begin(),V.end());
        vector<vector<int>>ret;
        do{
            ret.push_back(V);
        }while(next_permutation(V.begin(),V.end()));
        return ret;
    }
};