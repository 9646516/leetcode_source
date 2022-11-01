// id:357716687
// runtime:440 ms
// memory:60 MB
// title:Check if an Original String Exists Given Two Encoded Strings
// translatedTitle:同源字符串检测
// questionId:2184
// time:2022-09-01 17:36:45

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
 * @lc app=leetcode.cn id=2060 lang=cpp
 *
 * [2060] 同源字符串检测
 */
int dp[55][55][2005];

class Solution {
  public:
    string a, b;
    vector<int> sb;
    vector<int> ret;
    void dfs2(int pos, int sum, int now) {
        if (pos == sb.size()) {
            ret.push_back(sum + now);
        } else {
            dfs2(pos + 1, sum, now * 10 + sb[pos]);
            dfs2(pos + 1, sum + now, sb[pos]);
        }
    }
    vector<int> make_seq(string &x, int l, int r) {
        sb.clear();
        for (int i = l; i <= r; i++)
            sb.push_back(x[i] - '0');
        ret.clear();
        dfs2(0, 0, 0);
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        debug(x, l, r, ret);
        return ret;
    }
    int dfs(int p1, int p2, int aster) {
        if (p1 == a.size() && p2 == b.size()) {
            return aster == 0;
        } else if (dp[p1][p2][aster + 1000] != -1) {
            return dp[p1][p2][aster + 1000];
        } else {
            if (p1 < a.size() && isdigit(a[p1])) {
                int e1 = p1;
                for (int i = p1; i < (int)a.size(); i++) {
                    if (isdigit(a[i])) {
                        e1 = i;
                    } else {
                        break;
                    }
                }
                vector<int> o1 = make_seq(a, p1, e1);
                for (int i : o1) {
                    if (dfs(e1 + 1, p2, aster + i)) {
                        return dp[p1][p2][aster + 1000] = 1;
                    }
                }
                return dp[p1][p2][aster + 1000] = 0;
            } else if (p2 < b.size() && isdigit(b[p2])) {
                int e2 = p2;
                for (int i = p2; i < (int)b.size(); i++) {
                    if (isdigit(b[i])) {
                        e2 = i;
                    } else {
                        break;
                    }
                }
                vector<int> o2 = make_seq(b, p2, e2);
                for (int i : o2) {
                    if (dfs(p1, e2 + 1, aster - i)) {
                        return dp[p1][p2][aster + 1000] = 1;
                    }
                }
                return dp[p1][p2][aster + 1000] = 0;
            } else {
                if (aster > 0) {
                    return dp[p1][p2][aster + 1000] = (p2 < b.size() && dfs(p1, p2 + 1, aster - 1));
                } else if (aster < 0) {
                    return dp[p1][p2][aster + 1000] = (p1 < a.size() && dfs(p1 + 1, p2, aster + 1));
                } else {
                    return dp[p1][p2][aster + 1000] =
                               (p1 < a.size() && p2 < b.size() && a[p1] == b[p2] &&
                                dfs(p1 + 1, p2 + 1, aster));
                }
            }
        }
    }
    bool possiblyEquals(const string &s1, const string &s2) {
        a = s1;
        b = s2;
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0);
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
    auto res = s.possiblyEquals("a7a242a", "a2a14");
    debug(res);
    return 0;
}
#endif