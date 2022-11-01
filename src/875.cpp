// id:374152506
// runtime:32 ms
// memory:18.3 MB
// title:Koko Eating Bananas
// translatedTitle:爱吃香蕉的珂珂
// questionId:907
// time:2022-10-18 14:43:51

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L=1,R=1e9,ans=1e9;
        while(L<=R){
            int mid=(L+R)/2;
            long long now=0;
            for(int i:piles){
                now+=i/mid;
                if(i%mid)now++;
            }
            if(now<=h){
                ans=mid;
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        return ans;
    }
};