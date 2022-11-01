// id:370613580
// runtime:748 ms
// memory:29.9 MB
// title:Hello LeetCode!
// translatedTitle:Hello LeetCode!
// questionId:1000484
// time:2022-10-07 15:58:17

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
template <typename base_type, base_type MOD> struct IntMod {
    base_type n;
    IntMod(long long d = 0) { n = (d >= 0 ? d % MOD : (d % MOD + MOD) % MOD); }
    IntMod operator-() const { return build(n == 0 ? 0 : MOD - n); }
    IntMod &operator+=(IntMod a) {
        n = (n >= MOD - a.n ? n - MOD + a.n : n + a.n);
        return *this;
    }
    IntMod &operator-=(IntMod a) {
        n = (n >= a.n) ? n - a.n : n - a.n + MOD;
        return *this;
    }
    IntMod &operator*=(IntMod a) {
        *this = *this * a;
        return *this;
    }
    static IntMod build(base_type n) {
        IntMod r;
        r.n = n;
        return r;
    }
    friend bool operator==(IntMod a, IntMod b) { return a.n == b.n; }
    friend bool operator!=(IntMod a, IntMod b) { return a.n != b.n; }
    friend IntMod operator+(IntMod a, IntMod b) {
        return build(a.n >= MOD - b.n ? a.n - MOD + b.n : a.n + b.n);
    }
    friend IntMod operator-(IntMod a, IntMod b) {
        return build(a.n >= b.n ? a.n - b.n : a.n - b.n + MOD);
    }
    friend IntMod operator*(IntMod a, IntMod b) {
        return build(static_cast<base_type>(static_cast<long long>(a.n) * b.n % MOD));
    }
    friend istream &operator>>(istream &stream, IntMod &a) {
        stream >> a.n;
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const IntMod &a) {
        stream << a.n;
        return stream;
    }
};
using Int = IntMod<int, MOD>;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// c 1
// d 1
// e 4
// h 1
// l 3
// o 2
// t 1
struct node {
    int c, d, e, h, l, o, t;
    node() { clear(); }
    void set() {
        c = 1;
        d = 1;
        e = 4;
        h = 1;
        l = 3;
        o = 2;
        t = 1;
    }
    void clear() {
        c = 0;
        d = 0;
        e = 0;
        h = 0;
        l = 0;
        o = 0;
        t = 0;
    }
    node(int p1, int p2, int p3, int p4, int p5, int p6, int p7) {
        c = p1;
        d = p2;
        e = p3;
        h = p4;
        l = p5;
        o = p6;
        t = p7;
    }
    bool ok() { return c <= 1 && d <= 1 && e <= 4 && h <= 1 && l <= 3 && o <= 2 && t <= 1; }
    void add(char sb) {
        if (sb == 'c')
            c++;
        if (sb == 'd')
            d++;
        if (sb == 'e')
            e++;
        if (sb == 'h')
            h++;
        if (sb == 'l')
            l++;
        if (sb == 'o')
            o++;
        if (sb == 't')
            t++;
    }
    void del(char sb) {
        if (sb == 'c')
            c--;
        if (sb == 'd')
            d--;
        if (sb == 'e')
            e--;
        if (sb == 'h')
            h--;
        if (sb == 'l')
            l--;
        if (sb == 'o')
            o--;
        if (sb == 't')
            t--;
    }
    friend bool operator<(const node &a, const node &b) {
        if (a.c != b.c)
            return a.c < b.c;
        if (a.d != b.d)
            return a.d < b.d;
        if (a.e != b.e)
            return a.e < b.e;
        if (a.h != b.h)
            return a.h < b.h;
        if (a.l != b.l)
            return a.l < b.l;
        if (a.o != b.o)
            return a.o < b.o;
        if (a.t != b.t)
            return a.t < b.t;
        return 0;
    }
    friend node operator+(const node &a, const node &b) {
        return node{a.c + b.c, a.d + b.d, a.e + b.e, a.h + b.h, a.l + b.l, a.o + b.o, a.t + b.t};
    }
    friend ostream &operator<<(ostream &stream, const node &a) {
        stream << a.c << ' ' << a.d << ' ' << a.e << ' ' << a.h << ' ' << a.l << " " << a.o << " "
               << a.t;
        return stream;
    }
};
int need[255];
map<node, int> V;
node now;
void dfs(string a, int cost) {
    if (!V.count(now) || V[now] > cost) {
        V[now] = cost;
    }
    for (int i = 0; i < a.size(); i++) {
        if (!need[a[i]])
            continue;
        string b = a;
        b.erase(b.begin() + i);
        now.add(a[i]);
        if (now.ok())
            dfs(b, cost + (i - 1 - 0 + 1) * (a.size() - 1 - (i + 1) + 1));
        now.del(a[i]);
    }
}
class Solution {
  public:
    int Leetcode(vector<string> &words) {
        // for (auto i : "cdehlot")
        //     cout << i << ' ';
        // cout << endl;
        memset(need, 0, sizeof(need));
        for (auto i : "helloleetcode")
            need[i]++;
        map<node, int> dp;
        map<node, int> dp2;
        {
            node jb;
            jb.clear();
            dp[jb] = 0;
        }
        for (auto i : words) {
            V.clear();
            now.clear();
            dfs(i, 0);

            // for (auto [a, b] : V) {
            //     cout << a << '|' << b << endl;
            // }
            // for (auto [a, b] : dp) {
            //     cout << a << '|' << b << endl;
            // }
            // cout << endl;
            for (auto [state0, cost0] : dp) {
                for (auto [get, cost1] : V) {
                    auto now = state0 + get;
                    if (now.ok()) {
                        if (!dp2.count(now)) {
                            dp2[now] = cost0 + cost1;
                        } else {
                            dp2[now] = min(cost0 + cost1, dp2[now]);
                        }
                    }
                }
            }
            dp = dp2;
        }
        // for (auto [a, b] : dp) {
        //     cout << a << '|' << b << endl;
        // }
        {
            node jb;
            jb.set();
            if (!dp.count(jb))
                return -1;
            else
                return dp[jb];
        } // multiset<node> st;
        // memset(dp, 0x3f, sizeof(dp));
        // dp[0][0][0][0][0][0][0] = 0;
        // st.insert({0, 0, 0, 0, 0, 0, 0, 0});
        // while (!st.empty()) {
        //     auto now = *st.begin();
        //     st.erase(st.begin());
        //     if (dp[now.c][now.d][now.e][now.h][now.l][now.o][now.t] < now.cost)
        //         continue;
        // }
    }
};
#ifdef RINNE
int32_t main() {
    // freopen("x", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{};
    vector<int> v{5, 3, 3, 3};
    vector<string> VV{"hello", "leetcode"};
    // vector<string> VV{"hold", "engineer", "cost", "level"};
    // vector<string> VV{"engineer"};

    Solution *s = new Solution();
    string sb = "aaabaab";
    auto res = s->Leetcode(VV);
    debug(res);
    delete s;
    return 0;
}
#endif