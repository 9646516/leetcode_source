// id:297983423
// runtime:384 ms
// memory:6 MB
// title:Permutation Sequence
// translatedTitle:排列序列
// questionId:60
// time:2022-04-10 21:19:57

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
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

class Solution {
  public:
    int inverse;
    int table[10];
    string ret;
    int n;
    bool dfs(int pos, int mask, int tot_inverse) {
        // debug(ret, pos, n, tot_inverse);
        if (tot_inverse > inverse) {
            return false;
        } else if (pos == n) {
            // debug(111);
            return tot_inverse == inverse;
        } else {
            int P = 0;
            for (int i = 1; i <= n; i++) {
                P += !((mask >> i) & 1);
            }
            P--;
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!(mask & (1 << i))) {
                    ret.push_back(i + '0');
                    if (dfs(pos + 1, mask | 1 << i, tot_inverse + cnt * table[P])) {
                        return true;
                    }
                    ret.pop_back();
                    cnt++;
                }
            }
            return false;
        }
    }
    string getPermutation(int _n, int k) {
        n = _n;
        inverse = k - 1;
        table[0] = 1;
        for (int i = 1; i <= 9; i++) {
            table[i] = table[i - 1] * i;
        }
        auto res = dfs(0, 0, 0);
        debug(res);
        return ret;
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
    auto res = s.getPermutation(9, 362880-4);
    debug(res);
    return 0;
}
#endif