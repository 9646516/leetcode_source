// id:357820099
// runtime:920 ms
// memory:96.2 MB
// title:Kth Smallest Product of Two Sorted Arrays
// translatedTitle:两个有序数组的第 K 小乘积
// questionId:2150
// time:2022-09-01 22:07:57

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
 * @lc app=leetcode.cn id=2040 lang=cpp
 *
 * [2040] 两个有序数组的第 K 小乘积
 */

class Solution {
    vector<int> A, B;

    long long gao(long long lim) {
        long long ret = 0;
        for (long long x : A) {
            if (x > 0) {
                if (x * B[0] > lim)
                    continue;
                int head = 0, tail = B.size() - 1;
                while (head < tail) {
                    int mid = (head + tail + 1) >> 1;
                    if (x * B[mid] <= lim)
                        head = mid;
                    else
                        tail = mid - 1;
                }
                ret += head + 1;
            } else if (x < 0) {
                if (x * B[B.size() - 1] > lim)
                    continue;
                int head = 0, tail = B.size() - 1;
                while (head < tail) {
                    int mid = (head + tail) >> 1;
                    if (x * B[mid] <= lim)
                        tail = mid;
                    else
                        head = mid + 1;
                }
                ret += B.size() - head;
            } else if (lim >= 0)
                ret += B.size();
        }
        return ret;
    }

  public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
        A = nums1;
        B = nums2;
        long long head = -1e11, tail = 1e11;
        while (head < tail) {
            long long mid = (head + tail) >> 1;
            long long x = gao(mid);
            if (x >= k)
                tail = mid;
            else
                head = mid + 1;
        }
        return head;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{2};
    vector<int> b{2, 3};
    Solution s;
    auto res = s.kthSmallestProduct(a, b, 2);
    debug(res);
    return 0;
}
#endif