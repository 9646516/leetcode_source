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
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

class Solution {
  public:
    pair<int, int> solve(string s) {
        int value = 0;
        int pre = 0;
        string now;
        int pos = 1;
        for (char i : s) {
            if (i == '-' || i == '+') {
                if (!now.empty()) {
                    if (now.back() == 'x') {
                        now.pop_back();
                        if (now.empty())
                            now.push_back('1');
                        pre += (pos ? 1 : -1) * stol(now);
                    } else {
                        value += (pos ? 1 : -1) * stol(now);
                    }
                    now.clear();
                }
                pos = (i == '+');
            } else {
                now.push_back(i);
            }
        }
        if (!now.empty()) {
            if (now.back() == 'x') {
                now.pop_back();
                if (now.empty())
                    now.push_back('1');
                pre += (pos ? 1 : -1) * stol(now);
            } else {
                value += (pos ? 1 : -1) * stol(now);
            }
            now.clear();
        }
        return {value, pre};
    }
    string solveEquation(string str) {
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == '=') {
                string s1 = str.substr(0, i);
                string s2 = str.substr(i + 1);
                auto [val1, pre1] = solve(s1);
                auto [val2, pre2] = solve(s2);
                int val = val1 - val2;
                int pre = pre2 - pre1;
                if (val == 0 && pre == 0) {
                    return "Infinite solutions";
                } else if (val != 0 && pre == 0) {
                    return "No solution";
                } else {
                    val /= pre;
                    stringstream ss;
                    ss << "x=" << val;
                    return ss.str();
                }
            }
        }
        return "";
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
