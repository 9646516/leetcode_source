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
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */
class Solution {
  public:
    string optimalDivision(vector<int> &nums) {
        double minn[15][15];
        double maxx[15][15];
        string minn_s[15][15];
        string maxx_s[15][15];
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                minn[i][j] = numeric_limits<double>::max();
                maxx[i][j] = numeric_limits<double>::min();
            }
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            minn[i][i] = maxx[i][i] = nums[i];
            minn_s[i][i] = maxx_s[i][i] = to_string(nums[i]);
        }
        for (int len = 2; len <= (int)nums.size(); len++) {
            for (int L = 0; L + len - 1 < (int)nums.size(); L++) {
                int R = L + len - 1;
                for (int mid = L; mid < R; mid++) {
                    if (minn[L][R] > minn[L][mid] / maxx[mid + 1][R]) {
                        minn[L][R] = minn[L][mid] / maxx[mid + 1][R];
                        if (mid + 1 == R) {
                            minn_s[L][R] = minn_s[L][mid] + "/" + maxx_s[mid + 1][R];
                        } else {
                            minn_s[L][R] = minn_s[L][mid] + "/(" + maxx_s[mid + 1][R] + ")";
                        }
                    }

                    if (maxx[L][R] < maxx[L][mid] / minn[mid + 1][R]) {
                        maxx[L][R] = maxx[L][mid] / minn[mid + 1][R];
                        if (mid + 1 == R) {
                            maxx_s[L][R] = maxx_s[L][mid] + "/" + minn_s[mid + 1][R];
                        } else {
                            maxx_s[L][R] = maxx_s[L][mid] + "/(" + minn_s[mid + 1][R] + ")";
                        }
                    }
                }
            }
        }
        return maxx_s[0][nums.size() - 1];
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
