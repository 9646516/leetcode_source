// id:378208095
// runtime:352 ms
// memory:198.2 MB
// title:Finding MK Average
// translatedTitle:求出 MK 平均值
// questionId:1953
// time:2022-10-31 23:31:31

using ll = long long;
using T = ll;
constexpr int N = 1 << (__lg(100000) + 1);
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
    void set(const vector<T> &x) {
        assert((int)x.size() <= SZ);
        for (int i = 0; i < (int)x.size(); i++) {
            seg[i + SZ] = x[i];
        }
        build();
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
class MKAverage {
  public:
    deque<int> q;
    int m, k;
    Seg<N> seg, seg2;
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
    }

    void addElement(int num) {
        if (q.size() == m) {
            int remove = q.front();
            q.pop_front();
            seg.upd(remove, -1);
            seg2.upd(remove, -remove);
        }

        q.push_back(num);
        seg.upd(num, 1);
        seg2.upd(num, num);
    }

    int calculateMKAverage() {
        if (q.size() < m)
            return -1;
        ll xs = seg2.query(0, N - 1);
        {
            int L = 1, R = 100000, ans;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (seg.query(1, mid) >= k) {
                    ans = mid;
                    R = mid - 1;
                } else {
                    L = mid + 1;
                }
            }
            int has = seg.query(0, ans);
            int over = has - k;
            xs = xs - seg2.query(0, ans);
            xs = xs + 1LL * over * ans;
        }
        {
            int L = 1, R = 100000, ans;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (seg.query(mid, N - 1) >= k) {
                    ans = mid;
                    L = mid + 1;
                } else {
                    R = mid - 1;
                }
            }
            int has = seg.query(ans, N - 1);
            int over = has - k;
            xs = xs - seg2.query(ans, N - 1);
            xs = xs + 1LL * over * ans;
        }
        return xs / (m - k - k);
    }
};