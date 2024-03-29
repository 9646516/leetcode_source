// id:363054555
// runtime:308 ms
// memory:7.4 MB
// title:Find Minimum Time to Finish All Jobs
// translatedTitle:完成所有工作的最短时间
// questionId:1825
// time:2022-09-14 23:29:37

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
 * @lc app=leetcode.cn id=1723 lang=cpp
 *
 * [1723] 完成所有工作的最短时间
 */
int dp[1 << 12];
int sum[1 << 12];
class Solution {
  public:
    vector<int> V;
    int X;
    int dfs(int mask) {
        if (mask == 0) {
            return 0;
        } else if (dp[mask] != -1)
            return dp[mask];
        else {
            int ret = INF;
            for (int i = mask; i; i = (i - 1) & mask) {
                if (sum[i] <= X) {
                    ret = min(dfs(mask ^ i) + 1, ret);
                }
            }
            return dp[mask] = ret;
        }
    }
    int minimumTimeRequired(vector<int> &jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        memset(sum, 0, sizeof(sum));
        int n = jobs.size();
        int p = (n / k) + (n % k != 0);
        int L = accumulate(jobs.end() - p, jobs.end(), 0),
            R = accumulate(jobs.begin(), jobs.begin() + p, 0);
        int ans = R;
        V = jobs;

        for (int i = 0; i < (1 << n); i++) {
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    sum[i] += jobs[j];
                }
            }
        }

        while (L <= R) {
            int mid = (L + R) / 2;
            memset(dp, -1, sizeof(dp));
            X = mid;
            if (dfs((1 << n) - 1) <= k) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif