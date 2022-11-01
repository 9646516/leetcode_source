// id:361096025
// runtime:184 ms
// memory:69.6 MB
// title:Count Pairs With XOR in a Range
// translatedTitle:统计异或值在范围内的数对有多少
// questionId:1907
// time:2022-09-09 16:42:01

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
 * @lc app=leetcode.cn id=1803 lang=cpp
 *
 * [1803] 统计异或值在范围内的数对有多少
 */
struct node {
    int cnt;
    node *next[2];
    node() {
        cnt = 0;
        next[0] = next[1] = nullptr;
    }
};
void insert(node *root, int val) {
    for (int i = 16; i >= 0; i--) {
        int B = (val >> i) & 1;
        if (!root->next[B])
            root->next[B] = new node();
        root = root->next[B];
        root->cnt++;
    }
}
int get_greater(node *root, int val, int cmp) {
    int ret = 0;
    for (int i = 16; i >= 0; i--) {
        int B = (val >> i) & 1;
        int B2 = (cmp >> i) & 1;

        int eq = B ^ B2;
        if (B2 == 0) {
            node *g = root->next[eq ^ 1];
            if (g)
                ret += g->cnt;
        }

        root = root->next[eq];
        if (!root)
            break;
    }
    if (root)
        ret += root->cnt;
    return ret;
}
int get_less(node *root, int val, int cmp) {
    int ret = 0;
    for (int i = 16; i >= 0; i--) {
        int B = (val >> i) & 1;
        int B2 = (cmp >> i) & 1;

        int eq = B ^ B2;
        if (B2 == 1) {
            node *g = root->next[eq ^ 1];
            if (g) {
                // cout << i << ' ' << g->cnt << endl;

                ret += g->cnt;
            }
        }

        root = root->next[eq];
        if (!root)
            break;
    }
    if (root) {
        ret += root->cnt;

        // cout << "self" << endl;
    }
    return ret;
}
class Solution {
  public:
    int countPairs(vector<int> &nums, int low, int high) {
        int ans = 0;
        node *root = new node();
        for (int i = 0; i < (int)nums.size(); i++) {
            int a = get_greater(root, nums[i], low);
            int b = get_less(root, nums[i], high);
            // cout << i << ' ' << a << ' ' << b << endl;
            ans += a + b - i;
            insert(root, nums[i]);
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