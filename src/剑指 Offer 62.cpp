// id:373660679
// runtime:12 ms
// memory:8.7 MB
// title:圆圈中最后剩下的数字 LCOF
// translatedTitle:圆圈中最后剩下的数字
// questionId:100343
// time:2022-10-16 23:09:34

class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)return 0;
        return (m + lastRemaining(n - 1, m)) % n;
    }
};