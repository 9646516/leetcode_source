// id:296925031
// runtime:20 ms
// memory:86.9 MB
// title:Median of Two Sorted Arrays
// translatedTitle:寻找两个正序数组的中位数
// questionId:4
// time:2022-04-08 19:48:08

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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
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
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        if ((len1 + len2) & 1) {
            return solve<false>(nums1.data(), len1, nums2.data(), len2, (len1 + len2) / 2);
        } else {
            return solve<true>(nums1.data(), len1, nums2.data(), len2, (len1 + len2) / 2 - 1);
        }
    }
    template <bool wrap> double solve(int *V1, int len1, int *V2, int len2, int k) {
        if (len1 == 0) {
            if constexpr (wrap)
                return (V2[k] + V2[k + 1]) / 2.0;
            else
                return V2[k];
        } else if (len2 == 0) {
            if constexpr (wrap)
                return (V1[k] + V1[k + 1]) / 2.0;
            else
                return V1[k];
        } else if (k == 1) {
            if (V1[0] < V2[0]) {
                return solve<wrap>(V1 + 1, len1 - 1, V2, len2, k - 1);
            } else {
                return solve<wrap>(V1, len1, V2 + 1, len2 - 1, k - 1);
            }
        } else if (k == 0) {
            if constexpr (wrap) {
                if (V1[0] < V2[0]) {
                    if (len1 > 1) {
                        return (V1[0] + min(V1[1], V2[0])) / 2.0;
                    } else {
                        return (V1[0] + V2[0]) / 2.0;
                    }
                } else {
                    if (len2 > 1) {
                        return (V2[0] + min(V2[1], V1[0])) / 2.0;
                    } else {
                        return (V1[0] + V2[0]) / 2.0;
                    }
                }
            } else {
                return min(V1[0], V2[0]);
            }
        } else {
            int mid = k / 2;
            // choose v1
            {

                int step = min(len1, mid);
                int val = V1[step - 1];
                int step2 = lower_bound(V2, V2 + len2, val) - V2;
                int tot = step + step2;
                debug("v1", step, step2);
                if (tot <= k) {
                    debug(step, step2);
                    return solve<wrap>(V1 + step, len1 - step, V2 + step2, len2 - step2, k - tot);
                }
            }
            // choose v2
            {
                int step = min(len2, mid);
                int val = V2[step - 1];
                int step2 = lower_bound(V1, V1 + len1, val) - V1;
                int tot = step + step2;
                debug("v2", step, step2);
                debug(step2, step);
                return solve<wrap>(V1 + step2, len1 - step2, V2 + step, len2 - step, k - tot);
            }
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
    vector<int> V{3};
    vector<int> V2{1, 2, 4, 5};
    Solution s;
    auto res = s.findMedianSortedArrays(V, V2);
    debug(res);
    return 0;
}
#endif