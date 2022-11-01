// id:102985248
// runtime:32 ms
// memory:14.7 MB
// title:Number of Ways to Reorder Array to Get Same BST
// translatedTitle:将子数组重新排序得到同一个二叉查找树的方案数
// questionId:1692
// time:2020-08-30 10:56:46

#include <bits/stdc++.h>
using namespace std;
// https://github.com/the-tourist/algo/blob/master/misc/debug.cpp
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
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
#ifdef RINNE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:\t", debug_out(__VA_ARGS__)
#else
#define debug(...) 114514
#endif
using ll = long long;
const int MOD = 1e9 + 7;
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
    friend IntMod operator+(IntMod a, IntMod b) { return build(a.n >= MOD - b.n ? a.n - MOD + b.n : a.n + b.n); }
    friend IntMod operator-(IntMod a, IntMod b) { return build(a.n >= b.n ? a.n - b.n : a.n - b.n + MOD); }
    friend IntMod operator*(IntMod a, IntMod b) { return build(static_cast<base_type>(static_cast<long long>(a.n) * b.n % MOD)); }
    friend istream &operator>>(istream &stream, IntMod &a) {
        stream >> a.n;
        return stream;
    }
    friend ostream &operator<<(ostream &stream, const IntMod &a) {
        stream << a.n;
        return stream;
    }
};
const int N = 1000;
const int maxn = N + 555;
const int INF = 0x3F3F3F3F;
using Int = IntMod<int, MOD>;
struct node {
    node *L;
    node *R;
    int val;
    int sz;
    node(int val) {
        this->val = val;
        this->sz = 1;
        this->L = this->R = nullptr;
    }
};
class Solution {
  public:
    void add(node *root, int val) {
        if (val > root->val) {
            if (root->R) {
                add(root->R, val);
            } else {
                root->R = new node(val);
            }
        } else {
            if (root->L) {
                add(root->L, val);
            } else {
                root->L = new node(val);
            }
        }
    }
    void dfs(node *root) {
        if (root->L) {
            dfs(root->L);
            root->sz += root->L->sz;
        }
        if (root->R) {
            dfs(root->R);
            root->sz += root->R->sz;
        }
    }
    int numOfWays(vector<int> &V) {
        node *root = new node(V[0]);
        for (int i = 1; i < (int)V.size(); i++) {
            add(root, V[i]);
        }
        dfs(root);
        static ll inv[N + 555], invp[N + 555], p[N + 555];
        inv[1] = 1;
        for (int i = 2; i <= N; i++)
            inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
        p[0] = 1;
        for (int i = 1; i <= N; i++)
            p[i] = p[i - 1] * i % MOD;
        invp[0] = 1;
        for (int i = 1; i <= N; i++)
            invp[i] = invp[i - 1] * inv[i] % MOD;
        auto C = [&](int a, int b) -> ll {
            if (a < b)
                return 0;
            else
                return p[a] * invp[b] % MOD * invp[a - b] % MOD;
        };
        function<Int(node *)> gao = [&](node *root) -> Int {
            if (root->L == nullptr and root->R == nullptr) {
                return 1;
            } else if (root->L == nullptr) {
                return gao(root->R);
            } else if (root->R == nullptr) {
                return gao(root->L);
            } else {
                Int L = gao(root->L);
                Int R = gao(root->R);
                return L * R * C(root->sz - 1, root->L->sz);
            }
        };
        return (gao(root) - 1).n;
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{2, 1, 3};
    Solution s;
    auto res = s.numOfWays(a);
    debug(res);
    return 0;
}
#endif