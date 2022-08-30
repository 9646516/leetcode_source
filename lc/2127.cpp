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
 * @lc app=leetcode.cn id=2127 lang=cpp
 *
 * [2127] 参加会议的最多员工数
 */

class Solution {
  public:
    int fa[100000 + 555];
    int cnt[100000 + 555];
    vector<int> inv[100000 + 555];
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    int dfs(int x, int fa) {
        int ret = 0;
        for (int i : inv[x]) {
            if (i != fa && cnt[i] <= 0) {
                ret = max(ret, dfs(i, x));
            }
        }
        return ret + 1;
    }
    int maximumInvitations(vector<int> &V) {
        int sum2 = 0;
        const int n = V.size();
        for (int i = 0; i < n; i++) {
            fa[i] = i;
            inv[V[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int fa1 = seek(i);
            int fa2 = seek(V[i]);
            fa[fa1] = fa2;
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int fa = seek(i);
            mp[fa].push_back(i);
        }
        int ans = 0;
        queue<int> q;
        debug(mp);
        for (auto &[fa, V2] : mp) {
            debug(V2);
            int inq = 0;
            for (int i : V2) {
                cnt[i] = 0;
            }
            for (int i : V2) {
                cnt[V[i]]++;
            }
            for (int i : V2) {
                if (cnt[i] == 0)
                    q.push(i);
            }
            while (!q.empty()) {
                int now = q.front();
                q.pop();
                inq++;
                cnt[V[now]]--;
                if (cnt[V[now]] == 0)
                    q.push(V[now]);
            }
            int circle = (int)V2.size() - inq;
            if (circle == 2) {
                for (int i : V2) {
                    if (cnt[i] > 0) {
                        circle += dfs(i, -1) - 1;
                        // cout << i << ' ' << dfs(i, -1) << endl;
                    }
                }
                sum2 += circle;
            } else {
                ans = max(ans, circle);
            }
        }
        ans = max(ans, sum2);

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
    vector<int> data{1, 0, 3, 2, 5, 6, 7, 4, 9, 8, 11, 10, 11, 12, 10};
    Solution s;
    auto res = s.maximumInvitations(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
