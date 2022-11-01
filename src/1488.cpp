// id:80740858
// runtime:964 ms
// memory:349.4 MB
// title:Avoid Flood in The City
// translatedTitle:避免洪水泛滥
// questionId:1612
// time:2020-06-21 11:40:39

class Solution {
  public:
    vector<int> avoidFlood(vector<int> &rains) {
        unordered_map<int, deque<int>> G;
        vector<vector<int>> V(1);
        for (int i : rains) {
            if (!i) {
                V.emplace_back(vector<int>{});
            } else {
                V.end()[-1].emplace_back(i);
            }
        }
        vector<int> ans(rains.size(), -1);
        deque<int> trys;
        int idx = 0;
        for (int i = 0; i < (int)V.size(); i++) {
            for (int j : V[i]) {
                G[j].push_back(idx);
                if (G[j].size() >= 2) {
                    auto p = lower_bound(trys.begin(), trys.end(), G[j].front());
                    if (p == trys.end()) {
                        return vector<int>{};
                    }
                    ans[*p] = j;
                    trys.erase(p);
                    G[j].pop_front();
                }
                ++idx;
            }
            if (i != (int)V.size() - 1) {
                trys.push_back(idx);
                ++idx;
            }
        }
        for (int i : trys) {
            ans[i] = 1;
        }
        return ans;
    }
};