// id:368569014
// runtime:176 ms
// memory:5.9 MB
// title:K-Similar Strings
// translatedTitle:相似度为 K 的字符串
// questionId:884
// time:2022-09-29 20:23:50

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
 * @lc app=leetcode.cn id=854 lang=cpp
 *
 * [854] 相似度为 K 的字符串
 */
class Solution {
  public:
    int ans;
    int dfs(string &s1, const string &s2, int pos, int dep) {
        if (s1 == s2) {
            ans = min(ans, dep);
            return dep;
        } else if (dep >= ans) {
            return INF;
        } else {
            char need = s2[pos];
            if (s1[pos] == need) {
                return dfs(s1, s2, pos + 1, dep);
            } else {
                int ans = INF;
                for (int i = pos + 1; i < s1.size(); i++) {
                    if (s1[i] == need && s1[i] != s2[i]) {
                        swap(s1[i], s1[pos]);
                        ans = min(ans, dfs(s1, s2, pos + 1, dep + 1));
                        swap(s1[i], s1[pos]);
                    }
                }
                return ans;
            }
        }
    }
    int kSimilarity(string s1, string s2) {
        string a, b;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                a.push_back(s1[i]);
                b.push_back(s2[i]);
            }
        }
        ans = INF;
        return dfs(a, b, 0, 0);
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