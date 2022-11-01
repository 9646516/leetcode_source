// id:374827700
// runtime:92 ms
// memory:34.6 MB
// title:Smallest Difference LCCI
// translatedTitle:最小差
// questionId:100262
// time:2022-10-20 15:14:35

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int pos=0;
        long long ans=1e18;
        for(int i=0;i<a.size();i++){
            while(pos<b.size()&&b[pos]<a[i])pos++;
            for(int j=-1;j<=0;j++){
                int idx=pos+j;
                if(idx<b.size())ans=min(ans,abs(1LL*a[i]-b[idx]));
            }
        }
        return ans;
    }
};