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
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

class Solution {
  public:
    void calc1(vector<char> &ops, vector<int> &number) {
        while (!ops.empty() && ops.back() != '(' && ops.back() != '+' && ops.back() != '-') {
            char op = ops.back();
            ops.pop_back();
            int val = number.back();
            number.pop_back();
            int val0 = number.back();
            number.pop_back();
            if (op == '*')
                number.push_back(val0 * val);
            else
                number.push_back(val0 / val);
        }
    };
    void calc2(vector<char> &ops, vector<int> &number) {
        while (!ops.empty() && ops.back() != '(') {
            char op = ops.back();
            ops.pop_back();
            int val = number.back();
            number.pop_back();
            int val0 = number.back();
            number.pop_back();
            if (op == '+')
                number.push_back(val0 + val);
            else if (op == '-')
                number.push_back(val0 - val);
            else if (op == '*')
                number.push_back(val0 * val);
            else
                number.push_back(val0 / val);
        }
    };
    int calculate(string s) {
        vector<string> V;
        string now;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' ||
                     s[i] == ')') {
                if (!now.empty()) {
                    V.push_back(now);
                    now.clear();
                    V.push_back(string(1, s[i]));
                } else {
                    V.push_back(string(1, s[i]));
                }
            } else {
                now.push_back(s[i]);
            }
        }
        if (!now.empty()) {
            V.push_back(now);
            now.clear();
        }
        vector<string> V2;
        for (auto &i : V) {
            if (i == "+" || i == "-") {
                if (V2.empty() || V2.back() == "(") {
                    V2.push_back("0");
                }
            }
            V2.push_back(i);
        }
        V = move(V2);
        vector<int> number;
        vector<char> ops;

        for (auto i : V) {
            if (isdigit(i[0])) {
                number.push_back(stol(i));
            } else if (i[0] == '(') {
                ops.push_back('(');
            } else if (i[0] == '+' || i[0] == '-') {
                calc2(ops, number);
                ops.push_back(i[0]);
            } else if (i[0] == '*' || i[0] == '/') {
                calc1(ops, number);
                ops.push_back(i[0]);
            } else if (i[0] == ')') {
                calc2(ops, number);
                ops.pop_back();
            }
        }
        debug(number);
        debug(ops);
        calc2(ops, number);

        int res = 0;
        while (!ops.empty()) {
            if (ops.back() == '+')
                res += number.back();
            else
                res -= number.back();
            ops.pop_back();
            number.pop_back();
        }
        if (!number.empty())
            res += number[0];
        return res;
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
    auto res = s.calculate("1-5+10");
    debug(res);
    return 0;
}
#endif
// @lc code=end
