// id:373812457
// runtime:4 ms
// memory:6.8 MB
// title:不含重复字符的最长子字符串
// translatedTitle:不含重复字符的最长子字符串
// questionId:1000252
// time:2022-10-17 14:51:25

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mask=0;
        int ans=0;
        int pos=0;
        bitset<255>st;
        for(int i=0;i<s.size();i++){
            while(st[s[i]]){
                st[s[pos]]=0;
                pos++;
            }
            st[s[i]]=1;
            ans=max(ans,i-pos+1);
        }
        return ans;
    }
};