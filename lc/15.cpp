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
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
struct Hash {
    std::uint64_t operator()(tuple<int, int, int> const &s) const {
        const auto &[a, b, c] = s;
        return uint64_t(a) * 233 * 233 + uint64_t(b) * 233 + uint64_t(c);
    }
};

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        if (nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        vector<int> next(nums.size() + 5);
        int last = nums.size();
        int now = nums.back();
        for (int i = (int)nums.size() - 1; i >= 0; i--) {
            if (nums[i] == now) {
                next[i] = last;
            } else {
                now = nums[i];
                last = i + 1;
                next[i] = last;
            }
        }
        debug(next);
        debug(nums);
        unordered_set<tuple<int, int, int>, Hash> st;
        auto gao = [&](int p, int L, int target) {
            int R = nums.size() - 1;
            while (L < R) {
                while (R > L && nums[L] + nums[R] > target) {
                    R--;
                }
                if (R <= L)
                    break;
                if (nums[L] + nums[R] == target) {
                    st.emplace(nums[p], nums[L], nums[R]);
                }
                L++;
            }
        };
        for (int i = 0; i + 1 < (int)nums.size(); i = next[i]) {
            gao(i, i + 1, -nums[i]);
        }
        vector<vector<int>> ret;
        ret.reserve(st.size());
        for (const auto &[a, b, c] : st) {
            ret.push_back({a, b, c});
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
    vector<int> data{};
    Solution s;
    auto res = s.threeSum(data);
    debug(res);
    return 0;
}
#endif
// @lc code=end
