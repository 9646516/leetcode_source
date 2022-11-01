// id:100840434
// runtime:4 ms
// memory:11.2 MB
// title:Most Visited Sector in  a Circular Track
// translatedTitle:圆形赛道上经过次数最多的扇区
// questionId:1682
// time:2020-08-23 10:50:32

#include <bits/stdc++.h>
using namespace std;
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
class Solution {
  public:
    vector<int> mostVisited(int n, vector<int> &rounds) {
        vector<int> cnt(n + 5);
        int j = rounds.front();
        for (int i = 1; i < (int)rounds.size(); i++) {
            int r = rounds[i];
            for (;;) {
                debug(i, j);
                cnt[j]++;
                if (j == r) {
                    j++;
                    if (j == n + 1)
                        j = 1;
                    break;
                }
                j++;
                if (j == n + 1)
                    j = 1;
            }
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == mx) {
                ret.push_back(i);
            }
        }
        debug(mx, cnt);
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
    vector<int> a{1, 3, 1, 2};
    Solution s;
    auto res = s.mostVisited(5, a);
    debug(res);
    return 0;
}
#endif