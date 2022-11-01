// id:363735059
// runtime:4 ms
// memory:14.9 MB
// title:Kth Smallest Instructions
// translatedTitle:第 K 条最小指令
// questionId:489
// time:2022-09-16 19:40:21

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
 * @lc app=leetcode.cn id=1643 lang=cpp
 *
 * [1643] 第 K 条最小指令
 */

class Solution {
  public:
    string kthSmallestPath(vector<int> &V, int k) {
        long double P[33];
        P[0] = 1;
        for (int i = 1; i <= 30; i++)
            P[i] = P[i - 1] * i;
        string sb;
        long double now = k;
        swap(V[0], V[1]);
        while (V[0] || V[1]) {
            debug(V);
            for (int i = 0; i < 2; i++) {
                if (V[i] == 0)
                    continue;
                long double ways = P[V[0] + V[1] - 1] / P[V[i] - 1] / P[V[i ^ 1]];
                debug(now, ways);
                if (now > ways) {
                    now -= ways;
                } else {
                    sb.push_back(i);
                    V[i]--;
                    break;
                }
            }
        }
        for (char &i : sb)
            if (i == 0)
                i = 'H';
            else
                i = 'V';
        return sb;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{2, 1};
    Solution s;
    auto res = s.kthSmallestPath(data, 2);
    debug(res);
    return 0;
}
#endif