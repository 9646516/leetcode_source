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
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */
string bin(int x) {
    string ret;
    while (x) {
        ret.push_back((x & 1) + '0');
        x >>= 1;
    }
    while (ret.size() < 8) {
        ret.push_back('0');
    }

    reverse(ret.begin(), ret.end());
    return ret;
}
class Solution {
  public:
    // int dp[1 << 16][1 << 5];
    // string s;
    // string hand;
    // int reduce(int mask) {
    //     int mask0 = mask;
    //     // cout << "reduce" << endl;
    //     while (1) {
    //         bool extend = false;
    //         vector<int> now;
    //         for (int j = 0; j < s.size(); j++) {
    //             if ((mask >> j) & 1)
    //                 continue;
    //             if (now.empty()) {
    //                 now.push_back(j);
    //             } else {
    //                 if (s[j] == s[now[0]]) {
    //                     now.push_back(j);
    //                 } else {
    //                     if (now.size() >= 3) {
    //                         extend = 1;
    //                         for (int i : now) {
    //                             mask |= 1 << i;
    //                         }
    //                     }
    //                     now.clear();
    //                     now.push_back(j);
    //                 }
    //             }
    //         }
    //         if (now.size() >= 3) {
    //             extend = 1;
    //             for (int i : now) {
    //                 mask |= 1 << i;
    //             }
    //         }
    //         if (!extend) {
    //             break;
    //         }
    //     }
    //     debug(bin(mask0), bin(mask));
    //     return mask;
    // }
    // int dfs(int mask1, int mask2) {
    //     if (__builtin_popcount(mask1) == s.size()) {
    //         return 0;
    //     }
    //     if (dp[mask1][mask2] != -1) {
    //         return dp[mask1][mask2];
    //     } else {
    //         vector<vector<int>> V;
    //         {
    //             vector<int> now;
    //             for (int j = 0; j < s.size(); j++) {
    //                 if ((mask1 >> j) & 1)
    //                     continue;
    //                 if (now.empty()) {
    //                     now.push_back(j);
    //                 } else {
    //                     if (s[j] == s[now[0]]) {
    //                         now.push_back(j);
    //                     } else {
    //                         V.push_back(now);
    //                         now.clear();
    //                         now.push_back(j);
    //                     }
    //                 }
    //             }
    //             if (!now.empty())
    //                 V.push_back(now);
    //         }
    //         map<int, vector<int>> has;
    //         for (int i = 0; i < (int)hand.size(); i++) {
    //             if ((mask2 >> i) & 1)
    //                 continue;
    //             has[hand[i]].push_back(i);
    //         }
    //         int ans = INF;
    //         for (auto &i : V) {
    //             int color = s[i[0]];
    //             if (i.size() == 1) {
    //                 if (has[color].size() >= 2) {
    //                     int mask1_2 = mask1;
    //                     mask1_2 |= 1 << i[0];
    //                     mask1_2 = reduce(mask1_2);
    //                     int mask2_2 = mask2;
    //                     mask2_2 |= 1 << has[color][0];
    //                     mask2_2 |= 1 << has[color][1];
    //                     int F = dfs(mask1_2, mask2_2);
    //                     if (F != -1)
    //                         ans = min(ans, F + 2);
    //                 }
    //             } else {
    //                 if (has[color].size() >= 1) {
    //                     int mask1_2 = mask1;
    //                     mask1_2 |= 1 << i[0];
    //                     mask1_2 |= 1 << i[1];
    //                     mask1_2 = reduce(mask1_2);
    //                     int mask2_2 = mask2;
    //                     mask2_2 |= 1 << has[color][0];
    //                     int F = dfs(mask1_2, mask2_2);
    //                     if (F != -1)
    //                         ans = min(ans, F + 1);
    //                 }
    //             }
    //         }
    //         if (ans == INF)
    //             ans = -1;
    //         return dp[mask1][mask2] = ans;
    //     }
    // };
    string reduce(string s) {
        string q;
        int len = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (q.empty()) {
                q.push_back(s[i]);
                len = 1;
            } else if (s[i] == q.back()) {
                q.push_back(s[i]);
                len++;
            } else {
                if (len >= 3) {
                    while (len--) {
                        q.pop_back();
                    }
                }
                q.push_back(s[i]);
                len = 0;
                for (int j = (int)q.size() - 1; j >= 0; j--) {
                    if (q[j] == q.back())
                        len++;
                    else
                        break;
                }
            }
        }
        if (len >= 3) {
            while (len--) {
                q.pop_back();
            }
        }
        return q;
    }
    int findMinStep(string board, string hand) {
        int ans = -1;
        queue<pair<string, int>> q;
        unordered_map<string, unordered_set<int>> st;
        q.push({board, 0});
        while (!q.empty()) {
            auto [str, mask] = q.front();
            q.pop();
            if (str.empty()) {
                ans = __builtin_popcount(mask);
                break;
            } else {
                vector<int> st2(255);
                for (int i = 0; i < hand.size(); i++) {
                    if ((mask >> i) & 1)
                        continue;
                    int color = hand[i];
                    if (st2[color])
                        continue;
                    st2[color] = 1;
                    int mask2 = mask | 1 << i;
                    for (int j = 0; j < (int)str.size(); j++) {
                        if (j > 0 && str[j - 1] == str[j] && str[j] == color)
                            continue;
                        bool ok = 0;
                        if (str[j] == color) {
                            ok = true;
                        }

                        if (j > 0 && str[j - 1] == str[j] && str[j] != color) {
                            ok = true;
                        }

                        if (ok) {
                            string s2 = str;
                            s2.insert(s2.begin() + j, hand[i]);
                            s2 = reduce(s2);

                            if (st[s2].count(mask2))
                                continue;
                            st[s2].insert(mask2);
                            q.push({s2, mask2});
                        }
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
    vector<int> data{};
    Solution s;
    auto res = s.findMinStep("RRWWRRBBRR", "WB");
    debug(res);
    return 0;
}
#endif
// @lc code=end
