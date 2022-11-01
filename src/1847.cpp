// id:360263091
// runtime:556 ms
// memory:153 MB
// title:Closest Room
// translatedTitle:最近的房间
// questionId:1957
// time:2022-09-07 16:30:14

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
 * @lc app=leetcode.cn id=1847 lang=cpp
 *
 * [1847] 最近的房间
 */

class Solution {
  public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {
        vector<pair<int, int>> V;
        vector<tuple<int, int, int>> q;
        for (auto &i : rooms) {
            V.push_back({i[1], i[0]});
        }
        for (int i = 0; i < (int)queries.size(); i++) {
            q.push_back({queries[i][1], queries[i][0], i});
        }
        sort(V.begin(), V.end(), greater<pair<int, int>>());
        sort(q.begin(), q.end(), greater<tuple<int, int, int>>());
        int pos = 0;
        vector<int> ret(queries.size());
        set<int> st;
        for (auto [a, b, c] : q) {
            while (pos < (int)V.size() && V[pos].first >= a) {
                int id = V[pos].second;
                st.insert(id);
                pos++;
            }
            debug(a, b, st);
            auto now = st.lower_bound(b);
            int ans = INF;
            if (now != st.end()) {
                ans = *now;
            }
            if (now != st.begin()) {
                now--;
                if (abs(*now - b) <= abs(ans - b)) {
                    ans = *now;
                }
            }

            if (ans == INF)
                ans = -1;
            ret[c] = ans;
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
    vector<vector<int>> a{{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
    vector<vector<int>> b{{2, 3}, {2, 4}, {2, 5}};

    Solution s;
    auto res = s.closestRoom(a, b);
    debug(res);
    return 0;
}
#endif