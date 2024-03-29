// id:299508901
// runtime:132 ms
// memory:74.2 MB
// title:Maximum Gap
// translatedTitle:最大间距
// questionId:164
// time:2022-04-13 19:17:41

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
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

class Solution {
  public:
    int maximumGap(vector<int> &V) {
        if (V.size() < 2) {
            return 0;
        } else {
            int64_t P = 1;
            int mx = *max_element(V.begin(), V.end());
            vector<int> V2(V.size());
            while (P <= mx) {
                vector<int> cnt(1000, 0);
                for (int i : V) {
                    cnt[(i / P) % 1000]++;
                }
                partial_sum(cnt.begin(), cnt.end(), cnt.begin());
                for (int i = (int)V.size() - 1; i >= 0; i--) {
                    int p = (V[i] / P) % 1000;
                    V2[cnt[p] - 1] = V[i];
                    cnt[p]--;
                }
                swap(V, V2);
                debug(V);
                P *= 1000;
            }
            int ans = 0;
            for (int i = 1; i < (int)V.size(); i++) {
                ans = max(ans, V[i] - V[i - 1]);
            }
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
    vector<int> data{11, 5, 13, 14, 7, 8, 9};
    Solution s;
    auto res = s.maximumGap(data);
    debug(res);
    return 0;
}
#endif