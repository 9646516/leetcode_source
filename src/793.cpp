// id:368858244
// runtime:0 ms
// memory:5.8 MB
// title:Preimage Size of Factorial Zeroes Function
// translatedTitle:阶乘函数后 K 个零
// questionId:809
// time:2022-09-30 20:29:52

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
 * @lc app=leetcode.cn id=793 lang=cpp
 *
 * [793] 阶乘函数后 K 个零
 */

class Solution {
  public:
    ll get2(ll val, ll s) {
        ll ret = 0, now = s;
        while (now <= val) {
            ret += val / now;
            now *= s;
        }
        return ret;
    }
    ll get(ll k) {
        ll s2 = get2(k, 2);
        ll s5 = get2(k, 5);
        ll now = min(s2, s5);
        return now;
    }
    ll gmin(ll k) {
        ll L = 0, R = 1e18, ans = R;
        while (L <= R) {
            ll mid = (L + R) / 2;
            ll now = get(mid);
            if (now >= k) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return ans;
    }
    ll gmax(ll k) {
        ll L = 0, R = 1e18, ans = 0;
        while (L <= R) {
            ll mid = (L + R) / 2;
            ll now = get(mid);
            if (now <= k) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return ans;
    }
    int preimageSizeFZF(int k) {
        ll L = gmin(k), R = gmax(k);
        if (get(L) != k || get(R) != k)
            return 0;
        else
            return R - L + 1;
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