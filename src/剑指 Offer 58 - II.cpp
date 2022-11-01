// id:373645432
// runtime:4 ms
// memory:7.7 MB
// title:左旋转字符串 LCOF
// translatedTitle:左旋转字符串
// questionId:100330
// time:2022-10-16 22:17:24

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n)+s.substr(0,n);
    }
};