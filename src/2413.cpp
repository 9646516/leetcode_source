// id:364218331
// runtime:0 ms
// memory:5.8 MB
// title:Smallest Even Multiple
// translatedTitle:最小偶倍数
// questionId:2491
// time:2022-09-18 10:30:45

class Solution {
public:
    int smallestEvenMultiple(int n) {
        return 2*n/__gcd(2,n);
    }
};