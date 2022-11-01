// id:313793473
// runtime:280 ms
// memory:74.3 MB
// title:Concatenated Words
// translatedTitle:连接词
// questionId:472
// time:2022-05-15 15:50:07

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
 * @lc app=leetcode.cn id=472 lang=cpp
 *
 * [472] 连接词
 */

class Solution {
  public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &V) {
        const uint64_t SEED = 233;
        vector<uint64_t> P;
        P.push_back(1);
        for (int i = 1; i < 10000 + 5; i++) {
            P.push_back(P.back() * SEED);
        }
        vector<uint64_t> H;
        multiset<uint64_t> st;
        for (auto &i : V) {
            uint64_t now = 0;
            for (int j = 0; j < (int)i.size(); j++) {
                now = now * SEED + i[j];
            }
            H.push_back(now);
            st.insert(now);
        }
        vector<string> ret;
        for (int i = 0; i < (int)V.size(); i++) {
            if (V[i].empty())
                continue;
            st.erase(H[i]);
            vector<int> dp(V[i].size(), -1);
            function<bool(int)> gao = [&](int x) -> bool {
                if (x >= V[i].size())
                    return 1;
                if (dp[x] != -1)
                    return dp[x];
                uint64_t now = 0;
                for (int j = x; j < (int)V[i].size(); j++) {
                    now = now * SEED + V[i][j];
                    if (st.count(now) && gao(j + 1)) {
                        return dp[x] = 1;
                    }
                }
                return dp[x] = 0;
            };
            if (gao(0))
                ret.push_back(V[i]);
            st.insert(H[i]);
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
    vector<string> d{"ratcatdogcat", "rat", "catsdogcats"};
    Solution s;
    auto res = s.findAllConcatenatedWordsInADict(d);
    debug(res);
    return 0;
}
#endif
// @lc code=end
