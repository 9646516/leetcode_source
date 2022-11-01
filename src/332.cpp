// id:309460923
// runtime:28 ms
// memory:15 MB
// title:Reconstruct Itinerary
// translatedTitle:重新安排行程
// questionId:332
// time:2022-05-05 15:47:03

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
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

class Solution {
    vector<int> res;
    vector<vector<int>> V;
    void dfs(int x) {
        while (!V[x].empty()) {
            int to = V[x].back();
            V[x].pop_back();
            dfs(to);
        }
        res.push_back(x);
    }

  public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        vector<string> H;
        for (auto &i : tickets) {
            for (auto &j : i) {
                H.push_back(j);
            }
        }
        sort(H.begin(), H.end());
        H.resize(unique(H.begin(), H.end()) - H.begin());
        V.resize(H.size());
        for (auto &i : tickets) {
            int src = lower_bound(H.begin(), H.end(), i[0]) - H.begin();
            int dst = lower_bound(H.begin(), H.end(), i[1]) - H.begin();
            V[src].push_back(dst);
        }
        for (auto &i : V) {
            sort(i.begin(), i.end(), greater<int>());
        }
        int src = lower_bound(H.begin(), H.end(), string("JFK")) - H.begin();
        dfs(src);
        vector<string> ret;
        for (int i = (int)res.size() - 1; i >= 0; i--) {
            ret.push_back(H[res[i]]);
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
    // auto res = s.solve(data);
    // debug(res);
    return 0;
}
#endif