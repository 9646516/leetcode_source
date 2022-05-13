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
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

class Solution {
  public:
    vector<string> dp[26]; // dp[i][j] 做到i，和为j
    vector<string> dp2[26];
    vector<string> removeInvalidParentheses(string s) {
        const int len = s.size();
        dp[0].push_back("");
        for (int i = 0; i < len; i++) {
            const int ch = s[i];
            int val;
            if (ch == '(')
                val = 1;
            else if (ch == ')')
                val = -1;
            else
                val = 0;
            vector<int> mx(26, 0);
            {
                // do nothing
                for (int k = 0; k <= 25; k++) {
                    for (const auto &str : dp[k]) {
                        mx[k] = max(mx[k], (int)str.size());
                    }
                }
                // append
                for (int k = 0; k <= 25; k++) {
                    if (k + val < 0 || k + val > 25)
                        continue;
                    for (const auto &str : dp[k]) {
                        mx[k + val] = max(mx[k + val], (int)str.size() + 1);
                    }
                }
            }

            {
                // do nothing
                for (int k = 0; k <= 25; k++) {
                    for (const auto &str : dp[k]) {
                        if (mx[k] == str.size()) {
                            dp2[k].push_back(str);
                        }
                    }
                }
                // append
                for (int k = 0; k <= 25; k++) {
                    if (k + val < 0 || k + val > 25)
                        continue;
                    for (const const auto &str : dp[k]) {
                        if (mx[k + val] == str.size() + 1) {
                            string copy = str;
                            copy.push_back(ch);
                            debug(k + val, copy, k, char(ch), val);
                            dp2[k + val].push_back(move(copy));
                        }
                    }
                }
            }
            for (int k = 0; k <= 25; k++) {
                if (dp2[k].empty())
                    continue;
                sort(dp2[k].begin(), dp2[k].end());
                dp2[k].resize(unique(dp2[k].begin(), dp2[k].end()) - dp2[k].begin());
                sort(dp2[k].begin(), dp2[k].end(),
                     [](string &a, string &b) { return a.size() > b.size(); });
                while (dp2[k].back().size() != dp2[k].front().size()) {
                    dp2[k].pop_back();
                }
            }
            swap(dp, dp2);
            debug(i, mx);
        }
        return dp[0];
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
    auto res = s.removeInvalidParentheses("()())");
    debug(res);
    return 0;
}
#endif
// @lc code=end
