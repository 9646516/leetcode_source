// id:368205584
// runtime:44 ms
// memory:38.6 MB
// title:Three Equal Parts
// translatedTitle:三等分
// questionId:963
// time:2022-09-28 19:39:35

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
 * @lc app=leetcode.cn id=927 lang=cpp
 *
 * [927] 三等分
 */

class Solution {
  public:
    int next[30000 + 5][2];
    uint64_t H[30000 + 5];
    uint64_t P[30000 + 5];
    uint64_t get(int l, int r) {
        uint64_t ret = H[r];
        if (l)
            ret -= H[l - 1] * P[r - l + 1];
        return ret;
    }
    vector<int> threeEqualParts(vector<int> &arr) {
        const int N = arr.size();
        P[0] = 1;
        for (int i = 1; i <= N; i++)
            P[i] = P[i - 1] * 233;
        H[0] = arr[0];
        for (int i = 1; i < N; i++)
            H[i] = H[i - 1] * 233 + arr[i];
        next[N - 1][0] = next[N - 1][1] = -1;
        next[N - 1][arr[N - 1]] = N - 1;
        for (int i = N - 2; i >= 0; i--) {
            next[i][0] = next[i + 1][0];
            next[i][1] = next[i + 1][1];
            next[i][arr[i]] = i;
        }
        bool has1 = false;
        for (int i = 0; i + 2 < N; i++) {
            if (arr[i] == 1)
                has1 = 1;
            if (!has1 && next[i + 1][1] == -1) {
                return {i, i + 2};
            } else {
                int s1 = next[0][1];
                int len = i - s1 + 1;
                int s2 = next[i + 1][1];
                if (s2 == -1)
                    continue;
                int e2 = s2 + len - 1;
                if (e2 >= N)
                    continue;
                int s3 = next[e2 + 1][1];
                if (s3 == -1)
                    continue;
                int e3 = s3 + len - 1;
                if (e3 != N - 1)
                    continue;
                uint64_t h1 = get(s1, i);
                uint64_t h2 = get(s2, e2);
                uint64_t h3 = get(s3, e3);
                if (h1 == h2 && h2 == h3 && h3 == h1) {
                    return {i, e2 + 1};
                }
            }
        }
        return {-1, -1};
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