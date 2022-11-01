// id:357674562
// runtime:1216 ms
// memory:275.2 MB
// title:Maximum Number of Tasks You Can Assign
// translatedTitle:你可以安排的最多任务数目
// questionId:2180
// time:2022-09-01 16:25:01

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
 * @lc app=leetcode.cn id=2071 lang=cpp
 *
 * [2071] 你可以安排的最多任务数目
 */

class Solution {
  public:
    int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end(), greater<int>());
        int L = 1, R = min(tasks.size(), workers.size()), ans = 0;
        multiset<int> st;
        while (L <= R) {
            st.clear();
            int mid = (L + R) / 2;
            for (int i = 0; i < mid; i++) {
                st.insert(workers[i]);
            }
            bool ok = 1;
            int used = 0;
            for (int i = mid - 1; i >= 0; i--) {
                int need = tasks[i];
                auto ptr = st.lower_bound(need);
                if (ptr == st.end()) {
                    ptr = st.lower_bound(need - strength);
                    if (ptr == st.end()) {
                        ok = 0;
                        break;
                    }
                }
                int val = *ptr;
                st.erase(ptr);
                if (val >= need) {
                    continue;
                } else if (val + strength >= need) {
                    used++;
                    if (used > pills) {
                        ok = 0;
                        break;
                    }
                } else {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
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
    vector<int> data{};
    Solution s;
    auto res = s.solve(data);
    debug(res);
    return 0;
}
#endif