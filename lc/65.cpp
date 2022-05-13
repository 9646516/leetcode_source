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
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

class Solution {
  public:
    bool solve_int(string_view s) {
        if (s.empty())
            return false;
        if (s[0] == '+' || s[0] == '-') {
            s = s.substr(1);
        }
        if (s.empty())
            return false;
        for (int i = 0; i < (int)s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    bool solve_float_with_e(string_view s) {
        if (s.empty())
            return false;
        for (int i = 0; i < (int)s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                continue;
            } else if (s[i] == '.') {
                return solve_dot(s.substr(i + 1), i != 0);
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i)
                    return false;
                else
                    return solve_int(s.substr(i + 1));
            } else {
                return false;
            }
        }
        return true;
    }
    bool solve_int_with_e(string_view s) {
        if (s.empty())
            return false;
        for (int i = 0; i < (int)s.size(); i++) {
            if ('0' <= s[i] && s[i] <= '9') {
                continue;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (!i)
                    return false;
                else
                    return solve_int(s.substr(i + 1));
            } else {
                return false;
            }
        }
        return true;
    }
    bool solve_dot(string_view s, bool has_prefix) {
        debug(has_prefix);
        if (!has_prefix && s.empty())
            return false;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (!has_prefix && !i)
                    return false;
                else
                    return solve_int(s.substr(i + 1));
            } else if (isdigit(s[i])) {
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isNumber(string s) {
        if (isdigit(s[0])) {
            return solve_int_with_e(string_view(s.c_str())) ||
                   solve_float_with_e(string_view(s.c_str()));
        } else if (s[0] == '+' || s[0] == '-') {
            if (s.size() == 1)
                return false;
            else
                return solve_int_with_e(string_view(s.c_str() + 1)) ||
                       solve_float_with_e(string_view(s.c_str() + 1));
        } else if (s[0] == '.') {
            return solve_dot(string_view(s.c_str() + 1), false);
        } else {
            return false;
        }
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
    auto res = s.isNumber("005047e+6");
    debug(res);
    return 0;
}
#endif
// @lc code=end
