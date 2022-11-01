// id:367111306
// runtime:28 ms
// memory:6.6 MB
// title:Verbal Arithmetic Puzzle
// translatedTitle:口算难题
// questionId:1429
// time:2022-09-25 20:43:14

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
 * @lc app=leetcode.cn id=1307 lang=cpp
 *
 * [1307] 口算难题
 */

class Solution {
  public:
    vector<int> P[255];
    string G;
    int val[255];
    int lead[255];
    bool dfs(int pos, int used, int lbit) {
        if (pos == G.size()) {
            return lbit == 0;
        }
        for (int i : P[pos]) {
            if (val[i] == -1) {
                for (int j = 0; j <= 9; j++) {
                    if (lead[i] && j == 0)
                        continue;
                    if ((used >> j) & 1)
                        continue;
                    val[i] = j;
                    if (dfs(pos, used | 1 << j, lbit))
                        return 1;
                    val[i] = -1;
                }
                return 0;
            }
        }
        if (val[G[pos]] == -1) {
            for (int j = 0; j <= 9; j++) {
                if (lead[G[pos]] && j == 0)
                    continue;
                if ((used >> j) & 1)
                    continue;
                val[G[pos]] = j;
                if (dfs(pos, used | 1 << j, lbit))
                    return 1;
                val[G[pos]] = -1;
            }
            return 0;
        }
        int tot = lbit;
        for (int i : P[pos]) {
            tot += val[i];
        }
        tot -= val[G[pos]];
        if (tot < 0 || tot % 10 != 0)
            return 0;
        else
            return dfs(pos + 1, used, tot / 10);
    }
    bool isSolvable(vector<string> &words, string result) {
        for (auto &i : words)
            if (i.size() > result.size())
                return 0;
        memset(val, -1, sizeof(val));
        memset(lead, 0, sizeof(lead));
        if (result.size() != 1)
            lead[result[0]] = 1;
        for (auto &i : words) {
            if (i.size() != 1)
                lead[i[0]] = 1;
            reverse(i.begin(), i.end());
            for (int j = 0; j < (int)i.size(); j++) {
                P[j].push_back(i[j]);
            }
        }
        reverse(result.begin(), result.end());
        G = result;
        return dfs(0, 0, 0);
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