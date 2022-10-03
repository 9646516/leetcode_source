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
 * @lc app=leetcode.cn id=828 lang=cpp
 *
 * [828] 统计子串中的唯一字符
 */
class Solution {
  public:
    int uniqueLetterString(string s) {
        const int N = s.size();
        vector<int> V[26];
        for (int i = 0; i < s.size(); i++) {
            V[s[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            debug(V[i]);
            if (V[i].empty()) {
                continue;
            } else if (V[i].size() == 1) {
                int L = V[i][0] - 0 + 1;
                int R = (N - 1) - V[i][0] + 1;
                debug(L, R);
                ans += L * R;
            } else {
                for (int j = 1; j + 1 < V[i].size(); j++) {
                    int L = V[i][j] - (V[i][j - 1] + 1) + 1;
                    int R = (V[i][j + 1] - 1) - V[i][j] + 1;
                    ans += L * R;
                    debug(L, R);
                }
                {
                    int L = V[i][0] - 0 + 1;
                    int R = (V[i][1] - 1) - V[i][0] + 1;
                    ans += L * R;
                    debug(L, R);
                }
                {
                    int L = V[i][V[i].size() - 1] - (V[i][V[i].size() - 2] + 1) + 1;
                    int R = (N - 1) - V[i][V[i].size() - 1] + 1;
                    ans += L * R;
                    debug(L, R);
                }
            }
        }
        return ans;
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
    string sb = "ABA";
    auto res = s.uniqueLetterString(sb);
    debug(res);
    return 0;
}
#endif
// @lc code=end
