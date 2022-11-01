// id:373803258
// runtime:24 ms
// memory:31.2 MB
// title:左右两边子数组的和相等
// translatedTitle:左右两边子数组的和相等
// questionId:1000248
// time:2022-10-17 14:27:08

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        const int N=nums.size();
        vector<int>L=nums,R=nums;
        for(int i=1;i<N;i++){
            L[i]+=L[i-1];
        }
        for(int i=N-2;i>=0;i--){
            R[i]+=R[i+1];
        }
        int ans=-1;
        for(int i=0;i<N;i++){
            int lval=0,rval=0;
            if(i){
                lval=L[i-1];
            }
            if(i!=N-1){
                rval=R[i+1];
            }
            if(lval==rval){
                ans=i;
                break;
            }
        }
        return ans;
    }
};