// id:300960165
// runtime:276 ms
// memory:130.8 MB
// title:Sliding Window Maximum
// translatedTitle:滑动窗口最大值
// questionId:239
// time:2022-04-16 18:28:41

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
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &V, int k) {
        // deque<int> q;
        // multiset<int, greater<int>> st;
        // for (int i = 0; i < k; i++) {
        //     q.push_back(V[i]);
        //     st.insert(V[i]);
        // }
        // vector<int> ret;
        // ret.push_back(*st.begin());
        // for (int i = k; i < (int)V.size(); i++) {
        //     int to_remove = q.front();
        //     q.pop_front();
        //     st.erase(st.lower_bound(to_remove));

        //     q.push_back(V[i]);
        //     st.insert(V[i]);
        //     ret.push_back(*st.begin());
        // }
        // return ret;
        deque<pair<int, int>> st;
        for (int i = 0; i < k; i++) {
            while (!st.empty() && st.back().first < V[i]) {
                st.pop_back();
            }
            st.push_back({V[i], i});
        }
        debug(st);
        vector<int> ret;
        ret.push_back(st.front().first);
        for (int i = k; i < (int)V.size(); i++) {
            int l = i - k + 1;
            while (!st.empty() && st.front().second < l) {
                st.pop_front();
            }
            while (!st.empty() && st.back().first < V[i]) {
                st.pop_back();
            }
            st.push_back({V[i], i});
            debug(st);
            ret.push_back(st.front().first);
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
    vector<int> data{1, 3, 1, 2, 0, 5};
    Solution s;
    auto res = s.maxSlidingWindow(data, 3);
    debug(res);
    return 0;
}
#endif