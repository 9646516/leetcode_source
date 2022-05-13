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
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

class Solution {
  public:
    deque<int> F(const vector<int> &x, const int k) {
        deque<int> ret;
        for (int i = 0; i < (int)x.size(); i++) {
            int left = x.size() - i - 1;
            while (!ret.empty() && ret.back() < x[i] && (int)ret.size() - 1 + left + 1 >= k) {
                ret.pop_back();
            }
            ret.push_back(x[i]);
        }
        ret.resize(k);
        return ret;
    }
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<int> ans;
        for (int i = 0; i <= k; i++) {
            int k1 = i, k2 = k - i;
            if (k1 > nums1.size())
                continue;
            if (k2 > nums2.size())
                continue;
            auto x1 = F(nums1, min((int)nums1.size(), k1));
            auto x2 = F(nums2, min((int)nums2.size(), k2));

            debug(k1, x1, k2, x2);
            vector<int> ret;
            for (int i = 0; i < k; i++) {
                if (x1.empty()) {
                    ret.push_back(x2.front());
                    x2.pop_front();
                } else if (x2.empty()) {
                    ret.push_back(x1.front());
                    x1.pop_front();
                } else if (x1 > x2) {
                    ret.push_back(x1.front());
                    x1.pop_front();
                } else {
                    ret.push_back(x2.front());
                    x2.pop_front();
                }
            }
            debug(ret);
            if (ans < ret)
                ans = move(ret);
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
    vector<int> data1{3, 4, 6, 5};
    vector<int> data2{9, 1, 2, 5, 8, 3};
    Solution s;
    auto res = s.maxNumber(data1, data2, 5);
    debug(res);
    return 0;
}
#endif
// @lc code=end
