// id:367813191
// runtime:584 ms
// memory:114 MB
// title:Grid Illumination
// translatedTitle:网格照明
// questionId:1043
// time:2022-09-27 18:05:27

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
 * @lc app=leetcode.cn id=1001 lang=cpp
 *
 * [1001] 网格照明
 */
const int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
class Solution {
  public:
    vector<int> gridIllumination(int n, vector<vector<int>> &lamps, vector<vector<int>> &queries) {
        sort(lamps.begin(), lamps.end());
        lamps.erase(unique(lamps.begin(), lamps.end()), lamps.end());
        set<pair<int, int>> st;
        unordered_map<int, int> row, col, X1, X2;
        for (auto &i : lamps) {
            int a = i[0];
            int b = i[1];
            row[a]++;
            col[b]++;
            X1[a + b]++;
            X2[a - b]++;
            st.insert({a, b});
        }
        vector<int> ret;
        for (auto &i : queries) {
            int a = i[0];
            int b = i[1];
            if (row[a] || col[b] || X1[a + b] || X2[a - b]) {
                ret.push_back(1);
            } else {
                ret.push_back(0);
            }
            for (int j = 0; j < 9; j++) {
                int x = a + dx[j];
                int y = b + dy[j];
                if (st.count({x, y})) {
                    st.erase({x, y});
                    row[x]--;
                    col[y]--;
                    X1[x + y]--;
                    X2[x - y]--;
                }
            }
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif