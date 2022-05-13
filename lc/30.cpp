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
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

class Solution {
  public:
    vector<int> findSubstring(const string &s, vector<string> &words) {
        unordered_map<uint64_t, int> mp0;
        const int len_single = words.front().size();
        const int len = len_single * words.size();
        uint64_t P = 1;
        for (int i = 0; i < len_single; i++) {
            P *= 233;
        }
        vector<int> ret;
        for (const auto &i : words) {
            uint64_t HH = 0;
            for (int j = 0; j < len_single; j++) {
                HH = HH * 233 + i[j];
            }
            mp0[HH]++;
        }
        vector<uint64_t> H2;
        H2.reserve(s.size());
        H2[0] = s[0];
        for (int i = 1; i < (int)s.size(); i++) {
            H2[i] = H2[i - 1] * 233 + s[i];
        }
        unordered_map<uint64_t, int> mp;
        auto match = [&](int L, int R) -> bool {
            mp.clear();
            for (int i = L; i <= R; i += len_single) {
                auto now = H2[i + len_single - 1];
                if (i) {
                    now -= H2[i - 1] * P;
                }
                mp[now]++;
            }
            for (const auto &[a, b] : mp) {
                if (mp0.count(a) && mp0.at(a) == b) {
                    continue;
                } else {
                    return false;
                }
            }
            return true;
        };
        for (int i = 0; i < (int)s.size(); i++) {
            int R = i + len - 1;
            if (R >= s.size())
                break;
            if (match(i, R)) {
                ret.push_back(i);
            }
        }
        return ret;
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
