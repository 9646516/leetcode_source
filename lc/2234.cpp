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
 * @lc app=leetcode.cn id=2234 lang=cpp
 *
 * [2234] 花园的最大总美丽值
 */

class Solution {
  public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full,
                            int partial) {
        vector<ll> V;
        ll has = 0;
        for (int i : flowers) {
            if (i >= target)
                has++;
            else
                V.push_back(i);
        }
        sort(V.begin(), V.end());
        vector<ll> H = V;
        for (int i = 1; i < H.size(); i++)
            H[i] += H[i - 1];
        ll res = 0;
        for (int i = 0; i <= (int)V.size(); i++) {
            ll xs = 0;
            ll new_has = has + i;
            int S = V.size() - i;
            int R = S - 1;
            if (i) {
                xs += H[V.size() - 1];
                if (S - 1 >= 0)
                    xs -= H[S - 1];
            }
            ll need = 1LL * i * target - xs;
            if (need > newFlowers)
                break;
            if (R == -1) {
                res = max(res, new_has * full);
            } else {
                ll left = newFlowers - need;
                int l = 0, r = R, ans = 0;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    ll need = V[mid] * (mid + 1) - H[mid];
                    if (need <= left) {
                        ans = mid;
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }
                }
                ll left2 = left - (V[ans] * (ans + 1) - H[ans]);
                ll minn = left2 / (ans + 1) + V[ans];
                if (minn >= target)
                    minn = target - 1;
                res = max(res, new_has * full + minn * partial);
            }
        }
        return res;
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
