// id:102992008
// runtime:268 ms
// memory:57.4 MB
// title:Maximum Length of Subarray With Positive Product
// translatedTitle:乘积为正数的最长子数组长度
// questionId:1690
// time:2020-08-30 11:11:22

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
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
#define debug(...) 114514
#endif
using ll = long long;
const int MOD = 1e9 + 7;
class Solution {
  public:
    int getMaxLen(vector<int> &V) {
        vector<int> s;
        s.push_back(-1);
        for (int i = 0; i < (int)V.size(); i++) {
            if (V[i] == 0) {
                s.push_back(i);
            }
        }
        s.push_back(V.size());
        debug(s);
        int ans = 0;
        auto gao = [&](int L, int R) {
            debug(L, R);
            int sum = 0;
            for (int i = L; i <= R; i++) {
                sum += V[i] < 0;
            }
            if (sum & 1) {
                int ret = 0;
                for (int i = L; i <= R; i++) {
                    if (V[i] < 0) {
                        ret = max(ret, R - i);
                        break;
                    }
                }
                for (int i = R; i >= L; i--) {
                    if (V[i] < 0) {
                        ret = max(ret, i - L);
                        break;
                    }
                }
                return ret;
            } else {
                return R - L + 1;
            }
        };
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            int L = s[i] + 1, R = s[i + 1] - 1;
            if (L <= R)
                ans = max(ans, gao(L, R));
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
    vector<int> a{-1, -2, -3, 0, 1};
    Solution s;
    auto res = s.getMaxLen(a);
    debug(res);
    return 0;
}
#endif