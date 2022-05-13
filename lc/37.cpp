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
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

class Solution {
  public:
    void solveSudoku(vector<vector<char>> &board) {
        const int UNSIGNED = 114514;
        array<array<int, 9>, 9> V;
        array<array<int, 9>, 9> index_to_grid;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    V[i][j] = UNSIGNED;
                } else {
                    V[i][j] = board[i][j] - '0';
                }
            }
        }
        for (int i : {0, 3, 6}) {
            for (int j : {0, 3, 6}) {
                for (int ox = 0; ox < 3; ox++) {
                    for (int oy = 0; oy < 3; oy++) {
                        int x = i + ox;
                        int y = j + oy;
                        index_to_grid[x][y] = i + j / 3;
                    }
                }
            }
        }
        array<int, 9> row_mask, col_mask, grid_mask;
        for (int i = 0; i < 9; i++) {
            row_mask[i] = col_mask[i] = grid_mask[i] = 0;
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (V[i][j] != UNSIGNED) {
                    row_mask[i] |= 1 << V[i][j];
                    col_mask[j] |= 1 << V[i][j];
                    grid_mask[index_to_grid[i][j]] |= 1 << V[i][j];
                }
            }
        }
        function<bool(int, int)> dfs = [&](int row, int col) -> bool {
            if (col == 9) {
                col = 0;
                row++;
            }
            if (row == 9) {
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 9; j++) {
                        board[i][j] = V[i][j] + '0';
                    }
                }
                return true;
            } else if (V[row][col] == UNSIGNED) {
                for (int i = 1; i <= 9; i++) {
                    if (row_mask[row] & (1 << i)) {
                        continue;
                    } else if (col_mask[col] & (1 << i)) {
                        continue;
                    } else if (grid_mask[index_to_grid[row][col]] & (1 << i)) {
                        continue;
                    } else {
                        row_mask[row] |= (1 << i);
                        col_mask[col] |= (1 << i);
                        grid_mask[index_to_grid[row][col]] |= (1 << i);
                        V[row][col] = i;
                        if (dfs(row, col + 1))
                            return true;
                        V[row][col] = UNSIGNED;
                        row_mask[row] ^= (1 << i);
                        col_mask[col] ^= (1 << i);
                        grid_mask[index_to_grid[row][col]] ^= (1 << i);
                    }
                }
                return false;
            } else {
                return dfs(row, col + 1);
            }
        };
        static_cast<void>(dfs(0, 0));
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<char>> data{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                              {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                              {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                              {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                              {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                              {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                              {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                              {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                              {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    Solution s;
    s.solveSudoku(data);
    debug(data);
    return 0;
}
#endif
// @lc code=end
