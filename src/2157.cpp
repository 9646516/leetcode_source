// id:355537402
// runtime:1612 ms
// memory:78 MB
// title:Groups of Strings
// translatedTitle:字符串分组
// questionId:2276
// time:2022-08-27 15:16:52

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
 * @lc app=leetcode.cn id=2157 lang=cpp
 *
 * [2157] 字符串分组
 */
class Solution {
  public:
    vector<int> groupStrings(vector<string> &words) {
        unordered_map<int, int> fa, sz;
        function<int(int)> seek = [&](int x) -> int {
            return fa[x] == x ? x : fa[x] = seek(fa[x]);
        };

        set<int> P;
        for (auto &i : words) {
            int m = 0;
            for (auto j : i) {
                m |= 1 << (j - 'a');
            }
            P.insert(m);
            fa[m] = m;
            sz[m] += 1;
        }
        for (int i : P) {
            for (int j = 0; j < 26; j++) {
                int m = i ^ (1 << j);
                if (P.count(m)) {
                    int f1 = seek(i);
                    int f2 = seek(m);
                    if (f1 != f2) {
                        fa[f2] = f1;
                        sz[f1] += sz[f2];
                    }
                }
            }
            for (int j = 0; j < 26; j++) {
                if ((i >> j) & 1) {
                    for (int k = 0; k < 26; k++) {
                        if (!((i >> k) & 1)) {
                            int m = i ^ (1 << j) ^ (1 << k);
                            if (P.count(m)) {
                                int f1 = seek(i);
                                int f2 = seek(m);
                                if (f1 != f2) {
                                    fa[f2] = f1;
                                    sz[f1] += sz[f2];
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<int> cls;
        int mx = 0;
        for (int i : P) {
            int f = seek(i);
            mx = max(mx, sz[f]);
            cls.push_back(f);
        }
        sort(cls.begin(), cls.end());
        cls.resize(unique(cls.begin(), cls.end()) - cls.begin());
        return {(int)cls.size(), mx};
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