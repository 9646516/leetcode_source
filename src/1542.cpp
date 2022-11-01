// id:96088139
// runtime:112 ms
// memory:10.8 MB
// title:Find Longest Awesome Substring
// translatedTitle:找出最长的超赞子字符串
// questionId:1668
// time:2020-08-08 23:54:00

class Solution {
  public:
    int longestAwesome(string s) {
        int mask = 0, ans = 0;
        vector<int> mp(1 << 11, 1e9);
        mp[0] = -1;
        for (int i = 0; i < (int)s.size(); i++) {
            mask ^= 1 << (s[i] - '0');
            for (int j = 0; j < 10; j++) {
                ans = max(ans, i - mp[mask ^ (1 << j)]);
            }
            ans = max(ans, i - mp[mask]);
            mp[mask] = min(mp[mask], i);
        }
        return ans;
    }
};