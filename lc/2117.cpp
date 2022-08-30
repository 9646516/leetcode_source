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
 * @lc app=leetcode.cn id=2117 lang=cpp
 *
 * [2117] 一个区间内所有数乘积的缩写
 */

class Solution {
  public:
    string abbreviateProduct(int left, int right) {

        int s2 = 0, s5 = 0, s10 = 0;
        for (int i = left; i <= right; i++) {
            int now = i;
            while (now % 10 == 0) {
                now /= 10;
                s10++;
            }
            while (now % 2 == 0) {
                now /= 2;
                s2++;
            }
            while (now % 5 == 0) {
                now /= 5;
                s5++;
            }
        }
        int C = s10 + min(s2, s5);
        long double lg_sum = 0;
        int used_10 = s10, used_2 = min(s2, s5), used_5 = min(s2, s5);
        for (int i = left; i <= right; i++) {
            int now = i;
            while (now % 10 == 0 && used_10) {
                now /= 10;
                used_10--;
            }
            while (now % 2 == 0 && used_2) {
                now /= 2;
                used_2--;
            }
            while (now % 5 == 0 && used_5) {
                now /= 5;
                used_5--;
            }
            lg_sum += log10(now);
        }
        if (lg_sum > log10(99999'99999)) {
            ll S = 1;
            int used_10 = s10, used_2 = min(s2, s5), used_5 = min(s2, s5);
            for (int i = left; i <= right; i++) {
                int now = i;
                while (now % 10 == 0 && used_10) {
                    now /= 10;
                    used_10--;
                }
                while (now % 2 == 0 && used_2) {
                    now /= 2;
                    used_2--;
                }
                while (now % 5 == 0 && used_5) {
                    now /= 5;
                    used_5--;
                }
                S = S * now % 100000;
            }
            string SS = to_string(S);
            while (SS.size() != 5) {
                SS.insert(SS.begin(), '0');
            }
            lg_sum = lg_sum + 4 - int(lg_sum);
            long double P = pow(10.0, lg_sum);
            string PS = to_string(int(P));
            stringstream ss;

            ss << PS << "..." << SS << "e" << C;
            return ss.str();
        } else {
            int used_10 = s10, used_2 = min(s2, s5), used_5 = min(s2, s5);
            ll P = 1;
            for (int i = left; i <= right; i++) {
                int now = i;
                while (now % 10 == 0 && used_10) {
                    now /= 10;
                    used_10--;
                }
                while (now % 2 == 0 && used_2) {
                    now /= 2;
                    used_2--;
                }
                while (now % 5 == 0 && used_5) {
                    now /= 5;
                    used_5--;
                }
                P *= now;
            }
            string PS = to_string(P).substr(0, 5);
            stringstream ss;
            ss << P << "e" << C;
            return ss.str();
        }
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
// @lc code=end
