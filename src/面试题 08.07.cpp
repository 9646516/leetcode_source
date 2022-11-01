// id:374594362
// runtime:16 ms
// memory:19.2 MB
// title:Permutation I LCCI
// translatedTitle:无重复字符串的排列组合
// questionId:100241
// time:2022-10-19 19:55:20

class Solution {
public:
    vector<string> permutation(string S) {
        vector<string>ret;
        sort(S.begin(),S.end());
        do{
            ret.push_back(S);
        }while(next_permutation(S.begin(),S.end()));
        return ret;
    }
};