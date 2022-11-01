// id:374594836
// runtime:0 ms
// memory:6.7 MB
// title:Permutation II LCCI
// translatedTitle:有重复字符串的排列组合
// questionId:100348
// time:2022-10-19 19:56:41

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