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
 * @lc app=leetcode.cn id=2122 lang=cpp
 *
 * [2122] 还原原数组
 */

class Solution {
  public:
    vector<int> recoverArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < (int)nums.size(); i++) {
            int o = nums[i] - nums[0];
            if (o & 1 || o <= 0)
                continue;
            vector<int> V;
            for (int j = 1; j < (int)nums.size(); j++) {
                if (i == j)
                    continue;
                V.push_back(nums[j]);
            }
            vector<int> ret{nums[0] + o / 2};
            bool ok = 1;
            vector<int> vis(V.size(), 0);
            int L = 0;
            debug(V);
            for (int j = 0; j < (int)V.size(); j++) {
                if (vis[j])
                    continue;
                else {
                    bool found = 0;
                    vis[j] = 1;
                    while (L < (int)V.size()) {
                        if (!vis[L] && V[L] - V[j] == o) {
                            ret.push_back(V[j] + o / 2);
                            found = 1;
                            vis[L] = 1;
                            break;
                        } else {
                            L++;
                        }
                    }
                    if (!found) {
                        ok = 0;
                        break;
                    }
                }
            }
            if (ok) {
                return ret;
            }
        }
        return {};
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{2, 10, 6, 4, 8, 12};
    Solution s;
    auto res = s.recoverArray(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
