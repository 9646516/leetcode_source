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
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
struct node {
    node *prev;
    node *next;
    int key;
    int val;
    node(int key = 0, int val = 0) : key(key), val(val) {}
};
struct LinkList {
  private:
    node *head;
    node *tail;
    int sz;

  public:
    LinkList() {
        sz = 0;
        head = new node();
        tail = new node();
        head->next = tail;
        tail->prev = head;
    }
    ~LinkList() {
        delete head;
        delete tail;
    }

  private:
    void push_back_node(node *ret) {
        tail->prev->next = ret;
        ret->prev = tail->prev;
        ret->next = tail;
        tail->prev = ret;
    }

    void remove(node *x) {
        auto _prev = x->prev;
        auto _next = x->next;
        _prev->next = _next;
        _next->prev = _prev;
    }

  public:
    node *append(int key, int val) {
        node *ret = new node(key, val);
        push_back_node(ret);
        sz++;
        return ret;
    }
    int len() const { return sz; }
    void raise(node *x) {
        remove(x);
        push_back_node(x);
    }
    node *pop() {
        sz--;
        auto ret = head->next;
        remove(ret);
        return ret;
    }
};

class LRUCache {
    int cap;
    unordered_map<int, node *> mp;
    LinkList *V;

  public:
    LRUCache(int capacity) {
        cap = capacity;
        V = new LinkList();
    }
    ~LRUCache() { delete V; }
    int get(int key) {
        if (mp.count(key)) {
            auto now = mp[key];
            V->raise(now);
            return now->val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (!mp.count(key)) {
            if (V->len() == cap) {
                auto decay = V->pop();
                mp.erase(decay->key);
                delete decay;
            }
            mp[key] = V->append(key, value);
        } else {
            auto old = mp[key];
            old->val = value;
            V->raise(old);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

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
