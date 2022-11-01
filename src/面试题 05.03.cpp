// id:374567455
// runtime:4 ms
// memory:5.7 MB
// title:Reverse Bits LCCI
// translatedTitle:翻转数位
// questionId:100230
// time:2022-10-19 18:12:26

class Solution {
public:
    int solve(uint32_t num){
        int prev=0,len=0;
        int ans=0;
        for(int i=0;i<=31;i++){
            int B=((num>>i)&1);
            if(B==prev)len++;
            else{
                if(prev)ans=max(ans,len);
                prev=B;
                len=1;
            }
        }
        if(prev)ans=max(ans,len);
        return ans;
    }
    int reverseBits(int num) {
        int ans=solve(num);
        for(int i=0;i<=31;i++){
            if(!((num>>i)&1))ans=max(ans,solve(num|1<<i));
        }
        return ans;
    }
};