// id:373344400
// runtime:316 ms
// memory:139.4 MB
// title:Range Product Queries of Powers
// translatedTitle:二的幂数组中查询范围内的乘积
// questionId:2529
// time:2022-10-15 22:59:34

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
    vector<int> productQueries(int n, vector<vector<int>> &queries) {
        vector<int> V;
        for (int i = 31; i >= 0; i--) {
            if ((n >> i) & 1)
                V.push_back(i);
        }
        sort(V.begin(), V.end());
        for (int i = 1; i < V.size(); i++)
            V[i] += V[i - 1];
        vector<int> ret;
        for (auto &i : queries) {
            int l = i[0];
            int r = i[1];
            int cnt = V[r];
            if (l)
                cnt -= V[l - 1];
            ret.push_back(xpow(2, cnt));
        }
        return ret;
    }
};
#ifdef RINNE
int32_t main() {
    // freopen("x", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> v{6, 2, 2, 2, 6};
    string sb;
    Solution *s = new Solution();
    auto res = s->componentValue(v, a);
    debug(res);
    delete s;
    // const int NN = 1e6;
    // int ans = 0;
    // for (int i = 1; i <= NN; i++) {
    //     if (NN % i == 0)
    //         ans++;
    // }
    // cout << ans << endl;
    return 0;
}
#endif