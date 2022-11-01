// id:374298055
// runtime:0 ms
// memory:6.1 MB
// title:Palindrome Permutation LCCI
// translatedTitle:回文排列
// questionId:100184
// time:2022-10-18 21:23:11

class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int>cnt(255);
        for(int i:s)cnt[i]++;
        int bad=0;
        for(int i:cnt)if(i&1)bad++;
        return bad<=1;
    }
};