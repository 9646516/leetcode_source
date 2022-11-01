// id:358838143
// runtime:472 ms
// memory:146.1 MB
// title:Meeting Rooms III
// translatedTitle:会议室 III
// questionId:2479
// time:2022-09-04 13:13:36

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
const int ADD = 1;
const int REMOVE = 0;
class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        vector<pair<int, int>> V;
        multiset<tuple<ll, int, int>> V2;
        for (ll i = 0; i < (ll)meetings.size(); i++) {
            int a = meetings[i][0];
            int b = meetings[i][1];
            V.push_back({a, b - a});
            V2.insert({a, ADD, i});
        }
        queue<pair<int, int>> waiting;
        vector<int> cnt(105, 0);
        bitset<105> stat;
        stat.set();
        while (!V2.empty()) {
            auto [now, b, idx] = *V2.begin();
            V2.erase(V2.begin());
            if (b == ADD) {
                ll pos = stat._Find_first();
                if (pos == n) {
                    waiting.push({now, idx});
                } else {
                    debug(idx, pos);
                    cnt[pos]++;
                    stat[pos] = 0;
                    V2.insert({now + V[idx].second, REMOVE, pos});
                }
            } else {
                stat[idx] = 1;
                if (!waiting.empty()) {
                    ll pos = stat._Find_first();
                    auto [_, idx] = waiting.front();
                    waiting.pop();
                    cnt[pos]++;
                    stat[pos] = 0;
                    debug(idx, pos);
                    V2.insert({now + V[idx].second, REMOVE, pos});
                }
            }
        }
        debug(waiting.size());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            debug(i, cnt[i]);
            if (cnt[i] > cnt[ans])
                ans = i;
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
    freopen("in2", "r", stdin);
    int n = 2;
    // cin >> n;
    int a, b;
    vector<vector<int>> V{{10, 11}, {2, 10}, {1, 17}, {9, 13}, {18, 20}};
    // vector<vector<int>> V{};
    // while (cin >> a >> b) {
    //     V.push_back({a, b});
    // }
    Solution *s = new Solution();
    auto res = s->mostBooked(n, V);
    debug(res);
    return 0;
}
#endif