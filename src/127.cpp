// id:298967459
// runtime:636 ms
// memory:19.8 MB
// title:Word Ladder
// translatedTitle:单词接龙
// questionId:127
// time:2022-04-12 18:08:47

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
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

class Solution {
  public:
    inline bool test(const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < (int)a.size(); i++) {
            cnt += a[i] != b[i];
        }
        return cnt == 1;
    }
    int ladderLength(const string &src, const string &sink, vector<string> &str) {
        int sink_index = -1;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == sink) {
                sink_index = i;
            }
        }
        if (sink_index == -1) {
            return 0;
        } else {
            vector<vector<int>> V(str.size() + 5);
            for (int i = 0; i < (int)str.size(); i++) {
                for (int j = i + 1; j < (int)str.size(); j++) {
                    if (test(str[i], str[j])) {
                        V[i].push_back(j);
                        V[j].push_back(i);
                    }
                }
            }
            for (int i = 0; i < (int)str.size(); i++) {
                if (test(src, str[i])) {
                    V[str.size()].push_back(i);
                    V[i].push_back(str.size());
                }
            }
            multiset<pair<int, int>> st;
            vector<int> dis(str.size() + 5, INF);
            dis[str.size()] = 0;
            st.emplace(str.size(), 0);
            while (!st.empty()) {
                auto [now, d] = *st.begin();
                d++;
                st.erase(st.begin());
                for (int i : V[now]) {
                    if (dis[i] > d) {
                        dis[i] = d;
                        st.emplace(i, d);
                    }
                }
            }
            return dis[sink_index] == INF ? 0 : dis[sink_index] + 1;
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif