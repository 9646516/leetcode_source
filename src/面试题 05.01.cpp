// id:374565702
// runtime:4 ms
// memory:5.8 MB
// title:Insert Into Bits LCCI
// translatedTitle:插入
// questionId:100180
// time:2022-10-19 18:04:56

class Solution {
public:
    int insertBits(int N, int M, int l, int r) {
        for(int i=l;i<=r;i++){
            if((N>>i)&1)N^=1<<i;
        }
        N|=M<<l;
        return N;
    }
};