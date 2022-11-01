// id:368767119
// runtime:108 ms
// memory:23.8 MB
// title:Split Array With Same Average
// translatedTitle:数组的均值分割
// questionId:823
// time:2022-09-30 14:53:59

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
 * @lc app=leetcode.cn id=805 lang=cpp
 *
 * [805] 数组的均值分割
 */

class Solution {
  public:
    bool splitArraySameAverage(vector<int> &nums) {
        vector<int> st[16];
        const int N = nums.size();
        const int M = N / 2;
        for (int i = 0; i < 1 << M; i++) {
            int xs = 0, cnt = 0;
            for (int j = 0; j < M; j++) {
                if ((i >> j) & 1) {
                    xs += nums[j];
                    cnt++;
                }
            }
            st[cnt].push_back(xs);
        }

        unordered_set<int> st2[16];
        const int M2 = N - M;
        for (int i = 0; i < 1 << M2; i++) {
            int xs = 0, cnt = 0;
            for (int j = 0; j < M2; j++) {
                if ((i >> j) & 1) {
                    xs += nums[M + j];
                    cnt++;
                }
            }
            st2[cnt].insert(xs);
        }
        int xs = accumulate(nums.begin(), nums.end(), 0);
        double avg = 1.0 * xs / nums.size();
        for (int i = 1; i <= M; i++) {
            double need = avg * i;
            int val = need;
            if (need - val > 1e-4)
                continue;
            for (int j = 0; j <= i; j++) {
                for (int k : st[j]) {
                    if (st2[i - j].count(val - k)) {
                        return 1;
                    }
                }
            }
        }
        return 0;
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