// id:371995227
// runtime:36 ms
// memory:22.7 MB
// title:Maximum Sum of 3 Non-Overlapping Subarrays
// translatedTitle:三个无重叠子数组的最大和
// questionId:689
// time:2022-10-11 17:38:16

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
 * @lc app=leetcode.cn id=689 lang=cpp
 *
 * [689] 三个无重叠子数组的最大和
 */
int P[20005];
int S[20005];
int pos1[20005];
int val1[20005];
int pos2[20005];
int val2[20005];
class Solution {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        const int N = nums.size();
        for (int i = 0; i < N; i++) {
            P[i] = nums[i];
            S[i] = nums[i];
        }
        for (int i = N - 2; i >= 0; i--) {
            S[i] += S[i + 1];
        }
        for (int i = 1; i < N; i++) {
            P[i] += P[i - 1];
        }
        {
            int pos = -1, val = -1;
            for (int i = k - 1; i < N; i++) {
                int l = i - k + 1;
                int xs = P[i];
                if (l)
                    xs -= P[l - 1];
                if (val < xs) {
                    val = xs;
                    pos = i;
                }
                pos1[i] = pos - k + 1;
                val1[i] = val;
            }
        }
        {
            int pos = -1, val = -1;
            for (int i = N - k; i >= 0; i--) {
                int r = i + k - 1;
                int xs = S[i];
                if (r != N - 1)
                    xs -= S[r + 1];
                if (val <= xs) {
                    val = xs;
                    pos = i;
                }
                pos2[i] = pos;
                val2[i] = val;
            }
        }
        int ans = -1;
        vector<int> ret;
        for (int i = k; i + k + k - 1 < N; i++) {
            int r = i + k - 1;
            int tot = val1[i - 1] + val2[r + 1] + P[r] - P[i - 1];
            vector<int> now{pos1[i - 1], i, pos2[r + 1]};
            if (tot > ans) {
                ans = tot;
                ret = now;
            } else if (tot == ans && ret > now) {
                ans = tot;
                ret = now;
            }
        }
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif