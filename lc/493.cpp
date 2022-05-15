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
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

struct Treap {
    static const int P = 1e9 + 7;
    struct Node {
        Node *son[2];
        int key, v, cnt, size;
        Node(int v) : key(rand() % P), v(v), cnt(1), size(1) { son[0] = son[1] = null; }
        Node(void *) : key(P), cnt(0), size(0) { son[0] = son[1] = 0; }
        int MinID() { return son[0]->key > son[1]->key; }
        void Up() { size = son[0]->size + cnt + son[1]->size; }
    } * root;
    static Node *null;
    Treap() : root(null) {}
    static void Trans(Node *&pos, int d) {
        Node *s = pos->son[d];
        pos->son[d] = s->son[!d];
        s->son[!d] = pos;
        pos->Up(), s->Up();
        pos = s;
    }
    static int Adjust(Node *&pos) {
        int d = pos->MinID();
        if (pos->key > pos->son[d]->key) {
            Trans(pos, d);
            return !d;
        } else
            return -1;
    }
    static void Insert(Node *&pos, int v) {
        if (pos == null)
            pos = new Node(v);
        else if (pos->v == v) {
            pos->cnt++;
            pos->Up();
        } else {
            Insert(pos->son[pos->v < v], v);
            pos->Up();
            Adjust(pos);
        }
    }
    static void Remove(Node *&pos) {
        if (pos->son[0] == null && pos->son[1] == null)
            pos = null;
        else {
            int p = Adjust(pos);
            Remove(pos->son[p]);
            pos->Up();
        }
    }
    static void Delete(Node *&pos, int v) {
        if (pos->v == v) {
            if (--pos->cnt == 0) {
                pos->key = P;
                Remove(pos);
            } else
                pos->Up();
        } else {
            Delete(pos->son[pos->v < v], v);
            pos->Up();
        }
    }
    void Insert(int x) { Insert(root, x); }
    void Delete(int x) { Delete(root, x); }
    // number of nodes < v
    int Rank(ll v) {
        int res = 0;
        for (Node *pos = root; pos != null;)
            if (pos->v < v) {
                res += pos->cnt + pos->son[0]->size;
                pos = pos->son[1];
            } else
                pos = pos->son[0];
        return res;
    }
    // 1 based
    int Kth(int k) {
        for (Node *pos = root; pos != null;)
            if (pos->son[0]->size + 1 <= k && k <= pos->son[0]->size + pos->cnt)
                return pos->v;
            else if (k <= pos->son[0]->size)
                pos = pos->son[0];
            else {
                k -= pos->son[0]->size + pos->cnt;
                pos = pos->son[1];
            }
        throw;
    }
    int Pred(int v) {
        int res;
        for (Node *pos = root; pos != null;) {
            if (pos->v < v) {
                res = pos->v;
                pos = pos->son[1];
            } else
                pos = pos->son[0];
        }
        return res;
    }
    int Succ(int v) {
        int res;
        for (Node *pos = root; pos != null;) {
            if (pos->v > v) {
                res = pos->v;
                pos = pos->son[0];
            } else
                pos = pos->son[1];
        }
        return res;
    }
};
Treap::Node *Treap::null = new Treap::Node((void *)0);
class Solution {
  public:
    int reversePairs(vector<int> &nums) {
        Treap *st = new Treap();
        int sz = 0;
        int ans = 0;
        for (int i : nums) {
            ans += sz - st->Rank(1LL * i + i + 1);
            st->Insert(i);
            sz++;
        }
        delete st;
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
    vector<int> data{1, 3, 2, 3, 1};
    Solution s;
    auto res = s.reversePairs(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
