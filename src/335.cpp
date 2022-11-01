// id:309533371
// runtime:204 ms
// memory:50.4 MB
// title:Self Crossing
// translatedTitle:路径交叉
// questionId:335
// time:2022-05-05 17:43:35

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
 * @lc app=leetcode.cn id=335 lang=cpp
 *
 * [335] 路径交叉
 */
struct cmp {
    bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) const {
        return get<2>(a) < get<2>(b);
    }
};

class Solution {
  public:
    bool check2(vector<pair<int, int>> &V) {
        sort(V.begin(), V.end());
        vector<pair<int, int>> st;
        for (auto [a, b] : V) {
            if (st.empty()) {
                st.push_back({a, b});
            } else {
                if (st.back().second >= a)
                    return false;
                else
                    st.push_back({a, b});
            }
        }
        return true;
    }
    bool check(vector<tuple<int, int, int>> &V) {
        map<int, vector<pair<int, int>>> mp;
        for (auto [a, b, c] : V) {
            mp[a].push_back({b, c});
        }
        for (auto &i : mp) {
            if (!check2(i.second))
                return false;
        }
        return true;
    }
    bool isSelfCrossing(vector<int> &V) {
        int x = 0, y = 0;
        vector<tuple<int, int, int>> heng;
        vector<tuple<int, int, int>> shu;
        for (int i = 0; i < (int)V.size();) {
            if (i < (int)V.size()) {
                int val = V[i++];
                int y2 = y + val;
                shu.emplace_back(x, y, y2);
                y = y2;
            }
            if (i < (int)V.size()) {
                int val = V[i++];
                int x2 = x - val;
                heng.emplace_back(y, x2, x);
                x = x2;
            }

            if (i < (int)V.size()) {
                int val = V[i++];
                int y2 = y - val;
                shu.emplace_back(x, y2, y);
                y = y2;
            }
            if (i < (int)V.size()) {
                int val = V[i++];
                int x2 = x + val;
                heng.emplace_back(y, x, x2);
                x = x2;
            }
        }
        set<tuple<int, int, int>> ord;
        ord.insert(shu[0]);
        if (V.size() % 4 == 1 || V.size() % 4 == 3) {
            ord.insert(shu.back());
        }
        if (!check(heng))
            return true;
        if (!check(shu))
            return true;
        debug(1111);
        sort(heng.begin(), heng.end(),
             [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
                 auto &[y1, a1, b1] = a;
                 auto &[y2, a2, b2] = b;
                 return a1 < a2;
             });
        sort(shu.begin(), shu.end(),
             [](const tuple<int, int, int> &a, const tuple<int, int, int> &b) {
                 auto &[y1, a1, b1] = a;
                 auto &[y2, a2, b2] = b;
                 return y1 < y2;
             });
        multiset<int> st;
        multiset<tuple<int, int, int>, cmp> q;
        int ptr = 0;
        for (auto i : shu) {
            auto [x, a, b] = i;
            while (ptr < (int)heng.size()) {
                auto [y1, a1, b1] = heng[ptr];
                if (a1 <= x) {
                    q.insert(heng[ptr++]);
                    st.insert(y1);
                } else
                    break;
            }
            while (!q.empty()) {
                auto [y1, a1, b1] = *q.begin();
                if (b1 < x) {
                    q.erase(q.begin());
                    st.erase(st.lower_bound(y1));
                } else
                    break;
            }
            debug(x, a, b);
            debug(q);
            debug(st);
            auto ptr = st.lower_bound(a);
            int cnt = 0;
            while (ptr != st.end()) {
                if (*ptr <= b) {
                    cnt++;
                    ptr++;
                } else
                    break;
            }
            if (ord.count(i)) {
                if (cnt > 1)
                    return true;
            } else {
                if (cnt > 2)
                    return true;
            }
        }
        return false;
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{1, 1, 2, 2, 3, 3, 4, 4, 10, 4, 4, 3, 3, 2, 2, 1, 1};
    Solution s;
    auto res = s.isSelfCrossing(data);
    debug(res);
    return 0;
}
#endif