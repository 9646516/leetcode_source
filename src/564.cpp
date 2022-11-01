// id:318358606
// runtime:0 ms
// memory:5.9 MB
// title:Find the Closest Palindrome
// translatedTitle:寻找最近的回文数
// questionId:564
// time:2022-05-26 17:08:48

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
 * @lc app=leetcode.cn id=564 lang=cpp
 *
 * [564] 寻找最近的回文数
 */

class Solution {
  public:
    string nearestPalindromic(string n) {
        ll base;
        int len = n.size() / 2;
        const ll k = stoll(n);
        {
            string half;
            for (int i = 0; i < len; i++) {
                half.push_back(n[i]);
            }
            if (half.empty())
                base = 0;
            else
                base = stoll(half);
        }
        ll ans = 0;
        for (int i = -10; i <= 10; i++) {
            ll val;
            if (n.size() & 1) {
                ll mid = base * 10LL + n[len] - '0' + i;
                if (mid <= 0)
                    continue;
                string sb = to_string(mid);
                int sz = sb.size();
                for (int i = sz - 2; i >= 0; i--)
                    sb.push_back(sb[i]);
                val = stoll(sb);
            } else {
                ll mid = base + i;
                if (mid <= 0)
                    continue;
                string sb = to_string(mid);
                int sz = sb.size();
                for (int i = sz - 1; i >= 0; i--)
                    sb.push_back(sb[i]);
                val = stoll(sb);
            }
            if (val == k)
                continue;
            if (abs(ans - k) > abs(val - k))
                ans = val;
            else if (abs(ans - k) == abs(val - k) && val < ans) {
                ans = val;
            }
        }
        for (ll val = 9; val < 1e17; val = val * 10 + 9) {
            if (val == k)
                continue;
            if (abs(ans - k) > abs(val - k))
                ans = val;
            else if (abs(ans - k) == abs(val - k) && val < ans) {
                ans = val;
            }
        }
        for (ll i = 1; i < 1e17; i = i * 10) {
            ll val = i + 1;
            if (val == k)
                continue;
            if (abs(ans - k) > abs(val - k))
                ans = val;
            else if (abs(ans - k) == abs(val - k) && val < ans) {
                ans = val;
            }
        }
        return to_string(ans);
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