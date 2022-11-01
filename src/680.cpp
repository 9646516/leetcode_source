// id:373923746
// runtime:84 ms
// memory:20.3 MB
// title:Valid Palindrome II
// translatedTitle:验证回文串 II
// questionId:680
// time:2022-10-17 20:03:44

uint64_t H1[100005];
uint64_t H2[100005];
uint64_t POW[100005];
class Solution {
  public:
    bool validPalindrome(string s) {
        constexpr uint64_t SEED = 233;
        const int N = s.size();
        POW[0] = 1;
        for (int i = 1; i <= N; i++)
            POW[i] = POW[i - 1] * SEED;
        H1[0] = s[0];
        for (int i = 1; i < N; i++) {
            H1[i] = H1[i - 1] * SEED + s[i];
        }
        H2[N - 1] = s[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            H2[i] = H2[i + 1] * SEED + s[i];
        }
        if (H1[N - 1] == H2[0])
            return 1;
        for (int i = 0; i < N; i++) {
            uint64_t lval = 0, rval = 0;
            if (i) {
                lval += H1[i - 1] * POW[(N - 1) - (i + 1) + 1];
                rval += H2[0] - H2[i] * POW[(i - 1) - 0 + 1];
            }
            if (i != N - 1) {
                lval += H1[N - 1] - H1[i] * POW[(N - 1) - (i + 1) + 1];
                rval += H2[i + 1] * POW[(i - 1) - 0 + 1];
            }
            if (lval == rval)
                return 1;
        }
        return 0;
    }
};