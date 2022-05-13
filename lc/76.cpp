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
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

class Solution {
  public:
    uint8_t fix(char s) {
        if (s >= 'a' && s <= 'z') {
            s -= 'a';
        } else {
            s = s - 'A' + 26;
        }
        return s;
    }
    bool test(vector<int> &need, vector<int> &cnt) {
        for (int i = 0; i < 52; i++) {
            if (need[i] > cnt[i]) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> need(52, 0), cnt(52, 0);
        deque<char> q;
        string ret;
        for (int i = 0; i < (int)t.size(); i++) {
            need[fix(t[i])]++;
        }
        for (int i = 0; i < (int)s.size(); i++) {
            q.push_back(s[i]);
            cnt[fix(s[i])]++;
            while (!q.empty()) {
                int front = fix(q.front());
                cnt[front]--;
                if (test(need, cnt)) {
                    q.pop_front();
                } else {
                    cnt[front]++;
                    break;
                }
            }
            if (ret.empty() || q.size() < ret.size()) {
                if (test(need, cnt)) {
                    ret.clear();
                    for (auto i : q) {
                        ret.push_back(i);
                    }
                }
            }
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
    const char *s1 =
        "wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckd"
        "wccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvnea"
        "opadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwf"
        "sssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvde"
        "rjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftn"
        "vegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcyta"
        "bdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenketty"
        "lcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuy"
        "pfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon";
    const char *s2 = "ozgzyywxvtublcl";
    auto res = s.minWindow(s1, s2);
    debug(res);
    return 0;
}
#endif
// @lc code=end
