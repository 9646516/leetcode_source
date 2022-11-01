// id:369325733
// runtime:380 ms
// memory:7.6 MB
// title:Maximum Deletions on a String
// translatedTitle:对字母串可执行的最大删除数
// questionId:2510
// time:2022-10-02 20:05:10

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct RollingHash {
    static const ll mo0 = 1e9 + 21, mo1 = 1e9 + 7;
    static const ll add0 = 1000010007, add1 = 1003333331;
    static const ll mul0 = 233, mul1 = 19260817;
    static vector<ll> POW[2];
    vector<ll> H[2];
    void init(const string &s) {
        if (POW[0].empty()) {
            POW[0].push_back(1);
            POW[1].push_back(1);
        }
        while (POW[0].size() < s.size() + 10) {
            POW[0].push_back(POW[0].back() * mul0 % mo0);
            POW[1].push_back(POW[1].back() * mul1 % mo1);
        }
        H[0].push_back(0);
        H[1].push_back(0);
        for (int i = 0; i < s.size(); i++) {
            H[0].push_back((H[0].back() * mul0 + add0 + s[i]) % mo0);
            H[1].push_back((H[1].back() * mul1 + add1 + s[i]) % mo1);
        }
    }
    ll hash(int l, int r) { // s[l..r]
        if (l > r)
            return 0;
        else {
            ll F = (H[0][r + 1] + (mo0 - H[0][l] * POW[0][r + 1 - l] % mo0)) % mo0;
            ll S = (H[1][r + 1] + (mo1 - H[1][l] * POW[1][r + 1 - l] % mo1)) % mo1;
            return (F << 32) | S;
        }
    }
};
constexpr int MAXN = 4e3 + 5;
vector<ll> RollingHash::POW[2];
class Solution {
    int res[MAXN];
    RollingHash H;

  public:
    int deleteString(string s) {
        memset(res, -1, sizeof(res));
        H.init(s);
        int ans = dp(0, s.size());
        return ans;
    }

    int dp(int l, int r) {
        if (res[l] == -1) {
            int ret = 1;
            for (int i = l + 1; i < r; ++i) {
                int part = i - l;
                if (i + part > r)
                    break;
                if (H.hash(l, i - 1) == H.hash(i, i + part - 1)) {
                    ret = max(ret, 1 + dp(i, r));
                }
            }
            res[l] = ret;
        }
        return res[l];
    }
};