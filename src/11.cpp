// id:325868217
// runtime:172 ms
// memory:62.4 MB
// title:Container With Most Water
// translatedTitle:盛最多水的容器
// questionId:11
// time:2022-06-16 14:31:17

class Solution {
public:
    int maxArea(vector<int>& V) {
        const int n=V.size();
        vector<int>pre=V;
        vector<int>suf=V;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i],suf[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int l=i,r=i;
            {
                int L=0,R=i,ans=i;
                while(L<=R){
                    int mid=(L+R)/2;
                    if(pre[mid]<V[i]){
                        L=mid+1;
                    }else{
                        ans=mid;
                        R=mid-1;
                    }
                }
                l=ans;
            }
            {
                int L=i,R=n-1,ans=i;
                while(L<=R){
                    int mid=(L+R)/2;
                    if(suf[mid]<V[i]){
                        R=mid-1;
                    }else{
                        ans=mid;
                        L=mid+1;
                    }
                }
                r=ans;
            }
            ans=max(ans,(r-l)*V[i]);
        }
        return ans;
    }
};