// id:363375109
// runtime:548 ms
// memory:128.4 MB
// title:Minimum Adjacent Swaps for K Consecutive Ones
// translatedTitle:得到连续 K 个 1 的最少相邻交换次数
// questionId:1805
// time:2022-09-15 20:25:24

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
 * @lc app=leetcode.cn id=1703 lang=cpp
 *
 * [1703] 得到连续 K 个 1 的最少相邻交换次数
 */

class Solution {
  public:
    int minMoves(vector<int> &nums, int k) {
        vector<ll> V;
        for (int i = 0; i < (int)nums.size(); i++)
            if (nums[i])
                V.push_back(i);
        ll ans = 0x7FFFFFFF;
        vector<ll> P = V;
        for (int i = 1; i < (int)V.size(); i++) {
            P[i] += P[i - 1];
        }

        auto calc = [&](int start, int l, int r) {
            int L = 0, R = r - l, ans = 0;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (V[l + mid] <= start + mid) {
                    ans = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }

            int l1 = l, r1 = l + ans;
            int l2 = r1 + 1, r2 = r;

            int a1 = start, b1 = start + ans;
            int a2 = b1 + 1, b2 = start + r - l;

            ll f1 = 1LL * (a1 + b1) * (b1 - a1 + 1) / 2;
            ll f2 = 1LL * (a2 + b2) * (b2 - a2 + 1) / 2;
            ll g1 = P[r1];
            if (l1)
                g1 -= P[l1 - 1];
            ll g2 = P[r2];
            if (l2)
                g2 -= P[l2 - 1];

            return f1 - g1 + g2 - f2;
        };
        for (int i = 0; i + k - 1 < (int)V.size(); i++) {
            int s = i, e = i + k - 1;
            int L = V[s], R = V[e] - k + 1;
            while (L + 5 < R) {
                int rmid = (L + R) / 2;
                int lmid = (L + rmid) / 2;
                ll cost_l = calc(lmid, s, e);
                ll cost_r = calc(rmid, s, e);
                if (cost_l > cost_r)
                    L = lmid;
                else
                    R = rmid;
            }
            for (int i = L; i <= R; i++) {
                ans = min(ans, calc(i, s, e));
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
    vector<int> data{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    Solution s;
    auto res = s.minMoves(data, 9);
    debug(res);
    return 0;
}
#endif