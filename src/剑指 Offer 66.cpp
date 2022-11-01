// id:373656617
// runtime:16 ms
// memory:25.4 MB
// title:构建乘积数组 LCOF
// translatedTitle:构建乘积数组
// questionId:100338
// time:2022-10-16 22:54:34

class Solution {
  public:
    vector<int> constructArr(vector<int> &a) {
        const int N = a.size();
        vector<int> P = a;
        vector<int> S = a;
        for (int i = 1; i < N; i++)
            P[i] *= P[i - 1];
        for (int i = N - 2; i >= 0; i--)
            S[i] *= S[i + 1];
        vector<int> ret;
        for (int i = 0; i < N; i++) {
            int now = 1;
            if (i)
                now *= P[i - 1];
            if (i != N - 1)
                now *= S[i + 1];
            ret.push_back(now);
        }
        return ret;
    }
};