// id:377623357
// runtime:400 ms
// memory:140.6 MB
// title:Next Greater Element IV
// translatedTitle:下一个更大元素 IV
// questionId:2549
// time:2022-10-29 22:57:33

class Solution {
  public:
    vector<int> secondGreaterElement(vector<int> &nums) {
        const int N = nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < N; i++) {
            mp[nums[i]].push_back(i);
        }
        vector<int> ans(N, -1);
        multiset<int> st;
        for (auto i = prev(mp.end());; i--) {
            for (int j : i->second) {
                auto pos = st.upper_bound(j);
                if (pos != st.end()) {
                    pos++;
                    if (pos != st.end()) {
                        ans[j] = *pos;
                    }
                }
            }
            for (int j : i->second) {
                st.insert(j);
            }
            if (i == mp.begin())
                break;
        }
        for (auto &i : ans)
            if (i != -1)
                i = nums[i];
        return ans;
    }
};