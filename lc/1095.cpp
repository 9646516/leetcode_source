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
 * @lc app=leetcode.cn id=1095 lang=cpp
 *
 * [1095] 山脉数组中查找目标值
 */

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
#ifdef RINNE
class MountainArray {
  public:
    int get(int index);
    int length();
};
#endif

class Solution {
  public:
    int findInMountainArray(int target, MountainArray &q) {
        unordered_map<int, int> mp;
        auto get = [&](int val) {
            if (mp.count(val))
                return mp[val];
            else
                return mp[val] = q.get(val);
        };
        int L = 0, R = q.length() - 1;
        while (L + 4 <= R) {
            int rmid = (L + R) / 2;
            int lmid = (rmid + L) / 2;
            if (get(lmid) < get(rmid)) {
                L = lmid;
            } else {
                R = rmid;
            }
        }
        int pos = L, val = get(L);
        for (int i = L + 1; i <= R; i++) {
            if (get(i) > val) {
                val = get(i);
                pos = i;
            }
        }
        {
            int L = 0, R = pos, ans = -1;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (get(mid) >= target) {
                    ans = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            if (ans != -1 && q.get(ans) == target)
                return ans;
        }
        {
            int L = pos, R = q.length() - 1, ans = -1;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (get(mid) <= target) {
                    ans = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            if (ans != -1 && q.get(ans) == target)
                return ans;
        }
        return -1;
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
