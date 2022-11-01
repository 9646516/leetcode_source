// id:318441040
// runtime:40 ms
// memory:20.3 MB
// title:Erect the Fence
// translatedTitle:安装栅栏
// questionId:587
// time:2022-05-26 20:58:41

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
 * @lc app=leetcode.cn id=587 lang=cpp
 *
 * [587] 安装栅栏
 */

class Solution {
  public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        vector<pair<int, int>> V; // y,x
        for (auto &i : trees) {
            V.emplace_back(i[1], i[0]);
        }
        sort(V.begin(), V.end());
        vector<vector<int>> ret;
        for (int i = 0; i < 2; i++) {
            if (i & 1) {
                reverse(V.begin(), V.end());
            }
            deque<pair<int, int>> q;
            q.push_back(V[0]);
            for (int i = 1; i < (int)V.size(); i++) {
                auto [y, x] = V[i];
                while (q.size() >= 2) {
                    auto [y0, x0] = q.end()[-2];
                    auto [y1, x1] = q.end()[-1];
                    int oy0 = y1 - y0;
                    int ox0 = x1 - x0;
                    int oy1 = y - y1;
                    int ox1 = x - x1;
                    if (ox0 * oy1 - ox1 * oy0 < 0)
                        q.pop_back();
                    else
                        break;
                }
                q.emplace_back(y, x);
            }
            for (auto [y, x] : q) {
                ret.push_back({x, y});
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif