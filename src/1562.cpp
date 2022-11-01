// id:100872395
// runtime:864 ms
// memory:119.1 MB
// title:Find Latest Group of Size M
// translatedTitle:查找大小为 M 的最新分组
// questionId:1684
// time:2020-08-23 12:04:12

class Solution {
  public:
    int findLatestStep(vector<int> &a, int m) {
        if (m == a.size()) return a.size();
        set<pair<int, int>> st;
        st.emplace(1, a.size());
        for (int j = (int)a.size() - 1; j >= 0; j--) {
            int i = a[j];
            auto pos = prev(st.upper_bound({i, int(1e9)}));
            int l = pos->first, r = pos->second;
            if (i - l == m || r - i == m) return j;
            st.erase(pos);
            if (l <= i - 1) st.emplace(l, i - 1);
            if (i + 1 <= r) st.emplace(i + 1, r);
        }
        return -1;
    }
};