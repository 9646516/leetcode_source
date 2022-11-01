// id:371978230
// runtime:4 ms
// memory:8.6 MB
// title:24 Game
// translatedTitle:24 点游戏
// questionId:679
// time:2022-10-11 16:57:20

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
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

class Solution {
  public:
    bool solve(const vector<double> &V) {
        if (V.size() == 1) {
            return abs(V[0] - 24) < 1e-4;
        } else {
            for (int i = 0; i < V.size(); i++) {
                for (int j = i + 1; j < V.size(); j++) {
                    if (i != j) {
                        vector<double> v2;
                        for (int k = 0; k < V.size(); k++) {
                            if (k != i && k != j) {
                                v2.push_back(V[k]);
                            }
                        }
                        v2.push_back(0);
                        v2.back() = V[i] + V[j];
                        if (solve(v2))
                            return 1;

                        v2.back() = V[i] - V[j];
                        if (solve(v2))
                            return 1;
                        v2.back() = V[j] - V[i];
                        if (solve(v2))
                            return 1;

                        v2.back() = V[i] * V[j];
                        if (solve(v2))
                            return 1;

                        v2.back() = V[i] / V[j];
                        if (solve(v2))
                            return 1;
                        v2.back() = V[j] / V[i];
                        if (solve(v2))
                            return 1;
                    }
                }
            }
            return 0;
        }
    }
    bool judgePoint24(vector<int> &cards) {
        vector<double> V;
        for (int i : cards)
            V.push_back(i);
        return solve(V);
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