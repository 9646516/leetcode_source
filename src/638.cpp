// id:353565699
// runtime:152 ms
// memory:41.2 MB
// title:Shopping Offers
// translatedTitle:大礼包
// questionId:638
// time:2022-08-22 19:21:06

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
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

class Solution {
  public:
    vector<int> split(int mask) {
        vector<int> ret;
        for (int i = 0; i < 6; i++) {
            ret.push_back(mask % 11);
            mask /= 11;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    bool check(int mask, int mask2, const vector<int> &needs) {
        auto s = split(mask);
        auto s2 = split(mask2);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] + s2[i] > needs[i])
                return 0;
        }
        return 1;
    }
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        const int N = price.size();
        for (int i = N; i < 6; i++) {
            price.push_back(0);
            needs.push_back(0);
        }
        vector<pair<int, int>> box; // mask cost
        for (auto &i : special) {
            int mask = 0;
            for (int j = 0; j < N; j++) {
                mask = mask * 11 + i[j];
            }
            for (int j = N; j < 6; j++) {
                mask = mask * 11 + 0;
            }
            box.push_back({mask, i.back()});
        }
        static int dp[11 * 11 * 11 * 11 * 11 * 11];
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        set<pair<int, int>> st;
        st.insert({0, 0});
        int ans = INF;
        while (!st.empty()) {
            auto [cost, mask] = *st.begin();
            st.erase(st.begin());
            {
                auto s = split(mask);
                int now = cost;
                for (int i = 0; i < s.size(); i++) {
                    int o = (needs[i] - s[i]);
                    now += price[i] * o;
                }
                ans = min(ans, now);
            }
            for (auto &[mask2, cost2] : box) {
                if (check(mask, mask2, needs)) {
                    int new_mask = mask + mask2;
                    int new_cost = cost + cost2;
                    if (dp[new_mask] > new_cost) {
                        st.erase({dp[new_mask], new_mask});
                        dp[new_mask] = new_cost;
                        st.insert({dp[new_mask], new_mask});
                    }
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
    vector<int> a{9, 9};
    vector<vector<int>> b{{1, 1, 1}};
    vector<int> c{6, 6};
    Solution s;
    auto res = s.shoppingOffers(a, b, c);
    debug(res);
    return 0;
}
#endif