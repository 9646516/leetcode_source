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
 * @lc app=leetcode.cn id=782 lang=cpp
 *
 * [782] 变为棋盘
 */

class Solution {
  public:
    int N;
    int calc(vector<int> &V) {
        vector<int> B = V;
        sort(B.begin(), B.end());
        B.erase(unique(B.begin(), B.end()), B.end());
        if (B.size() != 2)
            return -1;
        vector<int> V2;
        int c1 = 0, c0 = 0;
        for (int i : V) {
            if (i == B[0]) {
                V2.push_back(0);
                c0++;
            } else {
                c1++;
                V2.push_back(1);
            }
        }
        if (V2.size() % 2 == 0) {
            if (c1 != c0)
                return -1;
            int ans = 0;
            for (int j = 0; j < V2.size(); j++) {
                if (V2[j] != (j & 1)) {
                    ans++;
                }
            }
            return min(ans, (int)V.size() - ans) / 2;
        } else {
            if (c1 == c0 + 1) {
                int ans = 0;
                for (int j = 0; j < V2.size(); j++) {
                    if (V2[j] != (1 ^ (j & 1))) {
                        ans++;
                    }
                }
                return ans / 2;
            } else if (c0 == c1 + 1) {
                int ans = 0;
                for (int j = 0; j < V2.size(); j++) {
                    if (V2[j] != ((j & 1))) {
                        ans++;
                    }
                }
                return ans / 2;
            } else {
                return -1;
            }
        }
    }
    int movesToChessboard(vector<vector<int>> &mp) {
        N = mp.size();
        vector<int> V;
        for (int i = 0; i < N; i++) {
            int now = 0;
            for (int j = 0; j < N; j++) {
                now = now << 1 | mp[i][j];
            }
            int cnt = __builtin_popcount(now);
            if (cnt != N / 2 && cnt != (N + 1) / 2)
                return -1;
            V.push_back(now);
        }
        int res1 = calc(V);
        if (res1 == -1)
            return -1;
        V.clear();
        for (int i = 0; i < N; i++) {
            int now = 0;
            for (int j = 0; j < N; j++) {
                now = now << 1 | mp[j][i];
            }
            int cnt = __builtin_popcount(now);
            if (cnt != N / 2 && cnt != (N + 1) / 2)
                return -1;
            V.push_back(now);
        }
        int res2 = calc(V);
        if (res2 == -1)
            return -1;
        return res1 + res2;
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
