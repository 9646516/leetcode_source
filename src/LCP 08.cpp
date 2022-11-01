// id:63887696
// runtime:900 ms
// memory:97.7 MB
// title:剧情触发时间
// translatedTitle:剧情触发时间
// questionId:1000057
// time:2020-04-18 15:17:23

class Solution {
  public:
    static const int maxn = 1e4 + 555;
    using ll = long long;
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        ll p0[maxn];
        ll p1[maxn];
        ll p2[maxn];
        p0[0] = increase[0][0];
        p1[0] = increase[0][1];
        p2[0] = increase[0][2];
        for (int i = 1; i < (int)increase.size(); i++) {
            p0[i] = p0[i - 1] + increase[i][0];
            p1[i] = p1[i - 1] + increase[i][1];
            p2[i] = p2[i - 1] + increase[i][2];
        }
        vector<int> ans;
        for (auto &i : requirements) {
            if (max({i[0], i[1], i[2]}) == 0)
                ans.push_back(0);
            else {
                int a1 = lower_bound(p0, p0 + (int)increase.size(), i[0]) - p0 + 1;
                int a2 = lower_bound(p1, p1 + (int)increase.size(), i[1]) - p1 + 1;
                int a3 = lower_bound(p2, p2 + (int)increase.size(), i[2]) - p2 + 1;
                int res = max({a1, a2, a3});
                if (res > (int)increase.size())
                    ans.push_back(-1);
                else
                    ans.push_back(res);
            }
        }
        return ans;
    }
};