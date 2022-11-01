// id:297398517
// runtime:20 ms
// memory:17.4 MB
// title:Valid Sudoku
// translatedTitle:有效的数独
// questionId:36
// time:2022-04-09 19:38:51

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
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &V) {
        for (int i = 0; i < 9; i++) {
            int mask = 0;
            for (int j = 0; j < 9; j++) {
                if (V[i][j] != '.') {
                    int val = V[i][j] - '0';
                    if (mask & (1 << val)) {
                        return false;
                    } else {
                        mask |= 1 << val;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            int mask = 0;
            for (int j = 0; j < 9; j++) {
                if (V[j][i] != '.') {
                    int val = V[j][i] - '0';
                    if (mask & (1 << val)) {
                        return false;
                    } else {
                        mask |= 1 << val;
                    }
                }
            }
        }
        for (int i : {0, 3, 6}) {
            for (int j : {0, 3, 6}) {
                int mask = 0;
                for (int ox = 0; ox < 3; ox++) {
                    for (int oy = 0; oy < 3; oy++) {
                        int x = i + ox;
                        int y = j + oy;
                        if (V[x][y] != '.') {
                            int val = V[x][y] - '0';
                            if (mask & (1 << val)) {
                                return false;
                            } else {
                                mask |= 1 << val;
                            }
                        }
                    }
                }
            }
        }
        return true;
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