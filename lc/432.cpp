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
 * @lc app=leetcode.cn id=432 lang=cpp
 *
 * [432] 全 O(1) 的数据结构
 */
struct node {
    int val;
    unordered_set<string> st;
};

class AllOne {
  public:
    list<node> V;
    unordered_map<string, list<node>::iterator> mp;
    AllOne() {}

    void inc(string key) {
        if (mp.count(key)) {
            auto now = mp[key];
            auto next = mp[key];
            next++;
            int val = now->val + 1;
            if (next == V.end() || next->val != val) {
                mp[key] = V.insert(next, {val, {key}});
            } else {
                next->st.insert(key);
                mp[key] = next;
            }
            now->st.erase(key);
            if (now->st.empty())
                V.erase(now);
        } else {
            if (V.empty() || V.front().val != 1) {
                mp[key] = V.insert(V.begin(), {1, {key}});
            } else {
                V.front().st.insert(key);
                mp[key] = V.begin();
            }
        }
    }

    void dec(string key) {
        auto now = mp[key];
        int val = now->val - 1;
        if (val) {
            auto prev = now;
            if (now == V.begin() || (--prev)->val != val) {
                mp[key] = V.insert(now, {val, {key}});
            } else {
                prev->st.insert(key);
                mp[key] = prev;
            }
        } else {
            mp.erase(key);
        }
        now->st.erase(key);
        if (now->st.empty())
            V.erase(now);
    }

    string getMaxKey() { return V.empty() ? "" : *prev(V.end())->st.begin(); }

    string getMinKey() { return V.empty() ? "" : *V.begin()->st.begin(); }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    AllOne *allOne = new AllOne();
    cout << 1 << endl;
    allOne->inc("hello");
    cout << 1 << endl;
    allOne->inc("hello");
    cout << allOne->getMaxKey() << endl; // 返回 "hello"
    cout << allOne->getMinKey() << endl; // 返回 "hello"
    allOne->inc("leet");
    cout << allOne->getMaxKey() << endl; // 返回 "hello"
    cout << allOne->getMinKey() << endl; // 返回 "leet"
    auto s = allOne->head;
    while (s) {
        cout << s->val << endl;
        s = s->next;
    }

    return 0;
}
#endif
// @lc code=end
