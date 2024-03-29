// id:313866335
// runtime:0 ms
// memory:5.8 MB
// title:Smallest Good Base
// translatedTitle:最小好进制
// questionId:483
// time:2022-05-15 18:13:11

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
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */

class Solution {
  public:
    string smallestGoodBase(string n) {
        ll val = stoll(n);
        ll res = numeric_limits<ll>::max();
        for (int i = 2; i <= 63; i++) {
            if ((1LL << i) - 1 > val)
                break;
            ll L = 2, R = 1e18 - 1, ans = 2;
            while (L <= R) {
                ll mid = (L + R) / 2;
                ll xs = 0;
                ll base = 1;
                for (int j = 0; j < i && xs <= val; j++) {
                    xs += base;
                    if ((double)base * mid > 1e18) {
                        base = 1e18;
                    } else {
                        base *= mid;
                    }
                }
                if (xs <= val)
                    L = mid + 1, ans = mid;
                else
                    R = mid - 1;
            }
            ll xs = 0;
            ll base = 1;
            for (int j = 0; j < i && xs <= val; j++) {
                xs += base;
                if ((double)base * ans > 1e18) {
                    base = 1e18;
                } else {
                    base *= ans;
                }
            }

            if (xs == val) {
                res = min(res, ans);
            }
        }
        return to_string(res);
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
    auto res = s.smallestGoodBase("3");
    debug(res);
    return 0;
}
#endif