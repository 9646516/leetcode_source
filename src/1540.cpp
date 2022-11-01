// id:96059577
// runtime:184 ms
// memory:17.5 MB
// title:Can Convert String in K Moves
// translatedTitle:K 次操作转变字符串
// questionId:1647
// time:2020-08-08 22:40:48

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
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
#define debug(...) 42
#endif
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
ll xpow(ll a, ll b) {
    ll ret = 1;
    a %= MOD;
    assert(b >= 0);
    while (b) {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
class Solution {
  public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size())
            return false;
        vector<int> cnt(30, 0);
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] != t[i])
                cnt[(-s[i] + t[i] + 26000) % 26]++;
        }
        debug(cnt);
        for (int i = 0; i < 26; i++) {
            int has = k / 26;
            int res = k % 26;
            if (res > 0)
                has += res >= i;
            debug(has, cnt[i]);
            if (has < cnt[i])
                return false;
        }
        debug(cnt);
        return true;
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    auto a = Solution();
    cout << a.canConvertString("aab", "bbb", 27) << endl;
    return 0;
}
#endif