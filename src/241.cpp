// id:300976873
// runtime:4 ms
// memory:12.2 MB
// title:Different Ways to Add Parentheses
// translatedTitle:为运算表达式设计优先级
// questionId:241
// time:2022-04-16 19:21:04

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
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

class Solution {
  public:
    vector<int> solve(string_view view) {
        vector<int> V;
        for (int i = 0; i < (int)view.size(); i++) {
            if (!isdigit(view[i])) {
                V.push_back(i);
            }
        }
        if (V.empty()) {
            int val = 0;
            for (int i = 0; i < (int)view.size(); i++) {
                val = val * 10 + view[i] - '0';
            }
            debug(val);
            return vector<int>{val};
        } else {
            vector<int> ret;
            for (int i : V) {
                auto left = solve(view.substr(0, i));
                auto right = solve(view.substr(i + 1, view.size() - i - 1));
                if (view[i] == '+') {
                    for (auto val1 : left)
                        for (auto val2 : right)
                            ret.push_back(val1 + val2);
                } else if (view[i] == '-') {
                    for (auto val1 : left)
                        for (auto val2 : right)
                            ret.push_back(val1 - val2);
                } else {
                    for (auto val1 : left)
                        for (auto val2 : right)
                            ret.push_back(val1 * val2);
                }
            }
            debug(ret);
            return ret;
        }
    }
    vector<int> diffWaysToCompute(const string &expression) {
        return solve(string_view(expression));
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
    auto res = s.diffWaysToCompute("2-1-1");
    debug(res);
    return 0;
}
#endif