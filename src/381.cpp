// id:310925258
// runtime:224 ms
// memory:105.6 MB
// title:Insert Delete GetRandom O(1) - Duplicates allowed
// translatedTitle:O(1) 时间插入、删除和获取随机元素 - 允许重复
// questionId:381
// time:2022-05-08 20:25:29

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
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */

class RandomizedCollection {
  public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool ret = (!idx.count(val) || idx[val].empty());
        V.push_back(val);
        idx[val].insert(V.size() - 1);
        return ret;
    }

    bool remove(int val) {
        if (!idx.count(val) || idx[val].empty())
            return false;
        int place = *idx[val].begin();
        idx[V[place]].erase(place);
        idx[V[V.size() - 1]].erase(V.size() - 1);

        idx[V[place]].insert(V.size() - 1);
        idx[V[V.size() - 1]].insert(place);

        swap(V[place], V[V.size() - 1]);

        idx[val].erase(V.size() - 1);
        V.pop_back();
        return true;
    }

    int getRandom() {
        static mt19937 rng(random_device{}());
        uniform_int_distribution<int> uni(0, V.size() - 1);
        return V[uni(rng)];
    }
    vector<int> V;
    unordered_map<int, unordered_set<int>> idx;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
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