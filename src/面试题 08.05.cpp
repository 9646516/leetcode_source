// id:374591265
// runtime:0 ms
// memory:5.9 MB
// title:Recursive Mulitply LCCI
// translatedTitle:递归乘法
// questionId:100199
// time:2022-10-19 19:46:28

class Solution {
public:
    int multiply(int A, int B) {
        int ans=0;
        for(int i=0;i<=31;i++){
            if((B>>i)&1){
                ans+=A<<i;
            }
        }
        return ans;
    }
};