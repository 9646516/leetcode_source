// id:373614078
// runtime:0 ms
// memory:6.7 MB
// title:最长不含重复字符的子字符串 LCOF
// translatedTitle:最长不含重复字符的子字符串
// questionId:100332
// time:2022-10-16 20:41:44

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos=0,ans=0;
        int vis[255];
        memset(vis,0,sizeof(vis));
        for(int i=0;i<s.size();i++){
            while(vis[s[i]]){
                vis[s[pos]]--;
                pos++;
            }
            vis[s[i]]++;
            ans=max(ans,i-pos+1);
        }
        return ans;
    }
};