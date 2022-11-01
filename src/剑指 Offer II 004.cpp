// id:373666359
// runtime:16 ms
// memory:9.2 MB
// title:只出现一次的数字 
// translatedTitle:只出现一次的数字 
// questionId:1000233
// time:2022-10-16 23:31:04

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int B[32];
        memset(B,0,sizeof(B));
        for(int i:nums){
            for(int j=31;j>=0;j--){
                if((i>>j)&1){
                    B[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<=31;i++){
            if(B[i]%3)ans|=1<<i;
        }
        return ans;
    }
};