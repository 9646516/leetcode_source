// id:374578205
// runtime:0 ms
// memory:5.7 MB
// title:Convert Integer LCCI
// translatedTitle:整数转换
// questionId:100181
// time:2022-10-19 19:01:22

class Solution {
public:
    int convertInteger(int A, int B) {
        return __builtin_popcount(A^B);
    }
};