// id:376115789
// runtime:164 ms
// memory:37.1 MB
// title:Minimum Cost to Make Array Equal
// translatedTitle:使数组相等的最小开销
// questionId:2538
// time:2022-10-24 21:10:36

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const int N=nums.size();
        auto calc=[&](int val){
            long long ret=0;
            for(int i=0;i<N;i++){
                ret+=1LL*abs(nums[i]-val)*cost[i];
            }
            return ret;
        };
        int L=0,R=1e6;
        while(L+10<=R){
            int mid=(L+R)/2;
            int rmid=(mid+R)/2;
            if(calc(mid)>calc(rmid)){
                L=mid;
            }else{
                R=rmid;
            }
        }
        long long ans=1e18;
        for(int i=L;i<=R;i++)ans=min(ans,calc(i));
        return ans;
    }
};