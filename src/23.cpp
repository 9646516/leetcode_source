// id:297333841
// runtime:492 ms
// memory:14.1 MB
// title:Merge k Sorted Lists
// translatedTitle:合并K个升序链表
// questionId:23
// time:2022-04-09 17:02:54

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
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        else {
            int choose = -1;

            for (int i = 0; i < (int)lists.size(); i++) {
                if (lists[i]) {
                    if (choose == -1 || lists[i]->val < lists[choose]->val) {
                        choose = i;
                    }
                }
            }
            if (choose == -1) {
                return nullptr;
            } else {
                node *head = lists[choose];
                node *now = head;
                set<node *> V;
                for (int i = 0; i < (int)lists.size(); i++) {
                    if (i == choose) {
                        node *now = lists[i]->next;
                        if (now) {
                            V.insert(now);
                        }
                    } else if (lists[i]) {
                        V.insert(lists[i]);
                    }
                }
                while (V.size() > 1) {
                    node *ptr = nullptr;
                    for (auto i : V) {
                        if (!ptr || i->val < ptr->val) {
                            ptr = i;
                        }
                    }
                    now->next = ptr;
                    now = now->next;
                    V.erase(ptr);
                    if (ptr->next) {
                        V.insert(ptr->next);
                    }
                }
                if (V.size() == 1) {
                    now->next = *V.begin();
                } else {
                    now->next = nullptr;
                }
                return head;
            }
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
    // auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif