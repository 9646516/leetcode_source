#pragma GCC optimize(2)

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
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

class Solution {
  public:
    string_view view;
    int64_t target;
    vector<string> ret;
    string now;
    void dfs(const int pos, const int64_t res, const int64_t last, char last_op) {
        if (pos == view.size()) {
            if (res == target) {
                ret.push_back(now);
            }
        } else {
            int64_t val = 0;
            const int sz = now.size();
            for (int i = pos; i < (int)view.size(); i++) {
                val = val * 10 + view[i] - '0';
                int64_t res2, last2;
                if (last_op == '+') {
                    res2 = res + val;
                    last2 = val;
                } else if (last_op == '-') {
                    res2 = res - val;
                    last2 = -val;
                } else {
                    res2 = res - last + last * val;
                    last2 = last * val;
                }
                now.push_back(view[i]);
                if (i + 1 == view.size()) {
                    dfs(i + 1, res2, last2, '+');
                } else {
                    for (char op : {'+', '-', '*'}) {
                        now.push_back(op);
                        dfs(i + 1, res2, last2, op);
                        now.pop_back();
                    }
                }
                if (view[pos] == '0')
                    break;
            }
            now.resize(sz);
        }
    }
    vector<string> addOperators(string num, int target) {
        this->view = num;
        this->target = target;
        dfs(0, 0, 0, '+');
        return ret;
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
    auto res = s.addOperators("2147483648", -2147483648);
    debug(res);
    return 0;
}
#endif
// @lc code=end
