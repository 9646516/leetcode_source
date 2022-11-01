// id:367754960
// runtime:1084 ms
// memory:151.3 MB
// title:Shortest Common Supersequence 
// translatedTitle:最短公共超序列
// questionId:1170
// time:2022-09-27 15:59:18

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
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */
#define GX(x, y) (((x)*b.size()) + (y))
#define add(x, y) V[x].push_back(y)
int fa[1001 * 1001 + 5];
int d[1001 * 1001 + 5];
class Solution {
  public:
    vector<int> V[1001 * 1001 + 5];
    string shortestCommonSupersequence(string a, string b) {
        a = '$' + a;
        b = '$' + b;
        const int S = GX(0, 0);
        for (int i = 0; i < a.size(); i++) {
            for (int j = 0; j < b.size(); j++) {
                if (i + 1 < a.size())
                    add(GX(i, j), GX(i + 1, j));
                if (j + 1 < b.size())
                    add(GX(i, j), GX(i, j + 1));
                if (i + 1 < a.size() && j + 1 < b.size() && a[i + 1] == b[j + 1]) {
                    add(GX(i, j), GX(i + 1, j + 1));
                }
            }
        }
        memset(d, 0x3f, sizeof(d));
        d[GX(0, 0)] = 0;
        queue<pair<int, int>> st;
        st.push({0, GX(0, 0)});
        while (!st.empty()) {
            auto [dis, pos] = st.front();
            st.pop();
            if (d[pos] < dis)
                continue;
            for (auto &i : V[pos]) {
                if (d[i] > dis + 1) {
                    fa[i] = pos;
                    d[i] = dis + 1;
                    st.push({dis + 1, i});
                }
            }
        }
        string ans;
        auto split = [&b](int val) -> pair<int, int> {
            int f = val / b.size();
            int s = val % b.size();
            return {f, s};
        };
        auto solve = [&](int pre, int now) {
            auto [x1, y1] = split(pre);
            auto [x2, y2] = split(now);
            if (x1 == x2)
                ans.push_back(b[y1]);
            else
                ans.push_back(a[x1]);
        };
        int now = GX(a.size() - 1, b.size() - 1);
        while (now != 0) {
            int f = fa[now];
            solve(now, f);
            now = f;
        }
        reverse(ans.begin(), ans.end());
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