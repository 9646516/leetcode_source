// id:373645052
// runtime:0 ms
// memory:8.4 MB
// title:翻转单词顺序 LCOF
// translatedTitle:翻转单词顺序
// questionId:100328
// time:2022-10-16 22:16:20

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string now;
        vector<string>V;
        while(ss>>now){
            V.push_back(now);
        }
        reverse(V.begin(),V.end());
        now.clear();
        for(auto&i:V){
            now.append(i);
            now.push_back(' ');
        }
        now.pop_back();
        return now;
    }
};