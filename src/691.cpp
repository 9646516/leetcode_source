// id:372003476
// runtime:1596 ms
// memory:205.6 MB
// title:Stickers to Spell Word
// translatedTitle:贴纸拼词
// questionId:691
// time:2022-10-11 18:05:03

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
 * @lc app=leetcode.cn id=691 lang=cpp
 *
 * [691] 贴纸拼词
 */
struct node {
    inline static int SZ;
    inline static int need[26];
    static void set_symbols(const string &X) {
        memset(need, -1, sizeof(need));
        auto cp = X;
        sort(cp.begin(), cp.end());
        cp.erase(unique(cp.begin(), cp.end()), cp.end());
        SZ = cp.size();
        for (int i = 0; i < cp.size(); i++) {
            need[cp[i] - 'a'] = i;
        }
    }
    vector<int> V;
    node() { V.resize(SZ); };
    node(const string &X) {
        V.resize(SZ);
        for (auto i : X) {
            int idx = need[i - 'a'];
            if (idx != -1)
                V[idx]++;
        }
    };
    bool any() {
        for (int i = 0; i < SZ; i++) {
            if (V[i])
                return 1;
        }
        return 0;
    }
    node(vector<int> &&X) : V(X){};
    void set_min(const node &a) {
        for (int i = 0; i < SZ; i++) {
            V[i] = min(V[i], a.V[i]);
        }
    }
    friend bool operator<(const node &a, const node &b) { return a.V < b.V; }
    friend bool operator==(const node &a, const node &b) { return a.V == b.V; }
    friend node operator+(const node &a, const node &b) {
        vector<int> V;
        V.reserve(SZ);
        for (int i = 0; i < SZ; i++) {
            V.push_back(a.V[i] + b.V[i]);
        }
        return node(move(V));
    }
};
class Solution {
  public:
    int minStickers(vector<string> &stickers, string target) {
        node::set_symbols(target);
        node to{target};
        vector<node> V;
        for (auto &i : stickers) {
            node cur{i};
            if (cur.any()) {
                V.push_back(cur);
            }
        }
        map<node, int> mp;
        mp[node()] = 0;
        queue<pair<int, node>> q;
        q.push({0, node()});
        while (!q.empty()) {
            auto [d, now] = q.front();
            if (now == to) {
                break;
            }
            q.pop();
            // if (mp[now] < d)
            //     continue;
            for (auto &i : V) {
                node next = now + i;
                next.set_min(to);
                if (!mp.count(next)) {
                    mp[next] = d + 1;
                    q.emplace(d + 1, move(next));
                } else if (mp[next] > d + 1) {
                    mp[next] = d + 1;
                    q.emplace(d + 1, move(next));
                }
            }
        }
        if (!mp.count(to))
            return -1;
        else
            return mp[to];
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