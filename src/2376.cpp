// id:353965015
// runtime:12 ms
// memory:6 MB
// title:Count Special Integers
// translatedTitle:统计特殊整数
// questionId:2457
// time:2022-08-23 17:27:55

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
 * @lc app=leetcode.cn id=2376 lang=cpp
 *
 * [2376] 统计特殊整数
 */
int dp[10][1 << 10][2][2];
class Solution {
  public:
    vector<int> bit;
    int dfs(int pos, int mask, int lead, int ok) {
        if (pos >= bit.size())
            return 1;
        else if (ok && dp[pos][mask][lead][ok] != -1) {
            return dp[pos][mask][lead][ok];
        } else {
            int xs = 0;
            int o = ok ? 9 : bit[pos];
            for (int i = o; i >= 0; i--) {
                if (mask & (1 << i))
                    continue;
                int new_mask = mask;
                if (lead) {
                    new_mask |= 1 << i;
                } else {
                    if (i != 0) {
                        new_mask |= 1 << i;
                    }
                }
                xs += dfs(pos + 1, new_mask, lead || i, ok || i < bit[pos]);
            }
            return dp[pos][mask][lead][ok] = xs;
        }
    }
    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        {
            int x = n;
            while (x) {
                bit.push_back(x % 10);
                x /= 10;
            }
            reverse(bit.begin(), bit.end());
        }
        return dfs(0, 0, 0, 0) - 1;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{};
    Solution s;
    auto res = s.countSpecialNumbers(20);
    debug(res);
    return 0;
}
#endif