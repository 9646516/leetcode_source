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
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */
int dp[2][16][20005];
class Solution {
  public:
    int racecar(int target) {
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0][0] = 0;
        queue<tuple<int, int, int, int>> st;
        st.push({0, 0, 0, 0});
        while (!st.empty()) {
            auto [d, neg, speed, pos] = st.front();
            st.pop();
            if (dp[neg][speed][pos] < d)
                continue;
            // A
            {
                int pos2;
                if (neg) {
                    pos2 = pos - (1 << speed);
                } else {
                    pos2 = pos + (1 << speed);
                }
                if (pos2 >= 0 && pos2 <= target * 2) {
                    int speed2 = speed + 1;
                    if ((1 << speed2) <= 2 * target) {
                        if (dp[neg][speed2][pos2] > d + 1) {
                            dp[neg][speed2][pos2] = d + 1;
                            st.push({d + 1, neg, speed2, pos2});
                        }
                    }
                }
            }
            // R
            {
                int neg2 = (neg ^ 1);
                if (dp[neg2][0][pos] > d + 1) {
                    dp[neg2][0][pos] = d + 1;
                    st.push({d + 1, neg2, 0, pos});
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 16; j++)
                ans = min(ans, dp[i][j][target]);
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
// @lc code=end
