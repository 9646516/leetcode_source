// id:374896228
// runtime:12 ms
// memory:17.2 MB
// title:Missing Number LCCI
// translatedTitle:消失的数字
// questionId:1000032
// time:2022-10-20 18:12:00

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int N=nums.size();
        vector<int>vis(N+1);
        for(int i:nums)vis[i]=1;
        for(int i=0;i<=N;i++){
            if(!vis[i])return i;
        }
        return -1;
    }
};