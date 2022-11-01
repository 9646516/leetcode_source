// id:368193466
// runtime:48 ms
// memory:12.1 MB
// title:Stamping The Sequence
// translatedTitle:戳印序列
// questionId:973
// time:2022-09-28 18:52:38

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
 * @lc app=leetcode.cn id=936 lang=cpp
 *
 * [936] 戳印序列
 */
int need[1005][1005];
int cnt[1005];
int B[1005];
class Solution {
  public:
    vector<int> movesToStamp(string stamp, string s) {
        memset(need, 0, sizeof(need));
        memset(cnt, 0, sizeof(cnt));
        const int sz = stamp.size();
        const int sz2 = s.size() - sz + 1;

        for (int i = 0; i < s.size(); i++) {
            B[i] = 1;
        }
        for (int i = 0; i < sz2; i++) {
            for (int j = 0; j < sz; j++) {
                if (s[i + j] != stamp[j]) {
                    need[i][i + j] = 1;
                    cnt[i]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < sz2; i++) {
            if (s.substr(i, sz) == stamp) {
                q.push(i);
            }
        }
        vector<int> res;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            res.push_back(now);
            for (int i = 0; i < sz; i++) {
                if (B[i + now] == 1) {
                    B[i + now] = 0;
                    int l = max(0, i + now - sz + 1);
                    for (int j = l; j <= i + now; j++) {
                        if (need[j][i + now]) {
                            cnt[j]--;
                            if (cnt[j] == 0) {
                                q.push(j);
                            }
                        }
                    }
                }
            }
        }
        if (res.size() == sz2) {
            reverse(res.begin(), res.end());
            return res;
        } else
            return {};
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