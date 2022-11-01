// id:374297211
// runtime:4 ms
// memory:6 MB
// title:Check Permutation LCCI
// translatedTitle:判定是否互为字符重排
// questionId:100159
// time:2022-10-18 21:21:09

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        vector<int>cnt(255);
        for(auto i:s1)cnt[i]++;
        for(auto i:s2)cnt[i]--;
        for(int i:cnt)if(i)return 0;
        return 1;
    }
};