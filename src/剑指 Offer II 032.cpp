// id:373893798
// runtime:8 ms
// memory:7 MB
// title:有效的变位词
// translatedTitle:有效的变位词
// questionId:1000273
// time:2022-10-17 18:24:46

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s==t)return 0;
        vector<int>cnt(26);
        for(char i:s)cnt[i-'a']++;
        for(char i:t)cnt[i-'a']--;
        for(int i:cnt)if(i)return 0;
        return 1;
    }
};