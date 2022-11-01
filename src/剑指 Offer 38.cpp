// id:373323621
// runtime:12 ms
// memory:17 MB
// title:字符串的排列  LCOF
// translatedTitle:字符串的排列
// questionId:100308
// time:2022-10-15 22:06:11

class Solution {
public:
    vector<string> permutation(string s) {
        vector<string>ret;
        sort(s.begin(),s.end());
        do{
            ret.push_back(s);
        } while (next_permutation(s.begin(),s.end()));
        return ret;
    }
};