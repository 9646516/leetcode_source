// id:361550051
// runtime:452 ms
// memory:123.8 MB
// title:Divide Intervals Into Minimum Number of Groups
// translatedTitle:将区间分为最少组数
// questionId:2488
// time:2022-09-11 11:15:16

class Solution {
  public:
    int minGroups(vector<vector<int>> &V2) {
        vector<pair<int, int>> V;
        for (auto i : V2)
            V.push_back({i[0], i[1]});
        sort(V.begin(), V.end()
             // [](const pair<int, int> &a, const pair<int, int> &b) {
             //     if (a.second != b.second)
             //         return a.second < b.second;
             //     return a.first < b.first;
             // }
            );
        multiset<int> st;
        for (auto &i : V) {
            if (st.empty())
                st.insert(i.second);
            else {
                auto pos = st.lower_bound(i.first);
                if (pos != st.begin()) {
                    pos--;
                    st.erase(pos);
                    st.insert(i.second);
                } else {
                    st.insert(i.second);
                }
            }
        }
        return st.size();
    }
};