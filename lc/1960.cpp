// @lc code=start
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
 * @lc app=leetcode.cn id=1960 lang=cpp
 *
 * [1960] 两个回文子字符串长度的最大乘积
 */
uint64_t H[100000 + 555];
uint64_t H2[100000 + 555];
uint64_t POW[100000 + 555];
uint64_t get_hash1(int l, int r) {
    int len = r - l + 1;
    uint64_t ret = H[r];
    if (l)
        ret -= H[l - 1] * POW[len];
    return ret;
}
uint64_t get_hash2(int l, int r, int sz) {
    int len = r - l + 1;
    uint64_t ret = H2[l];
    if (r + 1 < sz)
        ret -= H2[r + 1] * POW[len];
    return ret;
}
vector<int> solve(const string &a) {
    H[0] = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        H[i] = H[i - 1] * 233 + a[i];
    }
    H2[a.size() - 1] = a[a.size() - 1];
    for (int i = (int)a.size() - 2; i >= 0; i--) {
        H2[i] = H2[i + 1] * 233 + a[i];
    }
    vector<int> ret;
    for (int i = 0; i < (int)a.size(); i++) {
        int L = 1, R = min(i + 1, (int)a.size() - i), ans = 1;
        while (L <= R) {
            int mid = (L + R) / 2;
            int l = i - mid + 1, r = i + mid - 1;
            if (get_hash1(l, r) == get_hash2(l, r, a.size())) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        ret.push_back(ans);
    }
    return ret;
}
vector<int> gao(vector<int> P) {
    vector<int> P2;
    int omax = 0;
    multiset<pair<int, int>> st;
    multiset<int> st2;
    for (int i = 0; i < (int)P.size(); i++) {
        int l = i - P[i] + 1;
        int r = i + P[i] - 1;
        st.insert({r, l});
        st2.insert(i);
        while (!st.empty()) {
            if (st.begin()->first < i) {
                auto [r, l] = *st.begin();
                st.erase(st.begin());
                int o = (r + l) / 2;
                st2.erase(st2.lower_bound(o));
                omax = max(omax, r - l + 1);
            } else {
                break;
            }
        }
        int ans = (i - *st2.begin() + 1) * 2 - 1;
        ans = max(ans, omax);
        P2.push_back(ans);
    }
    return P2;
}
class Solution {
  public:
    long long maxProduct(string s) {
        POW[0] = 1;
        for (int i = 1; i <= s.size(); i++)
            POW[i] = POW[i - 1] * 233;
        vector<int> P = solve(s);
        P = gao(P);

        reverse(s.begin(), s.end());
        vector<int> S = solve(s);
        S = gao(S);
        reverse(S.begin(), S.end());

        ll ans = 0;
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            ans = max(ans, 1LL * P[i] * S[i + 1]);
        }
        return ans;
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
// @lc code=end
