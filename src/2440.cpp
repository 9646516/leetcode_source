// id:373339457
// runtime:348 ms
// memory:121.9 MB
// title:Create Components With Same Value
// translatedTitle:创建价值相同的连通块
// questionId:2531
// time:2022-10-15 22:49:31

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
class Solution {
  public:
    vector<int> V[20000 + 555];
    int dp[20000 + 555];
    int cnt[20000 + 555];
    int left[20000 + 555];
    int target;
    int N;
    vector<int> G;
    void dfs(int x, int fa) {
        cnt[x] = G[x];
        for (int i : V[x]) {
            if (i != fa) {
                dfs(i, x);
                cnt[x] += cnt[i];
            }
        }
    }
    void dfs2(int x, int fa) {
        if (cnt[x] == target) {
            left[x] = 0;
        } else if (cnt[x] < target) {
            left[x] = cnt[x];
        } else {
            left[x] = G[x];
            for (int i : V[x]) {
                if (i != fa) {
                    dfs2(i, x);
                    left[x] += left[i];
                }
            }
            if (left[x] == target)
                left[x] = 0;
        }
    }
    bool solve(int xs) {
        target = xs;
        for (int i = 0; i <= N; i++)
            dp[i] = 0;
        dfs2(0, -1);
        return left[0] == 0;
    }
    int componentValue(vector<int> &nums, vector<vector<int>> &edges) {
        G = nums;
        N = G.size();
        for (auto &i : edges) {
            int a = i[0];
            int b = i[1];
            V[a].push_back(b);
            V[b].push_back(a);
        }
        dfs(0, -1);
        ll xs = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 1; i < xs; i++) {
            if (xs % i == 0) {
                if (solve(i)) {
                    ans = (xs / i) - 1;
                    break;
                }
            }
        }
        return ans;
    }
};
#ifdef RINNE
int32_t main() {
    // freopen("x", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{{0,1},{1,2},{1,3},{3,4}};
    vector<int> v{6,2,2,2,6};
    string sb;
    Solution *s = new Solution();
    auto res = s->componentValue(v,a);
    debug(res);
    delete s;
    // const int NN = 1e6;
    // int ans = 0;
    // for (int i = 1; i <= NN; i++) {
    //     if (NN % i == 0)
    //         ans++;
    // }
    // cout << ans << endl;
    return 0;
}
#endif