// id:373797947
// runtime:76 ms
// memory:59.6 MB
// title:乘积小于 K 的子数组
// translatedTitle:乘积小于 K 的子数组
// questionId:1000244
// time:2022-10-17 14:12:06

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& V, int k) {
        int ans=0;
        long long xs=1;
        int pos=0;
        for(int i=0;i<V.size();i++){
            xs*=V[i];
            while(pos<=i&&xs>=k){
                xs/=V[pos];
                pos++;
            }
            ans+=i-pos+1;
        }
        return ans;
    }
};