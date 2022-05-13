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
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

class Solution {
  public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> times;
        for (int i = 0; i < (int)s.size();) {
            if (isdigit(s[i])) {
                int now = 0;
                for (;;) {
                    now = now * 10 + s[i] - '0';
                    i++;
                    if (i == s.size()) {
                        break;
                    }
                    if (!isdigit(s[i])) {
                        break;
                    }
                }
                times.push(now);
            } else if (s[i] == ']') {
                int res = times.top();
                times.pop();
                vector<string> ret;
                while (true) {
                    auto t = st.top();
                    st.pop();
                    if (t == "[")
                        break;
                    ret.push_back(t);
                }
                reverse(ret.begin(), ret.end());
                string now;
                for (auto i : ret)
                    now.append(i);
                string ans;
                while (res--) {
                    ans.append(now);
                }
                st.push(ans);
                i++;
            } else {
                st.push(string(1, s[i]));
                i++;
            }
        }
        vector<string> ret;
        while (!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        string fin;
        for (auto i : ret) {
            fin.append(i);
        }
        return fin;
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
    auto res = s.decodeString("3[a]2[bc]");
    debug(res);
    return 0;
}
#endif
// @lc code=end
