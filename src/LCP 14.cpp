// id:376637726
// runtime:1436 ms
// memory:106.8 MB
// title:切分数组
// translatedTitle:切分数组
// questionId:1000059
// time:2022-10-26 15:42:55

using ll = long long;
int dp[100000 + 5];
const int NUM = 10;
inline ll mul_mod(ll a, ll b, ll n) { return (__int128_t)a * b % n; }
ll pow_mod(ll a, ll b, ll n) {
    a = a % n;
    ll s = 1;
    while (b) {
        if (b & 1)
            s = mul_mod(s, a, n);
        a = mul_mod(a, a, n);
        b = b >> 1;
    }
    return s;
}
bool check(ll a, ll n, ll r, ll s) {
    ll ans, p, i;
    ans = pow_mod(a, r, n);
    p = ans;
    for (i = 1; i <= s; i++) {
        ans = mul_mod(ans, ans, n);
        if (ans == 1 && p != 1 && p != n - 1)
            return true;
        p = ans;
    }
    if (ans != 1)
        return true;
    return false;
}
bool Miller_Rabin(ll n) {
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (!(n & 1))
        return false;
    ll i, r, s, a;
    r = n - 1;
    s = 0;
    while (!(r & 1)) {
        r = r >> 1;
        s++;
    }
    for (i = 0; i < NUM; i++) {
        a = rand() % (n - 1) + 1;
        if (check(a, n, r, s))
            return false;
    }
    return true;
}
ll Pollard_rho(ll n, ll c) {
    ll i = 1, k = 2, x, y, d, p;
    x = rand() % n;
    y = x;
    while (true) {
        i++;
        x = (mul_mod(x, x, n) + c) % n;
        if (y == x)
            return n;
        if (y > x)
            p = y - x;
        else
            p = x - y;
        d = __gcd(p, n);
        if (d != 1 && d != n)
            return d;
        if (i == k) {
            y = x;
            k += k;
        }
    }
}
void find(vector<int> &f, ll n) {
    if (Miller_Rabin(n)) {
        f.push_back(n);
        return;
    }
    ll p = n;
    while (p >= n)
        p = Pollard_rho(p, rand() % (n - 1) + 1);
    find(f, p);
    find(f, n / p);
}
void gao(vector<int> &f, ll n) { 
    f.clear();
    if (n == 1) {
        f.push_back(1);
    } else {
        find(f, n);
    }
}
class Solution {
  public:
    int splitArray(vector<int> &nums) {
        const int N = nums.size();
        vector<int> V[100000 + 55];
        for (int i = 0; i < N; i++) {
            gao(V[i + 1], nums[i]);
        }
        unordered_map<int, int> prefix;
        dp[0] = 0;
        for (int i = 1; i <= N; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j : V[i]) {
                if (!prefix.count(j))
                    prefix[j] = dp[i - 1];
                else {
                    prefix[j] = min(prefix[j], dp[i - 1]);
                    dp[i] = min(dp[i], prefix[j] + 1);
                }
            }
        }
        return dp[N];
    }
};