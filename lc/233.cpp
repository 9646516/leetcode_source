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
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 */

class Solution {
  public:
    vector<int> p;
    vector<int> num;
    vector<int> num2;
    int dfs(int now, int is_less_than) {
        if (now == (int)p.size())
            return 0;
        else {
            if (is_less_than) {
                return num2[now + 1] + 10 * dfs(now + 1, true);
            } else if (p[now] == 0) {
                return dfs(now + 1, false);
            } else if (p[now] == 1) {
                return (num[now + 1] + 1) + dfs(now + 1, true) + dfs(now + 1, false);
            } else {
                return num2[now + 1] + dfs(now + 1, true) * p[now] + dfs(now + 1, false);
            }
        }
    }
    int countDigitOne(int n) {
        while (n) {
            p.push_back(n % 10);
            n /= 10;
        }
        reverse(p.begin(), p.end());
        {
            int now = 0;
            int P = 1;
            num.resize(p.size() + 1);
            for (int i = (int)p.size() - 1; i >= 1; i--) {
                now = now + p[i] * P;
                P *= 10;
                num[i] = now;
            }
            num.back() = 0;
        }
        {
            int now = 1;
            num2.resize(p.size() + 1);
            for (int i = (int)p.size() - 1; i >= 1; i--) {
                now = now * 10;
                num2[i] = now;
            }
            num2.back() = 1;
        }
        debug(p);
        debug(num);
        debug(num2);
        return dfs(0, 0);
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
    auto res = s.countDigitOne(1000000000);
    debug(res);
    return 0;
}
#endif
// @lc code=end
