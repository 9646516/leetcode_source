// id:84832239
// runtime:208 ms
// memory:17.7 MB
// title:Minimum Possible Integer After at Most K Adjacent Swaps On Digits
// translatedTitle:最多 K 次交换相邻数位后得到的最小整数
// questionId:1629
// time:2020-07-05 12:28:54

using T = int;
constexpr int N = 1 << (__lg(30000)+1);
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define F0Rd(i, a) for (int i = (a)-1; i >= 0; i--)
template <int SZ> struct Seg {
    T seg[2 * SZ];
    static const T ID = 0;
    void init() { F0R(i, 2 * SZ) seg[i] = ID; }
    Seg() { init(); }
    void build() { F0Rd(i, SZ) seg[i] = comb(seg[2 * i], seg[2 * i + 1]); }
    T comb(const T &a, const T &b) const { return a + b; }
    void upd(int p, T value) {
        for (seg[p += SZ] += value; p > 1; p >>= 1)
            seg[p >> 1] = comb(seg[(p | 1) ^ 1], seg[p | 1]);
    }
    T query(int l, int r) {
        if (l > r)
            return 0;
        T res1 = ID, res2 = ID;
        r++;
        for (l += SZ, r += SZ; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                res1 = comb(res1, seg[l++]);
            if (r & 1)
                res2 = comb(seg[--r], res2);
        }
        return comb(res1, res2);
    }
};
class Solution {
  public:
    string minInteger(string num, int k) {
        static Seg<N> seg;
        seg.init();
        set<int> st[11];
        for (int i = 0; i < (int)num.size(); i++) {
            st[num[i] - '0'].insert(i);
        }
        string sb = "";
        const int N = num.size();
        while (k) {
            bool ok = 0;
            for (int fst = 0; fst <= 9; fst++) {
                if (!st[fst].empty()) {
                    int idx = *st[fst].begin();
                    int dis = idx - seg.query(0, idx - 1);
                    if (dis <= k) {
                        st[fst].erase(idx);
                        sb.push_back('0' + fst);
                        k -= dis;
                        seg.upd(idx, 1);
                        ok = 1;
                        break;
                    }
                }
            }
            if (!ok)
                break;
        }
        while (sb.size() < N) {
            char s;
            int idx = 1e9;
            for (int fst = 0; fst <= 9; fst++) {
                if (!st[fst].empty() && *st[fst].begin() < idx) {
                    idx = *st[fst].begin();
                    s = fst + '0';
                }
            }
            st[s - '0'].erase(idx);
            sb.push_back(s);
        }
        return sb;
    }
};