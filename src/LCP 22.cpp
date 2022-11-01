// id:376660019
// runtime:4 ms
// memory:5.9 MB
// title:黑白方格画
// translatedTitle:黑白方格画
// questionId:1000140
// time:2022-10-26 16:38:25

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
class Solution {
  public:
    unordered_set<ll> st;
    int m[7][7];
    void test(int m1, int m2, int n, int k) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                m[i][j] = 0;
        for (int i = 0; i < n; i++) {
            if ((m1 >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    m[i][j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if ((m2 >> i) & 1) {
                for (int j = 0; j < n; j++) {
                    m[j][i] = 1;
                }
            }
        }
        int xs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                xs += m[i][j];
            }
        }
        if (xs == k) {
            ll h1 = 0, h2 = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    h1 = (h1 * 233 + m[i][j]) % MOD;
                    h2 = (h2 * 2333 + m[i][j]) % (MOD + 2);
                }
            }
            st.insert(h1 << 32 | h2);
        }
    }
    int paintingPlan(int n, int k) {
        for (int i = 0; i < 1 << n; i++) {
            for (int j = 0; j < 1 << n; j++) {
                test(i, j, n, k);
            }
        }
        return st.size();
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
    vector<int> V{2, 3, 3, 2, 3, 3};
    Solution *s = new Solution();
    auto res = s->splitArray(V);
    debug(res);
    delete s;
    return 0;
}
#endif