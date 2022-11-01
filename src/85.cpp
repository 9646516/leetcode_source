// id:298398214
// runtime:56 ms
// memory:20.4 MB
// title:Maximal Rectangle
// translatedTitle:最大矩形
// questionId:85
// time:2022-04-11 17:40:47

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
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

class Solution {
  public:
    int calc(const vector<int> &mid, const vector<int> &left, const vector<int> &right) {
        int ans = 0;
        for (int i = 0; i < (int)mid.size(); i++) {
            int left_min = INF, right_min = INF, mid_min = 1;
            for (int j = i; j >= 0 && mid[j]; j--) {
                left_min = min(left_min, left[j]);
                right_min = min(right_min, right[j]);
                ans = max(ans, (left_min + right_min + 1) * (i - j + 1));
            }
        }
        return ans;
    }
    int maximalRectangle(const vector<vector<char>> &V) {
        const int n = V.size();
        const int m = V.front().size();
        function<int(int, int)> gao = [&](int l, int r) -> int {
            if (l > r)
                return 0;
            else if (l == r) {
                int ans = 0;
                int now = 0;
                for (int i = 0; i < n; i++) {
                    if (V[i][l] == '1') {
                        now++;
                    } else {
                        ans = max(ans, now);
                        now = 0;
                    }
                }
                ans = max(ans, now);
                debug(l, r, ans);
                return ans;
            } else {
                int mid = (l + r) / 2;
                int res1 = gao(l, mid - 1);
                int res2 = gao(mid + 1, r);
                vector<int> left_expand, right_expand, mid_expand;
                for (int i = 0; i < n; i++) {
                    if (V[i][mid] == '1') {
                        mid_expand.push_back(1);
                        {
                            int sum = 0;
                            for (int j = mid - 1; j >= l; j--) {
                                if (V[i][j] == '1')
                                    sum++;
                                else
                                    break;
                            }
                            left_expand.push_back(sum);
                        }
                        {
                            int sum = 0;
                            for (int j = mid + 1; j <= r; j++) {
                                if (V[i][j] == '1')
                                    sum++;
                                else
                                    break;
                            }
                            right_expand.push_back(sum);
                        }
                    } else {
                        left_expand.push_back(0);
                        right_expand.push_back(0);
                        mid_expand.push_back(0);
                    }
                }
                int res3 = calc(mid_expand, left_expand, right_expand);
                debug(l, r, res1, res2, res3);
                return max({res1, res2, res3});
            }
        };
        return gao(0, m - 1);
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<char>> data{
        {'0', '0', '0', '1', '0', '1', '1', '1'}, {'0', '1', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '0', '1'}, {'0', '0', '0', '1', '0', '0', '0', '0'},
        {'0', '0', '1', '0', '0', '0', '1', '0'}, {'1', '1', '1', '0', '0', '1', '1', '1'},
        {'1', '0', '0', '1', '1', '0', '0', '1'}, {'0', '1', '0', '0', '1', '1', '0', '0'},
        {'1', '0', '0', '1', '0', '0', '0', '0'}};
    Solution s;
    auto res = s.maximalRectangle(data);
    debug(res);
    return 0;
}
#endif