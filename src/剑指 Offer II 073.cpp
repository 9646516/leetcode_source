// id:374152074
// runtime:24 ms
// memory:18.2 MB
// title:狒狒吃香蕉
// translatedTitle:狒狒吃香蕉
// questionId:1000337
// time:2022-10-18 14:42:40

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L=1,R=1e9,ans=1e9;
        while(L<=R){
            int mid=(L+R)/2;
            int now=0;
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