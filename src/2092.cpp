// id:356967816
// runtime:668 ms
// memory:238.8 MB
// title:Find All People With Secret
// translatedTitle:找出知晓秘密的所有专家
// questionId:2213
// time:2022-08-30 23:34:07

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
 * @lc app=leetcode.cn id=2092 lang=cpp
 *
 * [2092] 找出知晓秘密的所有专家
 */
template <int N> struct DSU {
    int fa[N], dep[N];
    void init() {
        iota(fa, fa + N, 0);
        fill(dep, dep + N, 1);
    }
    int seek(int x) { return fa[x] == x ? x : fa[x] = seek(fa[x]); }
    bool merge(int a, int b) {
        int f1 = seek(a), f2 = seek(b);
        if (f1 != f2) {
            if (dep[f1] < dep[f2]) {
                fa[f1] = f2;
            } else if (dep[f1] > dep[f2]) {
                fa[f2] = f1;
            } else {
                fa[f1] = f2;
                dep[f2]++;
            }
            return true;
        } else {
            return false;
        }
    }
    DSU() { init(); }
};
class Solution {
  public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {

        map<int, vector<pair<int, int>>> mp;
        for (auto &i : meetings) {
            mp[i[2]].push_back({i[0], i[1]});
        }
        auto *dsu = new DSU<100000 + 5>();
        dsu->merge(0, firstPerson);
        for (auto [t, v] : mp) {
            for (auto [a, b] : v) {
                dsu->merge(a, b);
            }
            set<int> bad;
            for (auto [a, b] : v) {
                if (dsu->seek(a) != dsu->seek(0)) {
                    bad.insert(a);
                    bad.insert(b);
                }
            }
            for (int i : bad)
                dsu->fa[i] = i;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++)
            if (dsu->seek(i) == dsu->seek(0))
                ret.push_back(i);
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