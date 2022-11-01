// id:298429763
// runtime:0 ms
// memory:7.1 MB
// title:Restore IP Addresses
// translatedTitle:复原 IP 地址
// questionId:93
// time:2022-04-11 19:01:20

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
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

class Solution {
  public:
    vector<string> ret;
    string_view view;
    vector<int> stack;
    void dfs(int x) {
        if (x == view.size()) {
            if (stack.size() == 4) {
                stringstream ss;
                for (int i = 0; i < 3; i++) {
                    ss << stack[i] << '.';
                }
                ss << stack.back();
                ret.push_back(ss.str());
            }
        } else {
            if (view[x] != '0') {
                int val = 0;
                for (int i = 1; i <= 3; i++) {
                    if (x + i - 1 >= (int)view.size())
                        break;
                    val = val * 10 + view[x + i - 1] - '0';
                    if (val > 255)
                        break;
                    else {
                        stack.push_back(val);
                        dfs(x + i);
                        stack.pop_back();
                    }
                }
            } else {
                stack.push_back(0);
                dfs(x + 1);
                stack.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        view = s;
        dfs(0);
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
    auto res = s.restoreIpAddresses("25525511135");
    debug(res);
    return 0;
}
#endif