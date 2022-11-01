// id:318326757
// runtime:16 ms
// memory:21.2 MB
// title:Logical OR of Two Binary Grids Represented as Quad-Trees
// translatedTitle:四叉树交集
// questionId:773
// time:2022-05-26 16:06:00

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
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node*
_bottomRight) { val = _val; isLeaf = _isLeaf; topLeft = _topLeft; topRight = _topRight; bottomLeft =
_bottomLeft; bottomRight = _bottomRight;
    }
};
*/
#ifdef RINNE
class Node {
  public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft,
         Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
#endif

class Solution {
  public:
    void push(Node *const x) {
        if (x->isLeaf)
            return;
        if (x->topLeft->isLeaf && x->topRight->isLeaf && x->bottomLeft->isLeaf &&
            x->bottomRight->isLeaf) {
            int xs = (int)x->topLeft->val + (int)x->topRight->val + (int)x->bottomLeft->val +
                     (int)x->bottomRight->val;
            if (xs == 0 || xs == 4) {
                delete x->topLeft;
                delete x->topRight;
                delete x->bottomLeft;
                delete x->bottomRight;
                x->isLeaf = 1;
                x->val = xs == 4;
                x->topLeft = nullptr;
                x->topRight = nullptr;
                x->bottomLeft = nullptr;
                x->bottomRight = nullptr;
            }
        }
    }
    Node *solve(Node *src, int val) {
        Node *ret;
        if (src->isLeaf) {
            ret = new Node();
            ret->isLeaf = 1;
            ret->val = src->val | val;
            ret->topLeft = nullptr;
            ret->topRight = nullptr;
            ret->bottomLeft = nullptr;
            ret->bottomRight = nullptr;
        } else {
            ret = new Node();
            ret->isLeaf = 0;
            ret->val = 0;
            ret->topLeft = solve(src->topLeft, val);
            ret->topRight = solve(src->topRight, val);
            ret->bottomLeft = solve(src->bottomLeft, val);
            ret->bottomRight = solve(src->bottomRight, val);
        }
        push(ret);
        return ret;
    }
    Node *intersect(Node *st1, Node *st2) {
        Node *ret;
        if (st1->isLeaf && st2->isLeaf) {
            ret = new Node();
            ret->isLeaf = 1;
            ret->val = st1->val | st2->val;
            ret->topLeft = nullptr;
            ret->topRight = nullptr;
            ret->bottomLeft = nullptr;
            ret->bottomRight = nullptr;
        } else if (st1->isLeaf && !st2->isLeaf) {
            ret = solve(st2, st1->val);
        } else if (!st1->isLeaf && st2->isLeaf) {
            ret = solve(st1, st2->val);
        } else {
            ret = new Node();
            ret->isLeaf = 0;
            ret->val = 0;
            ret->topLeft = intersect(st1->topLeft, st2->topLeft);
            ret->topRight = intersect(st1->topRight, st2->topRight);
            ret->bottomLeft = intersect(st1->bottomLeft, st2->bottomLeft);
            ret->bottomRight = intersect(st1->bottomRight, st2->bottomRight);
        }
        push(ret);
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