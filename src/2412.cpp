// id:364145094
// runtime:440 ms
// memory:115.9 MB
// title:Minimum Money Required Before Transactions
// translatedTitle:完成所有交易的初始最少钱数
// questionId:2499
// time:2022-09-17 23:25:28

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

class Solution {
  public:
    long long minimumMoney(vector<vector<int>> &transactions) {
        vector<pair<int, int>> V1;
        for (auto &i : transactions) {
            // if (i[0] - i[1] > 0)
            //     V1.push_back({i[0] - i[1], i[0]});
            // else
            V1.push_back({i[0] - i[1], i[0]});
        }
        sort(V1.begin(), V1.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if ((a.first > 0) != (b.first > 0))
                return a.first > 0;
            if (a.first > 0)
                return a.second - a.first < b.second - b.first;
            else
                return a.second > b.second;
        });
        auto can = [&](ll val) {
            for (auto &i : V1) {
                if (val < i.second)
                    return false;
                val -= i.first;
            }
            return true;
        };
        // sort(V1.begin(), V1.end());
        // do {
        ll L = 0, R = 1e18, ans = 0;
        while (L <= R) {
            ll mid = (L + R) / 2;
            if (can(mid)) {
                ans = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        //     if (ans == 18)
        debug(V1, ans);
        // } while (next_permutation(V1.begin(), V1.end()));
        return ans;
    }
};
#ifdef RINNE
int32_t main() {
    // freopen("x", "w", stderr);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<vector<int>> a{{3, 9}, {0, 4}, {7, 10}, {3, 5}, {0, 9},
                          {9, 3}, {7, 4}, {0, 0},  {3, 3}, {8, 0}};
    // // 24

    vector<vector<int>> b{{7, 2}, {0, 10}, {5, 0}, {4, 1}, {5, 8}, {5, 9}};
    // 18
    vector<vector<int>> c{{75, 21}, {23, 99}, {85, 61}, {20, 27}, {79, 86}, {18, 69},
                          {32, 86}, {89, 52}, {49, 19}, {29, 65}, {31, 44}, {28, 79},
                          {73, 66}, {43, 56}, {81, 95}, {13, 21}, {43, 29}, {46, 16},
                          {81, 18}, {37, 73}, {77, 98}, {68, 48}, {40, 56}, {40, 5},
                          {1, 93},  {20, 23}, {78, 36}, {51, 20}, {64, 70}, {33, 72}};
    // 468
    string sb;
    Solution *s = new Solution();
    auto res = s->minimumMoney(b);
    debug(res);
    return 0;
}
#endif

//