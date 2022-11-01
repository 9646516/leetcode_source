// id:367888153
// runtime:80 ms
// memory:26.4 MB
// title:Odd Even Jump
// translatedTitle:奇偶跳
// questionId:1017
// time:2022-09-27 21:39:11

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
 * @lc app=leetcode.cn id=975 lang=cpp
 *
 * [975] 奇偶跳
 */
int dp[20000 + 5][2];
int mp[100000 + 5];
class Solution {
  public:
    int oddEvenJumps(vector<int> &arr) {
        set<int> st;
        const int N = arr.size();
        dp[N - 1][0] = dp[N - 1][1] = 1;
        st.insert(arr[N - 1]);
        mp[arr[N - 1]] = N - 1;
        for (int i = N - 2; i >= 0; i--) {
            {
                auto pos = st.lower_bound(arr[i]);
                if (pos != st.end()) {
                    dp[i][1] = dp[mp[*pos]][0];
                } else {
                    dp[i][1] = 0;
                }
            }
            {
                auto pos = st.upper_bound(arr[i]);
                if (pos != st.begin()) {
                    pos--;
                    dp[i][0] = dp[mp[*pos]][1];
                } else {
                    dp[i][0] = 0;
                }
            }
            st.insert(arr[i]);
            mp[arr[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
            ans += dp[i][1];
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif