// id:358172301
// runtime:216 ms
// memory:9.5 MB
// title:Longest Subsequence Repeated k Times
// translatedTitle:重复 K 次的最长子序列
// questionId:2140
// time:2022-09-02 18:26:59

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
 * @lc app=leetcode.cn id=2014 lang=cpp
 *
 * [2014] 重复 K 次的最长子序列
 */
int next[2000 * 8 + 5][10];
int suf[2000 * 8 + 5][10];
class Solution {
  public:
    int idx, k;
    string now;
    bool dfs(int x) {
        if (x == 0) {
            int ptr = 0;
            for (int i = 0; i < k; i++) {
                for (int j : now) {
                    if (::suf[ptr][j] + i < k)
                        return 0;
                    ptr = ::next[ptr][j];
                    if (ptr == -1)
                        return 0;
                }
            }
            return 1;
        } else {
            now.push_back('$');
            for (int i = idx - 1; i >= 0; i--) {
                now.back() = i;
                if (dfs(x - 1))
                    return 1;
            }
            now.pop_back();
            return 0;
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        this->k = k;
        idx = 0;
        vector<int> cnt(255, 0);
        for (auto i : s) {
            cnt[i]++;
        }
        vector<int> rank(255), sb(255);
        for (int i = 'a'; i <= 'z'; i++) {
            if (cnt[i] >= k) {
                rank[i] = idx;
                sb[idx] = i;
                idx++;
            }
        }
        string s2 = "$";
        for (auto i : s) {
            if (cnt[i] >= k) {
                s2.push_back(rank[i]);
            }
        }
        for (int i = 0; i < idx; i++) {
            ::next[s2.size() - 1][i] = -1;
            ::suf[s2.size() - 1][i] = 0;
        }
        for (int i = s2.size() - 2; i >= 0; i--) {
            for (int j = 0; j < idx; j++) {
                ::next[i][j] = ::next[i + 1][j];
            }
            ::next[i][s2[i + 1]] = i + 1;
        }
        for (int i = s2.size() - 1; i >= 1; i--) {
            ::suf[i][s2[i]]++;
            for (int j = 0; j < idx; j++) {
                ::suf[i - 1][j] = ::suf[i][j];
            }
        }
        for (int i = min(7, (int)s2.size() / k); i >= 1; i--) {
            if (dfs(i)) {
                for (char &i : now)
                    i = sb[i];
                return now;
            }
        }
        return "";
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
    string ss = "letsleetcode";
    auto res = s.longestSubsequenceRepeatedK(ss, 2);
    debug(res);
    return 0;
}
#endif