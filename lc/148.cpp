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
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#ifdef RINNE
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
  public:
    using node = ListNode;
    node *dummy1, *dummy2;
    mt19937 rng;
    pair<node *, node *> qsort(node *head, int len) {
        if (len > 1) {
            node *split = head;
            {
                const int n = rng() % (len - 1);
                for (int i = 0; i < n; i++) {
                    split = split->next;
                }
            }

            int left = 0, right = 0;
            node *tail1 = dummy1, *tail2 = dummy2;
            {
                node *now = head;
                for (int i = 0; i < len; i++) {
                    if (now != split) {
                        if (now->val < split->val) {
                            tail1->next = now;
                            tail1 = tail1->next;
                            left++;
                        } else {
                            tail2->next = now;
                            tail2 = tail2->next;
                            right++;
                        }
                    }
                    now = now->next;
                }
            }

            node *s1 = dummy1->next, *s2 = dummy2->next;
            if (left && right) {
                auto [h1, t1] = this->qsort(s1, left);
                auto [h2, t2] = this->qsort(s2, right);
                t1->next = split;
                split->next = h2;
                t2->next = nullptr;
                return {h1, t2};
            } else if (left) {
                auto [h1, t1] = this->qsort(s1, left);
                t1->next = split;
                split->next = nullptr;
                return {h1, split};
            } else {
                auto [h2, t2] = this->qsort(s2, right);
                split->next = h2;
                t2->next = nullptr;
                return {split, t2};
            }
        } else {
            return {head, head};
        }
    }
    ListNode *sortList(ListNode *head) {
        if (!head)
            return nullptr;
        else {
            rng = mt19937(random_device{}());
            dummy1 = new node();
            dummy2 = new node();
            int len = 0;
            {
                auto now = head;
                while (now) {
                    len++;
                    now = now->next;
                }
            }
            auto [h, t] = this->qsort(head, len);
            delete dummy1;
            delete dummy2;
            return h;
        }
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
// @lc code=end
