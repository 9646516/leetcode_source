// id:370589995
// runtime:24 ms
// memory:12.1 MB
// title:最小展台数量
// translatedTitle:最小展台数量
// questionId:1000481
// time:2022-10-07 15:02:37

class Solution {
  public:
    int minNumBooths(vector<string> &demand) {
        map<int, int> mp;
        for (auto &i : demand) {
            map<int, int> mp2;
            for (auto j : i) {
                mp2[j]++;
            }
            for (auto [a, b] : mp2) {
                mp[a] = max(mp[a], b);
            }
        }
        int ans = 0;
        for (auto [a, b] : mp)
            ans += b;
        return ans;
    }
};