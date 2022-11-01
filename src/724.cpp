// id:373923469
// runtime:20 ms
// memory:31.5 MB
// title:Find Pivot Index
// translatedTitle:寻找数组的中心下标
// questionId:724
// time:2022-10-17 20:03:03

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