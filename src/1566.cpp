// id:102987707
// runtime:4 ms
// memory:8.4 MB
// title:Detect Pattern of Length M Repeated K or More Times
// translatedTitle:重复至少 K 次且长度为 M 的模式
// questionId:1689
// time:2020-08-30 11:01:56

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 114514
#endif
using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
  public:
    bool containsPattern(vector<int> &V, int m, int k) {
        auto ok = [&](int L, int R) {
            for (int i = 0; i < m; i++) {
                if (V[L + i] != V[R + i])
                    return false;
            }
            return true;
        };
        auto gao = [&](int s) -> bool {
            vector<int> sb;
            for (int i = 1; i < k; i++) {
                sb.push_back(s + m * i);
            }
            if (sb.back() + m - 1 >= V.size())
                return false;
            for (int i : sb) {
                if (!ok(s, i))
                    return false;
            }
            return true;
        };
        for (int i = 0; i < (int)V.size(); i++) {
            if (gao(i))
                return true;
        }
        return false;
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{2, 1, 3};
    Solution s;
    auto res = s.numOfWays(a);
    debug(res);
    return 0;
}
#endif