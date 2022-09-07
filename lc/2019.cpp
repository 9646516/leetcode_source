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
 * @lc app=leetcode.cn id=2019 lang=cpp
 *
 * [2019] 解出数学表达式的学生分数
 */
class Solution {
  public:
    string s;
    int calc() {
        vector<int> num, op;
        for (int i : s) {
            if (i == '+') {
                while (!op.empty() && op.back() == '*') {
                    int a = num.back();
                    num.pop_back();
                    num.back() *= a;
                    op.pop_back();
                }
                op.push_back(i);
            } else if (i == '*') {
                op.push_back(i);
            } else {
                num.push_back(i - '0');
            }
        }
        while (!op.empty()) {
            if (op.back() == '*') {
                int a = num.back();
                num.pop_back();
                num.back() *= a;
                op.pop_back();
            } else {
                int a = num.back();
                num.pop_back();
                num.back() += a;
                op.pop_back();
            }
        }
        return num.front();
    }
    vector<int> dp[33][33];
    void dfs(int l, int r) {
        if (!dp[l][r].empty()) {
            return;
        } else if (l == r) {
            dp[l][r].push_back(s[l] - '0');
        } else if (l + 2 == r) {
            if (s[l + 1] == '*')
                dp[l][r].push_back((s[l] - '0') * (s[l + 2] - '0'));
            else
                dp[l][r].push_back((s[l] - '0') + (s[l + 2] - '0'));
        } else {
            for (int i = l + 1; i <= r; i += 2) {
                dfs(l, i - 1);
                dfs(i + 1, r);
                if (s[i] == '*') {
                    for (auto a : dp[l][i - 1]) {
                        for (auto b : dp[i + 1][r]) {
                            if (a * b <= 1000) {
                                dp[l][r].push_back(a * b);
                            }
                        }
                    }
                } else {
                    for (auto a : dp[l][i - 1]) {
                        for (auto b : dp[i + 1][r]) {
                            if (a + b <= 1000) {
                                dp[l][r].push_back(a + b);
                            }
                        }
                    }
                }
            }
            sort(dp[l][r].begin(), dp[l][r].end());
            dp[l][r].erase(unique(dp[l][r].begin(), dp[l][r].end()), dp[l][r].end());
        }
    }
    int scoreOfStudents(string s, vector<int> &answers) {
        this->s = s;
        int ans = calc();
        dfs(0, s.size() - 1);
        unordered_set<int> st;
        for (int i : dp[0][s.size() - 1]) {
            st.insert(i);
        }
        int tot = 0;
        for (int i : answers) {
            if (i == ans)
                tot += 5;
            else if (st.count(i))
                tot += 2;
        }
        return tot;
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
