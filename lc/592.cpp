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
 * @lc app=leetcode.cn id=592 lang=cpp
 *
 * [592] 分数加减运算
 */

class Solution {
  public:
    string fractionAddition(string expression) {
        vector<string> V;
        string now;
        for (char i : expression) {
            if (i == '+' || i == '-') {
                if (now.empty()) {
                    now.push_back(i);
                } else {
                    V.push_back(now);
                    now.clear();
                    now.push_back(i);
                }
            } else {
                now.push_back(i);
            }
        }
        if (!now.empty())
            V.push_back(now);
        vector<pair<int, int>> V2;
        for (auto &i : V) {
            int f = 0, s = 0, sig = 1;
            int ptr = 0;
            if (i[0] == '+') {
                sig = 1;
                ptr++;
            } else if (i[0] == '-') {
                sig = 0;
                ptr++;
            }
            while (ptr < (int)i.size() && i[ptr] != '/') {
                f = f * 10 + i[ptr] - '0';
                ptr++;
            }
            ptr++;
            while (ptr < (int)i.size()) {
                s = s * 10 + i[ptr] - '0';
                ptr++;
            }
            if (!sig)
                f = -f;
            V2.push_back({f, s});
        }
        ll f = V2[0].first;
        ll s = V2[0].second;
        for (int i = 1; i < (int)V2.size(); i++) {
            auto [a, b] = V2[i];
            ll s2 = s * b;
            ll f2 = f * b + a * s;
            if (f2) {
                ll gcd = __gcd(s2, f2);
                s2 /= gcd;
                f2 /= gcd;
                f = f2;
                s = s2;
            } else {
                f = 0;
                s = 1;
            }
            if (s < 0) {
                f = -f;
                s = -s;
            }
        }
        stringstream ss;
        ss << f << "/" << s;
        return ss.str();
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
