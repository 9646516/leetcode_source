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
 * @lc app=leetcode.cn id=1707 lang=cpp
 *
 * [1707] 与数组中元素的最大异或值
 */
struct node {
    node *next[2];
    node() { next[0] = next[1] = nullptr; }
};
void insert(node *root, int val) {
    for (int i = 31; i >= 0; i--) {
        int B = (val >> i) & 1;
        if (!root->next[B]) {
            root->next[B] = new node();
        }
        root = root->next[B];
    }
}

int query(node *root, int x, int m) {
    int ret = -1;
    int base = 0;
    for (int i = 31; i >= 0; i--) {
        int B2 = (m >> i) & 1;
        if (B2 == 1 && root->next[0]) {
            int now = base;
            node *root2 = root->next[0];
            for (int j = i - 1; j >= 0; j--) {
                int B1 = (x >> j) & 1;
                if (root2->next[B1 ^ 1]) {
                    now |= (B1 ^ 1) << j;
                    root2 = root2->next[B1 ^ 1];
                } else {
                    now |= B1 << j;
                    root2 = root2->next[B1];
                }
            }
            ret = max(ret, now ^ x);
        }
        if (!root->next[B2]) {
            break;
        }
        root = root->next[B2];
        base |= B2 << i;
        if (i == 0) {
            ret = max(ret, x ^ base);
        }
    }
    return ret;
}
class Solution {
  public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        node *root = new node();
        for (int i : nums) {
            insert(root, i);
        }
        vector<int> ret;
        for (auto &i : queries) {
            int x = i[0], m = i[1];
            ret.push_back(query(root, x, m));
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
    vector<int> data{0, 1, 2, 3, 4};
    vector<vector<int>> q{{5, 6}};
    Solution s;
    auto res = s.maximizeXor(data, q);
    debug(res);
    return 0;
}
#endif
// @lc code=end
