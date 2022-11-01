// id:373286243
// runtime:4 ms
// memory:10.9 MB
// title:打印从1到最大的n位数 LCOF
// translatedTitle:打印从1到最大的n位数
// questionId:100296
// time:2022-10-15 20:06:20

class Solution {
public:
    vector<int> printNumbers(int n) {
        int P[100];
        P[0]=1;
        vector<int>ret;
        for(int i=1;i<=9;i++)P[i]=P[i-1]*10;
        for(int i=1;i<P[n];i++){
            ret.push_back(i);
        }
        return ret;
    }
};