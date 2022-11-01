// id:370665902
// runtime:380 ms
// memory:52.2 MB
// title:沙地治理
// translatedTitle:沙地治理
// questionId:1000485
// time:2022-10-07 18:29:29

class Solution {
  public:
    vector<vector<int>> sandyLandManagement(int size) {
        if (size == 1)
            return {{1, 1}};
        if (size == 2)
            return {{1, 1}, {2, 1}, {2, 3}};
        if (size == 3)
            return {{1, 1}, {2, 1}, {2, 3}, {3, 1}, {3, 5}};
        vector<vector<int>> ret;
        int s = 0;
        int L = 1, R = size * 2 - 1;
        for (int i = L; i <= R; i += 2) {
            ret.push_back({size, i});
        }
        for (int i = size - 2; i >= 2; i -= 2) {
            if (s == 0) {
                L = 3;
                R -= 4;
            } else {
                L = 1;
                R -= 4;
            }
            for (int j = L; j <= R; j += 2) {
                ret.push_back({i, j});
            }
            s ^= 1;
        }
        s = 0;
        for (int i = size - 1; i >= 2; i -= 2) {
            if (s == 0)
                ret.push_back({i, 2});
            else
                ret.push_back({i, 1});
            s ^= 1;
        }
        ret.push_back({1, 1});
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        return ret;
    }
};