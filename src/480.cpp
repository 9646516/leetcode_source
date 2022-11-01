// id:313847661
// runtime:40 ms
// memory:18.9 MB
// title:Sliding Window Median
// translatedTitle:滑动窗口中位数
// questionId:480
// time:2022-05-15 17:25:09

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
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

class Solution {
  public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        deque<int> q;
        multiset<int> f, s;
        int n1, n2;
        if (k & 1)
            n1 = k / 2 + 1;
        else
            n1 = k / 2;
        n2 = k - n1;
        vector<double> ret;
        for (int i : nums) {
            q.push_back(i);
            if (f.size() < n1)
                f.insert(i);
            else {
                f.insert(i);
                auto r = *prev(f.end());
                f.erase(prev(f.end()));
                s.insert(r);
            }
            if (q.size() > k) {
                auto to_remove = q.front();
                q.pop_front();
                if (s.count(to_remove))
                    s.erase(s.lower_bound(to_remove));
                else {
                    f.erase(f.lower_bound(to_remove));
                    f.insert(*s.begin());
                    s.erase(s.begin());
                }
            }
            debug(f, s);
            if (q.size() == k) {
                if (k & 1) {
                    ret.push_back(*prev(f.end()));
                } else {
                    ret.push_back((1.0 * (*prev(f.end())) + *s.begin()) / 2.0);
                }
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
    vector<int> data{1, 3, -1, -3, 5, 3, 6, 7};
    Solution s;
    auto res = s.medianSlidingWindow(data, 3);
    debug(res);
    return 0;
}
#endif