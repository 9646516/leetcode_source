// id:87071147
// runtime:568 ms
// memory:7.7 MB
// title:Best Position for a Service Centre
// translatedTitle:服务中心的最佳位置
// questionId:1638
// time:2020-07-12 15:16:26

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string &s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
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
using ll = long long;
const int INF = 0x3F3F3F3F;
const int maxn = 2e5 + 555;
const int MOD = 1e9 + 7;
const long double EPS = 1e-8;
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double getMinDistSum(vector<vector<int>> &positions) {
        function<double(double, double)> gao2 = [&](double x, double y) -> double {
            double ret = 0;
            for (const auto &i : positions) {
                ret += sqrt((x - i[0]) * (x - i[0]) + (y - i[1]) * (y - i[1]));
            }
            return ret;
        };
        function<double(double)> gao = [&](double pos) -> double {
            double L = 0, R = 100;
            while (L + EPS <= R) {
                double lmid = L + (R - L) / 3;
                double rmid = R - (R - L) / 3;
                double lans = gao2(pos, lmid);
                double rans = gao2(pos, rmid);
                if (lans > rans) {
                    L = lmid;
                } else {
                    R = rmid;
                }
            }
            return gao2(pos, L);
        };
        double L = 0, R = 100;
        while (L + EPS <= R) {
            double lmid = L + (R - L) / 3;
            double rmid = R - (R - L) / 3;
            double lans = gao(lmid);
            double rans = gao(rmid);
            if (lans > rans) {
                L = lmid;
            } else {
                R = rmid;
            }
        }
        return gao(L);
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    auto a = Solution();
    auto s = vector<vector<int>>{{96, 97}, {46, 17}, {95, 97}, {96, 95}, {97, 95}, {55, 56}, {98, 96}, {50, 44}, {37, 72}, {38, 21}, {96, 96}, {96, 97}, {47, 62}, {97, 97}, {46, 51},
                                 {98, 97}, {42, 25}, {65, 62}, {18, 71}, {94, 95}, {48, 44}, {96, 95}, {97, 97}, {33, 54}, {22, 37}, {95, 96}, {34, 47}, {94, 98}, {95, 97}, {43, 20}};
    // 1142.15589
    // auto s = vector<vector<int>>{{44, 23}, {18, 45}, {6, 73}, {0, 76}, {10, 50}, {30, 7}, {92, 59}, {44, 59}, {79, 45}, {69, 37}, {66, 63}, {10, 78}, {88, 80}, {44, 87}};
    // 499.28078
    cout << a.getMinDistSum(s);
    return 0;
}
#endif