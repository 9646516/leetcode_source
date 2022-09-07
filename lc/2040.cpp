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
 * @lc app=leetcode.cn id=2040 lang=cpp
 *
 * [2040] 两个有序数组的第 K 小乘积
 */

class Solution {
  public:
    long long kthSmallestProduct(const vector<int> &a, const vector<int> &b, long long k) {
#if 0
        auto get_greater = [&](ll val) {
            ll ret = 0;
            for (int i = 0; i < (int)a.size(); i++) {
                if (a[i] == 0) {
                    if (val < 0) {
                        ret += b.size();
                    }
                } else if (a[i] > 0) {
                    ll part = val / a[i];
                    while (part * a[i] <= val)
                        part++;
                    if (part <= b.back()) {
                        int pos = lower_bound(b.begin(), b.end(), part) - b.begin();
                        ret += ((ll)b.size() - 1) - pos + 1;
                    }
                } else {
                    ll part = val / a[i];
                    while (part * a[i] <= val)
                        part--;
                    if (part >= b.front()) {
                        int pos = upper_bound(b.begin(), b.end(), part) - b.begin() - 1 - 0 + 1;
                        ret += pos;
                    }
                }
            }
            return ret;
        };
        ll L = -1e10, R = 1e10, ans = -1e10;
        const ll k2 = (ll)a.size() * (ll)b.size() - k;
        while (L <= R) {
            ll mid = (L + R) / 2;
            if (get_greater(mid) <= k2) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        return ans;
#else
        auto get_less = [&](ll val) {
            ll ret = 0;
            for (int i = 0; i < (int)a.size(); i++) {
                if (a[i] == 0) {
                    if (val > 0) {
                        ret += b.size();
                    }
                } else if (a[i] > 0) {
                    ll part = val / a[i] + 1;
                    while (part * a[i] >= val)
                        part--;
                    if (part >= b.front()) {
                        int pos = upper_bound(b.begin(), b.end(), part) - b.begin();
                        ret += pos - 1 - 0 + 1;
                    }
                } else {
                    ll part = val / a[i] - 1;
                    while (part * a[i] >= val)
                        part++;
                    if (part <= b.back()) {
                        int pos = lower_bound(b.begin(), b.end(), part) - b.begin();
                        ret += (b.size() - 1) - (pos) + 1;
                    }
                }
            }
            return ret;
        };
        ll L = -1e10, R = 1e10, ans = -1e10;
        while (L <= R) {
            ll mid = (L + R) / 2;
            if (get_less(mid) <= k - 1) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        return ans;
#endif
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{2};
    vector<int> b{2, 3};
    Solution s;
    auto res = s.kthSmallestProduct(a, b, 2);
    debug(res);
    return 0;
}
#endif
// @lc code=end
