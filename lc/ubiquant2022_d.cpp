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

class Solution {
  public:
    uint64_t H(const vector<int> &X) {
        uint64_t ret = 0;
        for (int i : X)
            ret = ret * 233 + i;
        return ret;
    }
    double chipGame(vector<int> &nums, int kind) {
        while (nums.size() < kind) {
            nums.push_back(0);
        }
        sort(nums.begin(), nums.end());
        unordered_map<uint64_t, double> mp;
        function<double(vector<int>)> dfs = [&](const vector<int> &V) -> double {
            auto hash = H(V);
            if (mp.count(hash)) {
                return mp[hash];
            } else if (V == nums)
                return mp[hash] = 0;
            else {
                double bad = 0;
                double xs = 0;

                double p = 1.0 / kind;
                unordered_map<int, pair<double, double>> mp2;
                for (int i = 0; i < kind; i++) {
                    if (mp2.count(V[i])) {
                        auto [a, b] = mp2[V[i]];
                        bad += a;
                        xs += b;
                    } else {
                        auto now = V;
                        now[i]++;
                        for (int j = i + 1; j < kind; j++) {
                            if (now[j] < now[j - 1])
                                swap(now[j], now[j - 1]);
                        }
                        bool ok = 1;
                        for (int j = 0; j < kind; j++) {
                            if (now[j] > nums[j]) {
                                ok = 0;
                                break;
                            }
                        }
                        if (!ok) {
                            bad += p;
                            mp2[V[i]] = {p, 0};
                        } else {
                            double res = p * dfs(now);
                            xs += res;
                            mp2[V[i]] = {0, res};
                        }
                    }
                }
                return mp[hash] = (xs + 1) / (1 - bad);
            }
        };
        return dfs(vector<int>(kind, 0));
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> data{1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 5, 5, 6};
    Solution s;
    auto res = s.chipGame(data, 49);
    debug(res);
    return 0;
}
#endif
// @lc code=end
