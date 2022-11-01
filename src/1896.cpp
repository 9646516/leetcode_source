// id:359907878
// runtime:180 ms
// memory:63.4 MB
// title:Minimum Cost to Change the Final Value of Expression
// translatedTitle:反转表达式值的最少操作次数
// questionId:2008
// time:2022-09-06 20:41:52

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
 * @lc app=leetcode.cn id=1896 lang=cpp
 *
 * [1896] 反转表达式值的最少操作次数
 */
const int ADD = 2;
const int OR = 3;
struct node {
    int val;
    node *L;
    node *R;
    node(int val) {
        L = R = nullptr;
        this->val = val;
    }
};

class Solution {
  public:
    pair<int, int> dfs(node *x) {
        if (x->val == OR) {
            auto [l0, l1] = dfs(x->L);
            auto [r0, r1] = dfs(x->R);
            int ans0 = min({l0 + r0, 1 + l0 + r1, 1 + r0 + l1});
            int ans1 = min({l1 + r0, r1 + l0, l1 + r1});
            // cout << ans0 << ' ' << ans1 << endl;
            return {ans0, ans1};
        } else if (x->val == ADD) {
            auto [l0, l1] = dfs(x->L);
            auto [r0, r1] = dfs(x->R);
            int ans0 = min({l0 + r1, l1 + r0, l0 + r0});
            int ans1 = min({l1 + r1, 1 + l1 + r0, 1 + r1 + l0});
            return {ans0, ans1};
        } else if (x->val == 1) {
            return {1, 0};
        } else {
            // cout << "0" << endl;
            return {0, 1};
        }
    }
    int minOperationsToFlip(string str) {
        stack<node *> val;
        stack<int> number;
        stack<char> op;
        auto step = [&]() {
            auto ch = op.top();
            op.pop();
            node *R = val.top();
            val.pop();
            node *L = val.top();
            val.pop();

            int a = number.top();
            number.pop();
            int b = number.top();
            number.pop();

            node *head;
            if (ch == '|') {
                number.push(a | b);
                head = new node(OR);
            } else {
                number.push(a & b);
                head = new node(ADD);
            }
            head->L = L;
            head->R = R;
            val.push(head);
        };
        for (int i : str) {
            if (i == '0' || i == '1') {
                val.push(new node(i - '0'));
                number.push(i - '0');
                if (!op.empty() && op.top() != '(')
                    step();
            } else if (i == '(' || i == '|' || i == '&') {
                op.push(i);
            } else {
                op.pop();
                if (!op.empty() && op.top() != '(')
                    step();
            }
        }
        node *fa = val.top();
        int result = number.top();
        auto [a, b] = dfs(fa);
        if (result == 1)
            return a;
        else
            return b;
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
    string sb = "1|1|(0&0)&1";
    auto res = s.minOperationsToFlip(sb);
    debug(res);
    return 0;
}
#endif