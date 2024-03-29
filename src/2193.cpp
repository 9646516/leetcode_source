// id:354910528
// runtime:60 ms
// memory:7.6 MB
// title:Minimum Number of Moves to Make Palindrome
// translatedTitle:得到回文串的最少操作次数
// questionId:1356
// time:2022-08-25 20:58:36

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
 * @lc app=leetcode.cn id=2193 lang=cpp
 *
 * [2193] 得到回文串的最少操作次数
 */

class Solution {
  public:
    int minMovesToMakePalindrome(string s) {
        vector<int> cnt(255, 0);
        for (auto i : s)
            cnt[i]++;
        char mid = '#';
        for (int i = 'a'; i <= 'z'; i++) {
            if (cnt[i] & 1) {
                mid = i;
                break;
            }
        }
        for (int i = 'a'; i <= 'z'; i++) {
            cnt[i] /= 2;
        }
        string sb;
        for (char i : s) {
            if (cnt[i] > 0) {
                cnt[i]--;
                sb.push_back(i);
            }
        }
        string bs = sb;
        reverse(bs.begin(), bs.end());
        stringstream full;
        if (mid != '#') {
            full << sb << mid << bs;
        } else {
            full << sb << bs;
        }
        string inv = full.str();
        int ans = 0;
        for (auto i = 0; i < (int)inv.size(); i++) {
            for (int j = i; j < (int)s.size(); j++) {
                if (s[j] == inv[i]) {
                    s.erase(s.begin() + j);
                    s.insert(s.begin() + i, inv[i]);
                    ans += abs(i - j);
                    break;
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
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif