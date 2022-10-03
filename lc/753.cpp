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
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */
int dp[5000][5000];
class Solution {
  public:
    int n, k;
    int H(const vector<int> &V) {
        int ret = 0;
        for (int i : V) {
            ret = ret * k + i;
        }
        return ret;
    }
    string split(int val) {
        string ret;
        for (int i = 0; i < n; i++) {
            ret.push_back((val % k) + '0');
            val /= k;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    vector<int> V;
    int end[5000];
    vector<int> start[10];
    vector<int> G[5000];
    void dfs(int pos) {
        if (pos == n) {
            int h = H(V);
            end[h] = V.back();
            start[V[0]].push_back(h);
        } else {
            for (int i = 0; i < k; i++) {
                V[pos] = i;
                dfs(pos + 1);
            }
        }
    }
    string crackSafe(int n, int k) {
        if (n == 1) {
            string res;
            for (int i = 0; i < k; i++)
                res.push_back('0' + i);
            return res;
        }
        int mx = 1;
        for (int i = 0; i < n; i++)
            mx *= k;
        V.resize(n);
        this->n = n;
        this->k = k;
        for (int i = 0; i < mx; i++) {
            for (int j : start[end[i]]) {
                if (i != j)
                    G[i].push_back(j);
            }
        }
        dfs(0);
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
