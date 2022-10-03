// @lc code=start
/// 9646516

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const char s) { return string(1, s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N> string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A> string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B> string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ")";
}
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) +
           ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

/*
 * @lc app=leetcode.cn id=1224 lang=cpp
 *
 * [1224] 最大相等频率
 */

class Solution {
  public:
    int maxEqualFreq(vector<int> &nums) {
        int ans = 0;
        unordered_map<int, int> mp;
        multiset<int> st;
        auto can = [&]() -> bool {
            debug(st);
            if (st.size() == 1)
                return 1;
            else if (st.size() == 2) {
                int a = *st.begin();
                int b = *prev(st.end());
                if (a == 1)
                    return 1;
                if (b == a + 1)
                    return 1;
                return 0;
            } else if (st.size() == 3) {
                int a = *st.begin();
                int b = *prev(prev(st.end()));
                int c = *prev(st.end());
                if (a == b && c == b + 1)
                    return 1;
                if (b == c && a == 1)
                    return 1;
                return 0;
            } else {
                int a = *st.begin();
                int b = *next(st.begin());
                int c = *prev(prev(st.end()));
                int d = *prev(st.end());
                if (a == b && b == c && d == c + 1)
                    return 1;
                if (b == c && c == d && a == 1)
                    return 1;
                return 0;
            }
        };
        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i])) {
                st.erase(st.lower_bound(mp[nums[i]]));
            }
            mp[nums[i]]++;
            st.insert(mp[nums[i]]);
            if (can())
                ans = i + 1;
        }
        return ans;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{2, 2, 1, 1, 5, 3, 3, 5};
    Solution s;
    auto res = s.maxEqualFreq(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
