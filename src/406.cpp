// id:311304194
// runtime:88 ms
// memory:13.4 MB
// title:Queue Reconstruction by Height
// translatedTitle:根据身高重建队列
// questionId:406
// time:2022-05-09 18:24:39

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
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
struct member {
    int h;
    int m;
    int fa;
    friend bool operator<(const member &lhs, const member &rhs) {
        if (lhs.fa != rhs.fa)
            return lhs.fa < rhs.fa;
        else
            return lhs.h < rhs.h;
    }
};

class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        vector<member> st;
        vector<member> st2;
        for (auto &i : people) {
            st.push_back({i[0], i[1], i[1]});
        }
        sort(st.begin(), st.end());
        multiset<pair<int, int>> q;
        vector<vector<int>> ret;
        for (auto &i : st) {
            if (i.fa == 0) {
                q.insert({i.h, i.m});
            } else {
                st2.push_back(i);
            }
        }
        swap(st, st2);
        st2.clear();
        while (!q.empty()) {
            auto [h, m] = *q.begin();
            q.erase(q.begin());
            ret.push_back({h, m});
            for (auto &i : st) {
                if (i.h <= h) {
                    i.fa--;
                }
                if (i.fa == 0) {
                    q.insert({i.h, i.m});
                } else {
                    st2.push_back(i);
                }
            }
            swap(st, st2);
            st2.clear();
        }
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
    vector<vector<int>> data{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution s;
    auto res = s.reconstructQueue(data);
    debug(res);
    return 0;
}
#endif