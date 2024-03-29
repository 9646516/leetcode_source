// id:313465774
// runtime:472 ms
// memory:178.3 MB
// title:LFU Cache
// translatedTitle:LFU 缓存
// questionId:460
// time:2022-05-14 20:55:31

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
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
struct node {
    int key;
    int val;
    int rank;
    list<pair<int, list<node>>>::iterator fa;
};

class LFUCache {
  public:
    int sz;
    int cap;
    unordered_map<int, list<node>::iterator> mp;
    list<pair<int, list<node>>> V;
    LFUCache(int capacity) {
        this->cap = capacity;
        sz = 0;
    }
    int get(int key) {
        if (mp.count(key)) {
            auto copy = *mp[key];
            auto fa = copy.fa;
            fa->second.erase(mp[key]);
            copy.rank++;
            auto nxt = next(fa);
            if (nxt == V.end() || nxt->first != copy.rank) {
                nxt = V.insert(nxt, {copy.rank, {}});
            }
            copy.fa = nxt;
            mp[key] = nxt->second.insert(nxt->second.end(), copy);
            if (fa->second.empty())
                V.erase(fa);
            return copy.val;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cap == 0) {
            return;
        }
        if (mp.count(key)) {
            auto copy = *mp[key];
            auto fa = copy.fa;
            fa->second.erase(mp[key]);
            copy.rank++;
            copy.val = value;
            auto nxt = next(fa);
            if (nxt == V.end() || nxt->first != copy.rank) {
                nxt = V.insert(nxt, {copy.rank, {}});
            }
            copy.fa = nxt;
            mp[key] = nxt->second.insert(nxt->second.end(), copy);
            if (fa->second.empty())
                V.erase(fa);
        } else {
            sz++;
            if (sz > cap) {
                sz--;
                auto &fst = V.front().second;
                auto to_remove = fst.front();
                fst.erase(fst.begin());
                if (fst.empty())
                    V.erase(V.begin());
                mp.erase(to_remove.key);
            }
            if (V.empty() || V.front().first != 1) {
                V.insert(V.begin(), {1, {}});
            }
            node cur{key, value, 1, V.begin()};
            auto &st = V.front().second;
            mp[key] = st.insert(st.end(), cur);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

#ifdef RINNE
int32_t main() { return 0; }
#endif