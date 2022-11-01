// id:373345809
// runtime:108 ms
// memory:69.5 MB
// title:Minimize Maximum of Array
// translatedTitle:最小化数组中的最大值
// questionId:2530
// time:2022-10-15 23:02:30

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
    int minimizeArrayValue(vector<int> &nums) {
        int L = 0, R = 1e9, ans = 1e9;
        auto can = [&](int mx) -> bool {
            ll left = 0;
            for (int i : nums) {
                if (i <= mx)
                    left += mx - i;
                else {
                    ll need = i - mx;
                    if (left >= need)
                        left -= need;
                    else
                        return 0;
                }
            }
            return 1;
        };
        while (L <= R) {
            int mid = (L + R) / 2;
            if (can(mid)) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
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
    vector<vector<int>> a{{0, 1}, {1, 2}, {1, 3}, {3, 4}};
    vector<int> v{6, 2, 2, 2, 6};
    string sb;
    Solution *s = new Solution();
    auto res = s->componentValue(v, a);
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