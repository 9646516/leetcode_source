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
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

class Solution {
  public:
    vector<int> V;
    void add(int val) {
        V.push_back(val - 1);
        V.push_back(val);
        V.push_back(val + 1);
    }
    int has[3000 * 6];
    int intersectionSizeTwo(vector<vector<int>> &intervals) {
        memset(has, 0, sizeof(has));
        for (auto &i : intervals) {
            add(i[0]);
            add(i[1]);
        }
        sort(V.begin(), V.end());
        V.erase(unique(V.begin(), V.end()), V.end());
        for (auto &i : intervals) {
            i[0] = lower_bound(V.begin(), V.end(), i[0]) - V.begin();
            i[1] = lower_bound(V.begin(), V.end(), i[1]) - V.begin();
        }
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        reverse(intervals.begin(), intervals.end());
        for (auto &i : intervals) {
            int a = i[0], b = i[1];
            int cnt = 0;
            for (int i = a; i <= b; i++) {
                cnt += has[i];
                if (cnt >= 2)
                    break;
            }
            int need = 2 - cnt;
            for (int i = a; i <= b && need > 0; i++) {
                if (!has[i]) {
                    has[i] = 1;
                    ans++;
                    need--;
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
