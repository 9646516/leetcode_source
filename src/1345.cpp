// id:366066132
// runtime:392 ms
// memory:105.5 MB
// title:Jump Game IV
// translatedTitle:跳跃游戏 IV
// questionId:1447
// time:2022-09-22 20:03:04

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
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

class Solution {
  public:
    int minJumps(vector<int> &arr) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < (int)arr.size(); i++)
            mp[arr[i]].push_back(i);
        int dis[50000 + 1];
        memset(dis, 0x3f, sizeof(dis));
        dis[0] = 0;
        multiset<pair<int, int>> st;
        st.insert({0, 0});
        set<int> vis;
        while (!st.empty()) {
            auto [d, now] = *st.begin();
            if (now == arr.size() - 1)
                break;
            st.erase(st.begin());
            if (dis[now] < d)
                continue;
            if (now) {
                if (dis[now - 1] > d + 1) {
                    dis[now - 1] = d + 1;
                    st.insert({d + 1, now - 1});
                }
            }
            if (dis[now + 1] > d + 1) {
                dis[now + 1] = d + 1;
                st.insert({d + 1, now + 1});
            }
            if (!vis.count(arr[now])) {
                vis.insert(arr[now]);
                for (int i : mp[arr[now]]) {
                    if (dis[i] > d + 1) {
                        dis[i] = d + 1;
                        st.insert({d + 1, i});
                    }
                }
            }
        }
        return dis[arr.size() - 1];
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