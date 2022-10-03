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
 * @lc app=leetcode.cn id=1453 lang=cpp
 *
 * [1453] 圆形靶内的最大飞镖数量
 */

class Solution {
  public:
    int numPoints(vector<vector<int>> &darts, int r) {
        int ans = 1;
        auto calc = [&](double x, double y) {
            debug(x, y);
            int now = 0;
            for (auto i : darts) {
                double o1 = i[0] - x;
                double o2 = i[1] - y;
                double o = o1 * o1 + o2 * o2;
                debug(i[0], i[1], o);
                if (o <= r * r + 1e-8)
                    now++;
            }
            ans = max(ans, now);
        };
        for (int i = 0; i < (int)darts.size(); i++) {
            int x1 = darts[i][0];
            int y1 = darts[i][1];
            for (int j = i + 1; j < (int)darts.size(); j++) {
                int x2 = darts[j][0];
                int y2 = darts[j][1];
                ll o1 = x2 - x1;
                ll o2 = y2 - y1;
                if (o1 * o1 + o2 * o2 > 4LL * r * r) {
                    continue;
                }

                double d = sqrt(o1 * o1 + o2 * o2);
                double d2 = sqrt(r * r - d * d / 4.0);

                double ox = o1 / d;
                double oy = o2 / d;

                double x = (x1 + x2) / 2.0;
                double y = (y1 + y2) / 2.0;
                for (auto [ox2, oy2] : vector<pair<double, double>>{{oy, -ox}, {-oy, ox}}) {
                    double xs = x + ox2 * d2;
                    double ys = y + oy2 * d2;
                    calc(xs, ys);
                }
            }
        }
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
    vector<vector<int>> data{{4, 5}, {-4, 1}, {-3, 2}, {-4, 0}, {0, 2}};
    Solution s;
    auto res = s.numPoints(data, 5);
    debug(res);
    return 0;
}
#endif
// @lc code=end
