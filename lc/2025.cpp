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
 * @lc app=leetcode.cn id=2025 lang=cpp
 *
 * [2025] 分割数组的最多方案数
 */

class Solution {
  public:
    int waysToPartition(vector<int> &nums, int k) {
        vector<ll> P;
        unordered_map<int, int> L, R;
        for (int i = 0; i < (int)nums.size(); i++) {
            P.push_back(nums[i]);
        }
        for (int i = 1; i < (int)nums.size(); i++) {
            P[i] += P[i - 1];
        }
        for (int i = 0; i + 1 < (int)nums.size(); i++) {
            R[P[i]]++;
        }
        int ans = 0;
        ll tot = P.back();
        if (tot % 2 == 0) {
            ans = R[tot / 2];
        }
        debug(ans);
        for (int i = 0; i < (int)nums.size(); i++) {
            ll o = k - nums[i];
            ll tot2 = tot + o;
            if (tot2 % 2 == 0) {
                ll need = tot2 / 2;
                int lc = L[need];
                int rc = R[need - o];
                ans = max(ans, lc + rc);
            }
            if (i != (int)nums.size() - 1) {
                R[P[i]]--;
                L[P[i]]++;
            }
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
    vector<int> data{0, 0, 5, 0};
    Solution s;
    auto res = s.waysToPartition(data, 0);
    debug(res);
    return 0;
}
#endif
// @lc code=end
