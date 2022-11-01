// id:356959492
// runtime:840 ms
// memory:270.6 MB
// title:Valid Arrangement of Pairs
// translatedTitle:合法重新排列数对
// questionId:2201
// time:2022-08-30 23:12:52

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
 * @lc app=leetcode.cn id=2097 lang=cpp
 *
 * [2097] 合法重新排列数对
 */

class Solution {
  public:
    vector<int> G[200000 + 5];
    int in[200000 + 5], out[200000 + 5];
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {
        const int N = pairs.size();
        vector<int> V;
        for (auto i : pairs) {
            V.push_back(i[0]);
            V.push_back(i[1]);
        }
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        memset(in, 0, sizeof(int) * V.size());
        memset(out, 0, sizeof(int) * V.size());
        for (auto &i : pairs) {
            i[0] = lower_bound(V.begin(), V.end(), i[0]) - V.begin();
            i[1] = lower_bound(V.begin(), V.end(), i[1]) - V.begin();
            G[i[0]].push_back(i[1]);
            in[i[1]]++;
            out[i[0]]++;
        }
        int s = 0;
        for (int i = 0; i < (int)V.size(); i++) {
            if (in[i] < out[i]) {
                s = i;
                break;
            }
        }
        vector<int> res;
        function<void(int)> dfs = [&](int x) {
            while (!G[x].empty()) {
                int to = G[x].back();
                G[x].pop_back();
                dfs(to);
            }
            res.push_back(x);
        };
        dfs(s);
        reverse(res.begin(), res.end());
        vector<vector<int>> fin;
        for (int i = 1; i < (int)res.size(); i++)
            fin.push_back({V[res[i - 1]], V[res[i]]});
        return fin;
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