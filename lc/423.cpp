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
 * @lc app=leetcode.cn id=423 lang=cpp
 *
 * [423] 从英文中重建数字
 */

class Solution {
    void out(vector<array<double, 11>> &x) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 11; j++) {
                cout << x[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }

  public:
    string originalDigits(string s) {
        const string words[] = {"zero", "one", "two",   "three", "four",
                                "five", "six", "seven", "eight", "nine"};
        vector<array<double, 11>> V(26);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 11; j++) {
                V[i][j] = 0;
            }
        }
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < (int)words[j].size(); k++) {
                V[words[j][k] - 'a'][j] += 1;
            }
        }
        for (int i = 0; i < (int)s.size(); i++) {
            V[s[i] - 'a'][10] += 1;
        }
        int fst = 0;
        for (int i = 0; i < 26; i++) {
            {
                bool done = 0;
                while (!done && fst < 10) {
                    for (int j = i; j < 26; j++) {
                        if (abs(V[j][fst]) > 1e-4) {
                            swap(V[i], V[j]);
                            done = 1;
                            break;
                        }
                    }
                    if (!done) {
                        fst++;
                    }
                }
            }
            if (fst < 10) {
                for (int j = 0; j < 26; j++) {
                    if (j == i)
                        continue;
                    double K = V[j][fst] / V[i][fst];
                    for (int k = 0; k < 11; k++) {
                        V[j][k] -= V[i][k] * K;
                    }
                }
            }
        }
        vector<int> res(10, 0);
        for (int i = 0; i < 26; i++) {
            int has = 0;
            for (int j = 0; j < 10; j++) {
                if (abs(V[i][j]) > 1e-3) {
                    res[j] = round(V[i][10] / V[i][j]);
                }
            }
        }
        stringstream ss;
        for (int i = 0; i <= 9; i++) {
            for (int j = 0; j < res[i]; j++) {
                ss << i;
            }
        }
        return ss.str();
    }
};

#ifdef RINNE
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(2);
    cout << fixed;
    vector<int> data{};
    Solution s;
    auto res = s.originalDigits("owoztneoer");
    debug(res);
    return 0;
}
#endif
// @lc code=end
