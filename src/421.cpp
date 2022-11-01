// id:313025981
// runtime:296 ms
// memory:77.5 MB
// title:Maximum XOR of Two Numbers in an Array
// translatedTitle:数组中两个数的最大异或值
// questionId:421
// time:2022-05-13 16:34:19

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
 * @lc app=leetcode.cn id=421 lang=cpp
 *
 * [421] 数组中两个数的最大异或值
 */
struct node {
    node *next[2];
    int cnt = 0;
};
void insert(node *root, int val) {
    for (int i = 30; i >= 0; i--) {
        int b = (val >> i) & 1;
        if (!root->next[b])
            root->next[b] = new node();
        root = root->next[b];
        root->cnt++;
    }
}
void erase(node *root, int val) {
    for (int i = 30; i >= 0; i--) {
        int b = (val >> i) & 1;
        root = root->next[b];
        root->cnt--;
    }
}
int get_res(node *root, int val) {
    int ret = 0;
    for (int i = 30; i >= 0; i--) {
        int b = (val >> i) & 1;
        int nb = !b;
        if (root->next[nb] && root->next[nb]->cnt) {
            ret |= (nb) << i;
            root = root->next[nb];
        } else {
            ret |= (b) << i;
            root = root->next[b];
        }
    }
    return ret;
}
class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        node *root = new node();
        for (int i : nums) {
            insert(root, i);
        }
        int ans = 0;
        for (int i : nums) {
            erase(root, i);
            int lv = get_res(root, i);
            // cout << i << ' ' << lv << endl;
            ans = max(ans, lv ^ i);
            insert(root, i);
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
    vector<int> data{3, 10, 5, 25, 2, 8};
    Solution s;
    auto res = s.findMaximumXOR(data);
    debug(res);
    return 0;
}
#endif