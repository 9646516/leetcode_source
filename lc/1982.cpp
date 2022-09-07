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
 * @lc app=leetcode.cn id=1982 lang=cpp
 *
 * [1982] 从子集的和还原数组
 */

class Solution {
  public:
    vector<int> gao(const vector<int> &V, int val) {
        list<int> st;
        for (int i : V)
            st.push_back(i);
        vector<int> ret;
        if (val > 0) {
            auto pos = st.begin();
            while (!st.empty()) {
                if (pos == st.begin())
                    pos++;
                auto a = *st.begin();
                st.erase(st.begin());
                int b = a + val;
                while (pos != st.end() && *pos < b) {
                    pos++;
                }
                if (*pos != b)
                    return {};
                auto pos2 = next(pos);
                st.erase(pos);
                pos = pos2;

                ret.push_back(a);
            }
        } else {
            auto pos = st.begin();
            while (!st.empty()) {
                if (pos == st.begin())
                    pos++;
                auto a = *st.begin();
                st.erase(st.begin());
                int b = a - val;
                while (pos != st.end() && *pos < b) {
                    pos++;
                }
                if (*pos != b)
                    return {};
                auto pos2 = next(pos);
                st.erase(pos);
                pos = pos2;

                ret.push_back(b);
            }
            reverse(ret.begin(), ret.end());
        }
        return ret;
    }
    vector<int> recoverArray(int n, vector<int> &sums) {
        sort(sums.begin(), sums.end());
        return dfs(n, sums);
    }
    vector<int> dfs(int n, const vector<int> &sums) {
        debug(n, sums);
        if (n == 1) {
            if (sums[0] == 0)
                return {sums[1]};
            else if (sums[1] == 0)
                return {sums[0]};
            else
                return {};
        } else {
            int a = sums[0], b = sums[1];

            {
                auto f = gao(sums, a - b);
                if (!f.empty()) {
                    auto res = recoverArray(n - 1, f);
                    if (!res.empty()) {
                        res.push_back(a - b);
                        return res;
                    }
                }
            }

            {
                auto f = gao(sums, b - a);
                if (!f.empty()) {
                    auto res = recoverArray(n - 1, f);
                    if (!res.empty()) {
                        res.push_back(b - a);
                        return res;
                    }
                }
            }
            return {};
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
    vector<int> data{0, 0, 5, 5, 4, -1, 4, 9, 9, -1, 4, 3, 4, 8, 3, 8};
    Solution s;
    auto res = s.recoverArray(4, data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
