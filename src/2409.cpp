// id:364122066
// runtime:0 ms
// memory:5.7 MB
// title:Count Days Spent Together
// translatedTitle:统计共同度过的日子数
// questionId:2496
// time:2022-09-17 22:40:23

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
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Solution {
  public:
    int split(string s) {
        int a = s[0] - '0';
        int b = s[1] - '0';
        int c = s[3] - '0';
        int d = s[4] - '0';
        int f = a * 10 + b;
        int ret = 0;
        for (int i = 1; i < f; i++)
            ret += days[i];
        ret += c * 10 + d;
        return ret;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob,
                          string leaveBob) {
        int a1 = split(arriveAlice);
        int b1 = split(leaveAlice);
        int a2 = split(arriveBob);
        int b2 = split(leaveBob);
        if (a1 <= a2 && a2 <= b1 && b1 <= b2)
            return b1 - a2 + 1;
        else if (a2 <= a1 && a1 <= b2 && b2 <= b1)
            return b2 - a1 + 1;
        else if (a1 <= a2 && a2 <= b2 && b2 <= b1)
            return b2 - a2 + 1;
        else if (a2 <= a1 && a1 <= b1 && b1 <= b2)
            return b1 - a1 + 1;
        return 0;
    }
};
#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(10);
    cout << fixed;
    vector<int> a{};
    vector<int> b{};
    string sb;
    Solution *s = new Solution();
    auto res = s->maximumRobots(a, b, 19);
    debug(res);
    return 0;
}
#endif
