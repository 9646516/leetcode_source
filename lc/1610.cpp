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
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] 可见点的最大数目
 */

class Solution {
  public:
    int X(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first * b.second - a.second * b.first;
    }
    int D(const pair<int, int> &a, const pair<int, int> &b) {
        return a.first * b.first + a.second * b.second;
    }
    double S(const pair<int, int> &a) { return sqrt(a.first * a.first + a.second * a.second); }
    int visiblePoints(vector<vector<int>> &points, int angle, vector<int> &location) {
        vector<pair<int, int>> V;
        int res = 0;
        for (auto &i : points) {
            int a = i[0] - location[0];
            int b = i[1] - location[1];
            if (a == 0 && b == 0)
                res++;
            else
                V.push_back({a, b});
        }
        sort(V.begin(), V.end(), [&](pair<int, int> &a, pair<int, int> &b) {
            return atan2(a.second, a.first) < atan2(b.second, b.first);
        });
        debug(V);
        const int N = V.size();
        for (int i = 0; i < N; i++) {
            V.push_back(V[i]);
        }
        int R = 0;
        int ans = 0;
        for (int i = 0; i < (int)V.size(); i++) {
            while (R < (int)V.size()) {
                double sin = X(V[i], V[R]) / S(V[i]) / S(V[R]);
                double cos = D(V[i], V[R]) / S(V[i]) / S(V[R]);
                double res;
                if (cos > 0.999999999) {
                    res = 0;
                } else {
                    res = acos(cos);
                    if (sin < 0) {
                        res = M_PI * 2 - res;
                    }
                }
                res = res * 360 / 2 / M_PI;
                debug(i, R, cos, sin, res);
                if (res > angle)
                    break;
                else {
                    R++;
                }
            }
            ans = max(ans, min(R - i, N));
        }

        return ans + res;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> data{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {1, 2}, {2, 1}};
    Solution s;
    vector<int> a{1, 1};
    auto res = s.visiblePoints(data, 0, a);
    debug(res);
    return 0;
}
#endif
// @lc code=end
