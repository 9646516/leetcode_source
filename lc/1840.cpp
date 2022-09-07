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
 * @lc app=leetcode.cn id=1840 lang=cpp
 *
 * [1840] 最高建筑高度
 */

class Solution {
  public:
    int calc(int prev_idx, int prev_h, int now_idx, int now_h) {
        int left = now_idx - prev_idx;
        if (now_h > prev_h) {
            int use = now_h - prev_h;
            if (use >= left) {
                return prev_h + left;
            } else {
                left -= use;
                return now_h + left / 2;
            }
        } else {
            int use = prev_h - now_h;
            if (use >= left) {
                return now_h + left;
            } else {
                left -= use;
                return prev_h + left / 2;
            }
        }
    }
    int maxBuilding(int n, vector<vector<int>> &V) {
        if (V.empty())
            return n - 1;
        else {
            sort(V.begin(), V.end());
            debug(V);
            vector<int> H(V.size());
            int prev_h = 0;
            for (int i = 0; i < (int)V.size(); i++) {
                if (V[i][1] > prev_h) {
                    if (i)
                        prev_h = min(prev_h + V[i][0] - V[i - 1][0], V[i][1]);
                    else
                        prev_h = min(prev_h + V[i][0] - 1, V[i][1]);
                } else {
                    prev_h = V[i][1];
                }
                H[i] = prev_h;
            }
            for (int i = (int)V.size() - 2; i >= 0; i--) {
                int dis = V[i + 1][0] - V[i][0];
                if (H[i] > H[i + 1] + dis) {
                    H[i] = H[i + 1] + dis;
                }
            }
            int ans = calc(1, 0, V[0][0], H[0]);
            for (int i = 1; i < (int)V.size(); i++) {
                ans = max(ans, calc(V[i - 1][0], H[i - 1], V[i][0], H[i]));
            }
            ans = max(ans, H[V.size() - 1] + n - V[V.size() - 1][0]);
            return ans;
        }
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{8, 5},  {9, 0}, {6, 2}, {4, 0}, {3, 2},
                             {10, 0}, {5, 3}, {7, 3}, {2, 4}};
    Solution s;
    auto res = s.maxBuilding(10, data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
