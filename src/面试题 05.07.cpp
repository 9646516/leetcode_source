// id:374578735
// runtime:0 ms
// memory:5.9 MB
// title:Exchange LCCI
// translatedTitle:配对交换
// questionId:100182
// time:2022-10-19 19:03:33

class Solution {
public:
    int exchangeBits(int num) {
        int ret=0;
        for(int i=0;i<30;i+=2){
            int A=((num>>i)&1);
            int B=((num>>(i+1))&1);
            ret|=(A<<(i+1))|(B<<i);
        }
        return ret;
    }
};