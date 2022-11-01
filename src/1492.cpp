// id:82507155
// runtime:4 ms
// memory:6.2 MB
// title:The kth Factor of n
// translatedTitle:n 的第 k 个因子
// questionId:1585
// time:2020-06-27 22:33:08

using ll = long long;
class Solution {
  public:
    int kthFactor(int n, int k) {
        vector<int> s;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                s.push_back(i);
                if (i * i != n)
                    s.push_back(n / i);
            }
        }
        sort(s.begin(), s.end());
        if (s.size() < k)
            return -1;
        else
            return s[k - 1];
    }
};