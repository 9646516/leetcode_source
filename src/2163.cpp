// id:355516801
// runtime:376 ms
// memory:170.4 MB
// title:Minimum Difference in Sums After Removal of Elements
// translatedTitle:删除元素后和的最小差值
// questionId:2267
// time:2022-08-27 14:24:02

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
 * @lc app=leetcode.cn id=2163 lang=cpp
 *
 * [2163] 删除元素后和的最小差值
 */

class Solution {
  public:
    long long minimumDifference(vector<int> &nums) {
        const int N = nums.size() / 3;
        vector<ll> P;
        for (int i : nums)
            P.push_back(i);
        for (int i = 1; i < (int)nums.size(); i++) {
            P[i] += P[i - 1];
        }
        vector<ll> mx;
        {
            ll xs = 0;
            priority_queue<int> st;
            for (int i = 0; i < N; i++) {
                st.push(nums[i]);
                xs += nums[i];
            }
            mx.push_back(xs);
            for (int i = N; i < 2 * N; i++) {
                st.push(nums[i]);
                xs += nums[i];
                xs -= st.top();
                st.pop();
                mx.push_back(xs);
            }
        }

        vector<ll> minn;
        {
            ll xs = 0;
            priority_queue<int, vector<int>, greater<int>> st;
            for (int i = (int)nums.size() - 1; i >= N + N; i--) {
                st.push(nums[i]);
                xs += nums[i];
            }
            minn.push_back(xs);
            for (int i = 2 * N - 1; i >= N; i--) {
                st.push(nums[i]);
                xs += nums[i];
                xs -= st.top();
                st.pop();
                minn.push_back(xs);
            }
        }
        reverse(minn.begin(), minn.end());
        ll ans = 1e18;
        for (int i = 0; i < (int)mx.size(); i++)
            ans = min(ans, mx[i] - minn[i]);
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