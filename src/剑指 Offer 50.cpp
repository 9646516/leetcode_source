// id:373616262
// runtime:20 ms
// memory:10.4 MB
// title:第一个只出现一次的字符  LCOF
// translatedTitle:第一个只出现一次的字符
// questionId:100316
// time:2022-10-16 20:48:34

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int>cnt(255);
        for(char i:s)cnt[i]++;
        for(char i:s){
            if(cnt[i]==1)return i;
        }
        return ' ';
    }
};