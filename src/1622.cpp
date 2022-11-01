// id:378162529
// runtime:420 ms
// memory:179.8 MB
// title:Fancy Sequence
// translatedTitle:奇妙序列
// questionId:1728
// time:2022-10-31 21:09:43

const int MOD = 1e9 + 7;

class Fancy {
  public:
    using ll = long long;
    ll add, mul;
    vector<int> V;
    Fancy() {
        add = 0;
        mul = 1;
    }

    ll xpow(ll a, ll b) {
        ll ret = 1;
        a %= MOD;
        // assert(b >= 0);
        while (b) {
            if (b & 1)
                ret = ret * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return ret;
    }
    void append(int val) {
        val = (val - add) * xpow(mul, MOD - 2) % MOD;
        if (val < MOD)
            val += MOD;
        V.push_back(val);
    }

    void addAll(int inc) { add = (add + inc) % MOD; }

    void multAll(int m) {
        add = (add * m) % MOD;
        mul = mul * m % MOD;
    }

    int getIndex(int idx) {
        if (idx < V.size())
            return (V[idx] * mul + add) % MOD;
        else
            return -1;
    }
};