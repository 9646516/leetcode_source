// id:318451128
// runtime:4 ms
// memory:25.8 MB
// title:Valid Square
// translatedTitle:有效的正方形
// questionId:593
// time:2022-05-26 21:21:37

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
 * @lc app=leetcode.cn id=593 lang=cpp
 *
 * [593] 有效的正方形
 */

class Solution {
  public:
    ll D(pair<int, int> &f, pair<int, int> &s) {
        ll ox = f.first - s.first;
        ll oy = f.second - s.second;
        return ox * ox + oy * oy;
    }
    bool check(pair<int, int> &a, pair<int, int> &b, pair<int, int> &c) {
        ll x1 = a.first - b.first;
        ll y1 = a.second - b.second;

        ll x2 = c.first - b.first;
        ll y2 = c.second - b.second;

        return x1 * x2 + y1 * y2 == 0;
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4) {
        vector<pair<int, int>> V{{p1[0], p1[1]}, {p2[0], p2[1]}, {p3[0], p3[1]}, {p4[0], p4[1]}};
        sort(V.begin(), V.end());
        for (int i = 1; i < 4; i++) {
            if (V[i] == V[0]) {
                return 0;
            }
        }
        do {
            bool ok = 1;
            ll dis = D(V[0], V[3]);
            for (int i = 0; i < 3; i++) {
                if (D(V[i], V[i + 1]) != dis) {
                    ok = 0;
                    break;
                }
            }
            if (!ok)
                continue;
            for (int i = 0; i < 4; i++) {
                int pre = (i - 1 + 4) % 4;
                int next = (i + 1) % 4;
                if (!check(V[pre], V[i], V[next])) {
                    ok = 0;
                    break;
                }
            }
            if (ok)
                return 1;
        } while (next_permutation(V.begin(), V.end()));
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